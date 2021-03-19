#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int MAX = 2E6;
bool prime[MAX+1];
vector<int> prime_list;
ll ans;

/*
    Let (p1, p2) be the prime pair. We wish check when
    ___p1 = 0 (mod p2). Let 10^n be the smallest power
    of 10 greater than p1. Then we want to find the
    smallest k s.t. k*(10^n) = -p1 (mod p2).
    This means k = (10^n)^(-1)*(p2-p1) (mod p2)
*/

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

ll m_inv(ll n, ll p) {
    return fast_exp(n, p-2, p);
}

void init_sieve() {
    memset(prime, true, sizeof prime);
    prime[1] = false;
    prime[2] = true;
    for(int i = 4; i <= MAX; i += 2) {
        prime[i] = false;
    }
    for(int i = 3; i*i <= MAX; i += 2) {
        if(prime[i]) {
            for(int j = i*i; j <= MAX; j += i) {
                prime[j] = false;
            }
        }
    }
    bool seen = false;
    for(int i = 2; i <= MAX; i++) {
        if(seen) break;
        if(prime[i]) {
            prime_list.pb(i);
            if(i > 1E6) seen = true;
        }
    }
}

ll process(int ind) {
    int p1 = prime_list[ind];
    int p2 = prime_list[ind+1];
    ll ten_pow = 1;
    while(ten_pow <= p1) ten_pow *= 10;
    ll ten_inv = m_inv(ten_pow, p2);
    ll k = (ten_inv*(p2-p1))%p2;
    if(k < 0) k += p2;
    if(p1 == 19) cout << k*ten_pow+p1 << "\n";
    return k*ten_pow+p1;
}

int main() {
    init_sieve();
    int n_primes = prime_list.size();
    for(int i = 2; i < n_primes-1; i++) {
        ans += process(i);
    }
    cout << ans << "\n";
    return 0;
}