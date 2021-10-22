#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<array>
#include<assert.h>
#include<cmath>
#include<math.h>
typedef long long ll;
typedef long double ld;
#define pb push_back

const int R = 105;
const double epsilon = 1e-9;

std::vector<std::pair<int, int>> top_points;
std::vector<std::pair<int, int>> bottom_points;
std::vector<double> bottom_angles;

/* Fetch top half point locations & angles of bottom half points */
void get_points() {
    for(int x = -R+1; x <= R-1; ++x) {
        int max_y = std::sqrt(R*R-x*x);
        if(x*x+max_y*max_y >= R*R)
            --max_y;
        for(int y = 1; y <= max_y; ++y) {
            top_points.push_back({x, y});
            bottom_points.push_back({x, -y});
        }
        for(int y = -1; y >= -max_y; --y)
            bottom_angles.push_back(M_PI-std::acos(x/std::sqrt(x*x+y*y)));
    }
    std::sort(bottom_angles.begin(), bottom_angles.end());
}

/* Given two top-half points, how many bottom half points create triangle containing origin? */
int n_good_points(const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
    if(p1.second == 0 && p2.second == 0) {
        return 0;
    }
    double angle1 = std::acos(p1.first/std::sqrt(p1.first*p1.first+p1.second*p1.second));
    double angle2 = std::acos(p2.first/std::sqrt(p2.first*p2.first+p2.second*p2.second));
    double lb = std::min(angle1, angle2);
    double ub = std::max(angle1, angle2);
    /* Binary search for first angle strictly larger than lb */
    int low = 0; int high = bottom_angles.size();
    while(low != high) {
        int mid = (low+high)/2;
        if(lb-bottom_angles[mid] >= -epsilon) {
            low = mid+1;
        }
        else {
            high = mid;
        }
    }
    auto first_index = low;
    /* Binary search for first angle at least ub, then one before is strictly smaller */
    low = 0; high = bottom_angles.size();
    while(low != high) {
        int mid = (low+high)/2;
        if(ub-bottom_angles[mid] > epsilon) {
            low = mid+1;
        }
        else {
            high = mid;
        }
    }
    auto second_index = low-1;
    return (first_index <= second_index) ? second_index-first_index+1 : 0;
}

int main() {
    get_points();
    ll answer = 0;
    for(size_t i = 0; i < top_points.size(); ++i) {
        for(size_t j = i+1; j < top_points.size(); ++j) {
            answer += n_good_points(top_points[i], top_points[j]);
        }
    }
    answer *= 2;
    for(int x = -R+1; x <= R-1; ++x) {
        if(x == 0)
            continue;
        /* Iterate over all top points & try to find # bottom points */
        for(auto& top_point : top_points) {
            answer += n_good_points(top_point, {x, 0});
        }
    }
    std::cout << answer << std::endl;
    return 0;
}