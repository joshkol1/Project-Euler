#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define f first
#define s second

const ld eps = 1e-11;

/*
    Sum of pairs p1 and p2
*/
pair<ld, ld> v_sum(pair<ld, ld> p1, pair<ld, ld> p2) {
    return pair<ld, ld>(p1.f+p2.f, p1.s+p2.s);
}

/*
    Difference p1-p2 of pairs p1 and p2
*/
pair<ld, ld> v_diff(pair<ld, ld> p1, pair<ld, ld> p2) {
    return pair<ld, ld>(p1.f-p2.f, p1.s-p2.s);
}

/*
    Dot product of two vectors v1 and v2
*/
ld dot(pair<ld, ld> v1, pair<ld, ld> v2) {
    return v1.f*v2.f+v1.s*v2.s;
}

/*
    Return the solutions to the equation ax^2+bx+c=0 as a pair.
    First coordinate is the +sqrt solution, second is -sqrt.
*/
pair<ld, ld> quad_formula(ld a, ld b, ld c) {
    ld radical = sqrt(b*b-4*a*c);
    return pair<ld, ld>((-b+radical)/(2*a), (-b-radical)/(2*a));
}

int main() {
    pair<ld, ld> old_p = {0.0, 10.1};
    pair<ld, ld> new_p = {1.4, -9.6};
    int bounces = 0;
    while(new_p.f < -0.01 || new_p.f > 0.01 || new_p.s < 0) {
        // Displacement vector from hitting point to origin
        pair<ld, ld> disp = v_diff(old_p, new_p);
        // Slope of orthogonal to tangent line at hitting point
        ld m = (new_p.s)/(4*new_p.f);
        // A vector in m's direction
        pair<ld, ld> orth = {1, m};
        ld scale = dot(disp, orth)/dot(orth, orth);
        // Projection of displacement vector onto tangent's orthogonal
        pair<ld, ld> disp_proj = {scale, m*scale};
        // Vector in direction of reflection vector
        pair<ld, ld> reflect_v = v_diff(disp_proj, v_diff(disp, disp_proj));
        // Now, calculate the new point where light hits wall, denoted (new_x, new_y)
        ld new_m = (reflect_v.s)/(reflect_v.f);
        ld new_b = new_p.s-new_m*new_p.f;
        ld a = 4+new_m*new_m;
        ld b = 2*new_m*new_b;
        ld c = new_b*new_b-100;
        pair<ld, ld> x_inters = quad_formula(a, b, c);
        ld new_x;
        if(abs(new_p.f-x_inters.f) < eps) new_x = x_inters.s;
        else new_x = x_inters.f;
        ld new_y = new_m*new_x+new_b;
        // Update "previous" and "current" intersection point. Increment bounces
        old_p = new_p;
        new_p = {new_x, new_y};
        bounces++;
    }
    cout << bounces << "\n";
    return 0;
}