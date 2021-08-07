#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int MAX = 1E8;
bool prime[MAX+1];
vector<int> prime_list;
ll ans;

/*
    Wilson's theorem: (p-1)! = -1 (mod p)
    Just compute modular inverses and multiply them
    to -1
*/

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
    for(int i = 5; i <= MAX; i++) {
        if(prime[i]) {
            prime_list.pb(i);
        }
    }
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

ll m_inv(ll n, ll p) {
    return fast_exp(n, p-2, p);
}

ll process(int p) {
    ll ret = -1;
    ll fact = -1;
    for(int i = 1; i <= 4; i++) {
        fact = (m_inv(p-i, p)*fact)%p;
        ret = (ret+fact)%p;
    }
    if(ret < 0) ret += p;
    return ret;
}

int main() {
    init_sieve();
    for(int p : prime_list) {
        ans += process(p);
    }
    cout << ans << "\n";
    return 0;
}