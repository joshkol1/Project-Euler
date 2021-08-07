#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<array>
#include<assert.h>
#include<string>
#include<math.h>
#include<climits>
#include<utility>
#include<functional>
#include<numeric>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back

int gcd(int a, int b) {
    return (a == 0) ? b : gcd(b%a, a);
}

int main() {
    ld best_diff = 1;
    ld goal = 3.0L/7;
    int ans = 0;
    // Closest to 3/7 from left
    for(int d = 3; d <= 1000000; ++d) {
        auto n = (3*d)/7;
        if((3*d)%7 == 0)
            --n;
        if(gcd(n, d) != 1)
            continue;
        if(goal-(n+0.0L)/d < best_diff) {
            ans = n;
            best_diff = goal-(n+0.0L)/d;
        }
    }
    cout << ans << endl;
    return 0;
}