#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1E9+7;
const ll K = 1E7;
const ll N = 1E12;

ll choose[K+1];
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

void init_choose() {
    choose[0] = 1; choose[K] = 1;
    for(ll i = 1; i < K; i++) {
        choose[i] = choose[i-1];
        choose[i] = (choose[i]*(K-i+1))%MOD;
        choose[i] = (choose[i]*m_inv(i))%MOD;
        if(choose[i] == 0) break;
    }
}

int main() {
    init_choose();
    for(ll j = 1; j <= K-2; j++) {
        ll sign = (j%2) ? 1 : -1;
        ll num = f_exp(K-j, N)-1;
        ll sum_mod = (num*m_inv(K-j-1))%MOD;
        sum_mod = ((K-j)*sum_mod)%MOD;
        sum_mod = (sign*sum_mod*choose[j])%MOD;
        ans = (ans+sum_mod)%MOD;
    }
    ll sign = (K%2) ? -1 : 1;
    ans = (ans+(N%MOD)*sign*K)%MOD;
    if(ans < 0) ans += MOD;
    cout << ans << "\n";
    return 0;
}