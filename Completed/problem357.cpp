#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int MAX_VAL = 1E8;
bool prime[MAX_VAL+1];
ll total = 1;
vector<ll> init_filter;

/*
    Observations:
        (1) Number must contain a factor of 2 (except 1). Otheerwise, we 
        get odd+odd=even for d+n/d.
        (2) n+1 must be prime.
    The above two narrow the list of candidates downto ~500000 numbers. From
    here, just brute force the divisors and test for primality of sum.
    Note that precomputing primes up to 10^8 using a sieve is helpful.
*/

void init_sieve() {
    memset(prime, true, sizeof prime);
    prime[1] = false;
    for(int i = 2; i <= MAX_VAL; i++) {
        if(prime[i]) {
            for(int j = 2*i; j <= MAX_VAL; j += i) {
                prime[j] = false;
            }
        }
    }
}

bool condition(ll n) {
    for(int i = 1; i*i < n; i++) {
        if(n%i == 0 && !prime[i+n/i]) return false;
    }
    return true;
}

int main() {
    init_sieve();
    for(ll i = 1; i < MAX_VAL/2; i+=2) {
        if(prime[i+2] && prime[2*i+1]) {
            init_filter.pb(2*i);
        }
    }
    for(ll n : init_filter) {
        if(condition(n)) total += n;
    }
    cout << total << "\n";
    return 0;
}