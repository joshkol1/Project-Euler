#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

ll ans;

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

ll totient(ll n) {
    for(ll p = 2; p <= n; p++) {
        
    }
}

int main() {
    return 0;
}