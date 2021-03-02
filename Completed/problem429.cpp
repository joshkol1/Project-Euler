#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1E9+9;
const ll MAX = 1E8;
bool prime[MAX+1];
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

/*  
    Use Legendre for p-adic valuation
*/
void update_prime(ll n) {
    ll pow = 0;
    ll n_copy = n;
    while(n <= MAX) {
        pow += MAX/n;
        n *= n_copy;
    }
    ans = ans*(f_exp(n_copy, 2*pow)+1)%MOD;
}

/*
    Use sieve to efficiently calculate primes
*/
void solve() {
    for(ll i = 2; i <= MAX; i++) {
        if(prime[i]) {
            for(int j = 2*i; j <= MAX; j += i) {
                prime[j] = false;
            }
            update_prime(i);
        }
    }
}

int main() {
    memset(prime, true, sizeof prime);
    solve();
    cout << ans << "\n";
    return 0;
}