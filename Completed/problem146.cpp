#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int MAX = 150000000;
const int PRIME_BOUND = 10000;
const int residues[] = {1,3,7,9,13,27};
bool candidate[MAX];
bool prime[MAX];
vector<int> primes;
int n_primes;

bool manual_prime(ll n) {
    for(int i : primes) {
        if(i > n) break;
        if(n == i) return true;
        if(n%i == 0) return false;
    }
    return true;
}

void init_sieve() {
    memset(prime, true, sizeof prime);
    prime[1] = false;
    prime[2] = true;
    primes.pb(2);
    for(int i = 4; i < MAX; i += 2) prime[i] = false;
    for(int i = 3; i*i < MAX; i += 2) {
        if(prime[i]) {
            for(int j = i*i; j < MAX; j += i) {
                prime[j] = false;
            }
        }
    }
    for(int i = 3; i < MAX; i += 2) {
        if(prime[i]) primes.pb(i);
    }
    n_primes = primes.size();
}

void init_candidates() {
    memset(candidate, true, sizeof candidate);
    for(int p = 3; p < PRIME_BOUND; p+=2) {
        if(!prime[p]) continue;
        for(int n = 0; n < p; n++) {
            bool good = true;
            for(int r : residues) {
                if((n*n+r)%p==0) {
                    good = false; break;
                }
            }
            /*
                If n*n+r = 0 (mod p), then candidates
                cannot be n mod p.
            */
            if(!good) {
                int start = n;
                if(start%2 == 1) start += p;
                for(int ind = start; ind < MAX; ind += 2*p) {
                    candidate[ind] = false;
                }
            }
        }
    }
}

bool simul_good(ll n) {
    for(int i : primes) {
        if(i > n) break;
        if((n*n+1)%i == 0) return false;
        if((n*n+3)%i == 0) return false;
        if((n*n+7)%i == 0) return false;
        if((n*n+9)%i == 0) return false;
        if((n*n+13)%i == 0) return false;
        if((n*n+27)%i == 0) return false;
    }
    if(manual_prime(n*n+21)) return false;
    return true;
}

int main() {
    init_candidates();
    init_sieve();
    ll ans = 0;
    for(ll n = 10; n < MAX; n += 10) {
        if(n <= PRIME_BOUND+100 || candidate[n]) {
            if(!simul_good(n)) continue;
            ans += n;
        }
    }
    cout << ans << "\n";
    return 0;
}