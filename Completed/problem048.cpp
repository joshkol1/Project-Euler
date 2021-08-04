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

int main() {
    ll MOD = 1E10;
    ll ans = 0;
    for(ll n = 1; n <= 1000; ++n) {
        ll m = 1;
        for(ll j = 1; j <= n; ++j)
            m = (m*n)%MOD;
        ans = (ans+m)%MOD;
    }
    cout << ans << endl;
    return 0;
}