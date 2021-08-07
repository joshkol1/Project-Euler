#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
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

ll sum_fifths(ll n) {
    ll ans = 0;
    while(n != 0) {
        auto unit = n%10;
        ans += unit*unit*unit*unit*unit;
        n /= 10;
    }
    return ans;
}

int main() {
    ll ans = 0;
    // 7-digit & beyond impossible by induction
    for(ll n = 10; n < 1000000; ++n) {
        if(n == sum_fifths(n))
            ans += n;
    }
    cout << ans << endl;
    return 0;
}