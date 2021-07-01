#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int MAX = 5E7;
const int PRIME_BOUND = 100000;
bool candidate[MAX+1];
bool prime[MAX+1];
vector<int> primes;
int n_primes;

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

/*
    Is "a" a quadratic residue mod p?
    If a^((p-1)/2) = 1 (mod p) then return true.
    Otherwise return false.
*/
bool euler_criterion(ll a, ll p) {
    return fast_exp(a, (p-1)/2, p) == 1;
}

void init_sieve() {
    memset(prime, true, sizeof prime);
    prime[1] = false;
    prime[2] = true;
    for(int i = 4; i <= MAX; i += 2) prime[i] = false;
    for(int i = 3; i*i <= MAX; i += 2) {
        if(prime[i]) {
            for(int j = i*i; j < MAX; j += i) {
                prime[j] = false;
            }
        }
    }
    for(int i = 3; i < MAX; i += 2) {
        if(prime[i] && euler_criterion((i+1)/2, i)) {
            primes.pb(i);
        }
    }
    n_primes = primes.size();
    cout << "Num primes to check: ";
    cout << n_primes << "\n";
}

void init_candidates() {
    memset(candidate, true, sizeof candidate);
    for(int i = 0; primes[i] < PRIME_BOUND; i++) {
        int p = primes[i];
        for(ll n = 0; n <= p/2; n++) {
            ll t_n = 2*n*n-1;
            if(t_n%p == 0) {
                for(int c = n; c <= MAX; c += p) {
                    if(c == n && t_n == p) continue;
                    candidate[c] = false;
                }
            }
        }
    }
    int cand_count = 0;
    for(int i = 2; i <= MAX; i++) {
        cand_count += candidate[i];
    }
    cout << "Num candidates for n: ";
    cout << cand_count << "\n";
}

int main() {
    init_sieve();
    init_candidates();
    return 0;
}