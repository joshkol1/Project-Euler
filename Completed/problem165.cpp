#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back

const ll MOD = 50515093;
const ld epsilon = 1e-9;
const int N_SEGMENTS = 5000;

struct Point {
    ld x, y;
};

// For evil floating point comparisons
bool operator<(const Point& p1, const Point& p2) {
    if(abs(p1.x-p2.x) < epsilon) {
        if(abs(p1.y-p2.y) < epsilon)
            return false;
        return p1.y < p2.y;
    }
    return p1.x < p2.x;
}

struct Line {
    ld x1, y1, x2, y2;
};

// Given a line, return {m, b} where point on the line satisfy y = mx+b
pair<ld, ld> standard_form(Line& l) {
    assert(abs(l.x2-l.x1) > epsilon);
    ld m = (l.y2-l.y1)/(l.x2-l.x1);
    ld b = l.y1-m*l.x1;
    return {m, b};
}

Point intersection(Line& l1, Line& l2) {
    if(abs(l1.x1-l1.x2) < epsilon) {
        if(abs(l2.x1-l2.x2) < epsilon)
            return {-1, -1}; // Two vertical lines, no true intersection
        else { // l1 vertical, l2 not
            auto s_form = standard_form(l2);
            auto m = s_form.first; auto b = s_form.second;
            auto x = l1.x1;
            return {x, m*x + b};
        }
    } else {
        if(abs(l2.x1-l2.x2) < epsilon) { // l1 not vertical, l2 vertical
            auto s_form = standard_form(l1);
            auto m = s_form.first; auto b = s_form.second;
            auto x = l2.x1;
            return {x, m*x + b};
        } else {
            auto s_form1 = standard_form(l1);
            auto s_form2 = standard_form(l2);
            auto m1 = s_form1.first; auto b1 = s_form1.second;
            auto m2 = s_form2.first; auto b2 = s_form2.second;
            if(abs(m1-m2) < epsilon) // parallel lines, no true intersection 
                return {-1, -1};
            else {
                auto inter_x = (b2-b1)/(m1-m2);
                auto inter_y = m1*inter_x + b1;
                return {inter_x, inter_y};
            }
        }
    }
}

bool inside(Line& l, Point& p) {
    if(abs(l.x1-l.x2) < epsilon) { // Vertical line case
        // end points are not true intersections
        if(abs(p.y-l.y1) < epsilon || abs(p.y-l.y2) < epsilon)
            return false;
        return (l.y1 < p.y && p.y < l.y2) || (l.y2 < p.y && p.y < l.y1);
    }
    if(abs(l.y1-l.y2) < epsilon) { // horizontal line
        // end points
        if(abs(p.x-l.x1) < epsilon || abs(p.x-l.x2) < epsilon)
            return false;
        return (l.x1 < p.x && p.x < l.x2) || (l.x2 < p.x && p.x < l.x1);
    }
    // Line with non-zero slope
    auto x = p.x; auto y = p.y;
    // end point
    if(abs(x-l.x1) < epsilon || abs(x-l.x2) < epsilon || abs(y-l.y1) < epsilon || abs(y-l.y2) < epsilon)
        return false;
    bool x_good = (l.x1 < x && x < l.x2) || (l.x2 < x && x < l.x1);
    bool y_good = (l.y1 < y && y < l.y2) || (l.y2 < y && y < l.y1);
    return x_good && y_good;
}

vector<Line> lines;
set<Point> points;

void generate_lines() {
    ll seed = 290797;
    for(int i = 0; i < N_SEGMENTS; ++i) {
        seed = (seed*seed) % MOD;
        ld t1 = seed % 500;
        seed = (seed*seed) % MOD;
        ld t2 = seed % 500;
        seed = (seed*seed) % MOD;
        ld t3 = seed % 500;
        seed = (seed*seed) % MOD;
        ld t4 = seed % 500;
        lines.pb(Line{t1, t2, t3, t4});
    }
}

int main() {
    generate_lines();
    for(size_t i = 0; i < lines.size(); ++i) {
        for(size_t j = 0; j < lines.size(); ++j) {
            auto point = intersection(lines[i], lines[j]);
            /*
                One of two things leads to this:
                    1. Lines intersect outside region where segments are defined
                    2. Lines have no or infinitely many intersections (parallel)
            */
            if(point.x < 0 || point.y < 0)
                continue;
            if(inside(lines[i], point) && inside(lines[j], point)) {
                points.insert(point);
            }
        }
    }
    cout << points.size() << "\n";
    return 0;
}