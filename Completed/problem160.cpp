#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const ll MAX = 1000000000000LL;
const ll MOD = 1E5;
ll mod_table[MOD];
vector<ll> two_pows;
vector<ll> five_pows;

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

void precompute() {
    mod_table[0] = 1;
    for(int i = 1; i < MOD; i++) {
        if(i%2 == 0 || i%5 == 0) {
            mod_table[i] = mod_table[i-1];
            continue;
        }
        mod_table[i] = (mod_table[i-1]*i)%MOD;
    }
}

int main() {
    precompute();
    ll ans = 1;
    ll pow2_max = log2(MAX);
    ll pow5_max = log2(MAX)/log2(5);
    ll p2 = 1; ll p5 = 1; two_pows.pb(1); five_pows.pb(1);
    for(int i = 1; i <= pow2_max; i++) {
        p2 *= 2; two_pows.pb(p2);
    }
    for(int i = 1; i <= pow5_max; i++) {
        p5 *= 5; five_pows.pb(p5);
    }
    for(int e2 = 0; e2 <= pow2_max; e2++) {
        for(int e5 = 0; e5 <= pow5_max; e5++) {          
            ll ub = MAX/(two_pows[e2]*five_pows[e5]);
            if(ub == 0) break;
            ans *= fast_exp(mod_table[MOD-1], ub/MOD, MOD);
            ans %= MOD;
            ans = (ans*mod_table[ub%MOD])%MOD;
        }
    }
    ll v2 = 0;
    ll v5 = 0;
    ll pow_2 = 2;
    ll pow_5 = 5;
    for(; pow_2 <= MAX; pow_2 *= 2) {
        v2 += MAX/pow_2;
    }
    for(; pow_5 <= MAX; pow_5 *= 5) {
        v5 += MAX/pow_5;
    }
    ans = (ans*fast_exp(2, v2-v5, MOD))%MOD;
    cout << ans << "\n";
    return 0;
}