#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 bigint;
#define pb push_back

const int prime_max = 100;
const ll UB = 1E16-1;
vector<int> primes;

void get_primes() {
    for(int n = 2; n < prime_max; ++n) {
        bool prime = true;
        for(int i = 2; i*i <= n; ++i) {
            if(!(n%i)) {
                prime = false;
                break;
            }
        }
        if(prime)
            primes.pb(n);
    }
}

int n_elements(int subset) {
    int elems = 0;
    while(subset > 0) {
        elems += (subset&1);
        subset >>= 1;
    }
    return elems;
}

int main() {
    get_primes();
    bigint answer = 0;
    size_t n_primes = primes.size();
    for(int i = 1; i < 1<<n_primes; ++i) {
        int sset_primes = n_elements(i);
        ll prod = 1;
        for(size_t j = 0; j < n_primes; ++j) {
            if(i & (1<<j)) {
                prod *= primes[j];
                if(prod >= UB)
                    break;
            }
        }
        if(prod > UB)
            break;
        if(sset_primes%2)
            answer += UB/prod;
        else
            answer -= UB/prod;
    }
    cout << (ll)answer << "\n";
    return 0;
}