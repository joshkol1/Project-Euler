#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    Notice that B(n+1) = (n+1)^n/n!*B(n)
*/

const ll MAX = 20000;
const ll MOD = 1E9+7;
unordered_map<ll, ll> product_pf;
unordered_map<ll, ll> fact_pf;
ll ans = 1;

ll f_exp(ll n, ll p) {
    n %= MOD;
    ll res = 1;
    while(p > 0) {
        if(p&1) res = res * n % MOD;
        n = n * n % MOD;
        p >>= 1;
    }
    return res;
}

ll m_inv(ll n) {
    return f_exp(n, MOD-2);
}

void update_pf(ll n) {
    ll n_copy = n;
    for(ll i = 2; i*i <= n; i++) {
        while(n%i == 0) {
            product_pf[i] += (n_copy-1);
            n /= i;
        }
    }
    if(n != 1) product_pf[n] += (n_copy-1);
    ll m1 = n_copy-1;
    for(ll i = 2; i*i <= m1; i++) {
        while(m1%i == 0) {
            fact_pf[i]++;
            m1 /= i;
        }
    }
    if(m1 != 1) fact_pf[m1]++;
    for(auto const& p : fact_pf) {
        product_pf[p.first] -= p.second;
    }
}

int main() {
    for(ll i = 2; i <= MAX; i++) {
        ll p_mod = 1;
        update_pf(i);
        for(auto const& pr : product_pf) {
            ll exp_mod = f_exp(pr.first, pr.second+1)-1;
            exp_mod = exp_mod*(m_inv(pr.first-1))%MOD;
            p_mod = (p_mod*exp_mod)%MOD;
        }
        ans = (ans+p_mod)%MOD;
    }
    cout << ans << "\n";
    return 0;
}