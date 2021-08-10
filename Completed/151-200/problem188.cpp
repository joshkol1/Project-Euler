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

ll naive_order(ll n, ll m) {
    ll ans = 1;
    ll n_pow = n%m;
    while(n_pow != 1) {
        n_pow = (n_pow*n)%m;
        ++ans;
    }
    return ans;
}

ll fast_exp(ll b, ll e, ll m) {
    b %= m;
    ll ret = 1;
    while(e > 0) {
        if(e&1) ret = ret*b%m;
        b = b*b%m;
        e >>= 1;
    }
    return ret;
}

int main() {
    ll MOD = 1E8;
    ll hyoer_exp = 1855;
    vector<ll> orders;
    orders.pb(naive_order(1777, MOD));
    for(int i = 0; ; ++i) {
        orders.pb(naive_order(1777, orders[i]));
        if(orders[i+1] == 1)
            break;
    }
    for(ll o : orders)
        cout << o << endl;
    return 0;
}