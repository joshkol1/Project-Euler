#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<array>
#include<assert.h>
#include<cstring>
#include<math.h>
#include<climits>
#include<numeric>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back

/*
    Paper with result: https://web.iitd.ac.in/~atripath/publications/FP_3-var.pdf
*/

vector<ll> primes;
ll prime_bound;

void get_primes() {
    for(ll n = 2; n < prime_bound; ++n) {
        bool prime = true;
        for(ll i = 2; i*i <= n; ++i) {
            if(n%i == 0) {
                prime = false;
                break;
            }
        }
        if(prime)
            primes.pb(n);
    }
}

int main() {
    cin >> prime_bound;
    get_primes();
    ll answer = 0;
    for(size_t i = 0; i < primes.size(); ++i) {
        for(size_t j = i+1; j < primes.size(); ++j) {
            for(size_t k = j+1; k < primes.size(); ++k) {
                ll p = primes[i];
                ll q = primes[j];
                ll r = primes[k];
                answer += (2*p*q*r-p*q-p*r-q*r);
            }
        }
    }
    cout << answer << endl;
    return 0;
}