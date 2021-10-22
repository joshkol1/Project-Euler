#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<array>
#include<assert.h>
#include<cmath>
typedef long long ll;
typedef long double ld;
#define pb push_back

const ll R = 1e9;

ll inside_circle() {
    ll ans = 0;
    ll radius = std::round(R*std::sqrt(2)/8);
    for(ll x = -radius; x <= radius; ++x) {
        ll max_y = std::sqrt(R*R/32-x*x);
        if(max_y*max_y+x*x >= R*R/32)
            --max_y;
        assert(max_y*max_y+x*x < R*R/32);
        ans += 2*max_y+1;
    }
    return ans;
}

int main() {
    ll answer = (R+2)*(R+2)/4+R*R/4-(R+1);
    answer += R*R/8+(R/4+1)*(R/2+1)-(3*R/4+1);
    answer *= 2;
    answer += inside_circle();
    answer -= (R/4-1);
    std::cout << answer << std::endl;
    return 0;
}