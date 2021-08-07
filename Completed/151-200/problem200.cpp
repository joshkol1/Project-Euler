#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<array>
#include<assert.h>
#include<string>
#include<math.h>
#include<climits>
#include<utility>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back

size_t num_squbes;
vector<ll> search_bounds = 
    {10000000, 1000000000, 100000000000, 10000000000000};
size_t prime_bound;
vector<bool> prime;
vector<ll> primes;
vector<ll> candidates;
vector<ll> ten_pows;

bool is_prime(ll n) {
    if(n <= 1)
        return false;
    if(n == 2)
        return true;
    if(n%2 == 0)
        return false;
    for(ll i = 3; i*i <= n; i += 2) {
        if(n%i == 0)
            return false;
    }
    return true;
}

// Initialize primality sieve
void init() {
    primes.clear();
    prime = vector<bool>(prime_bound+1, true);
    if(prime_bound >= 1)
        prime[1] = false;
    for(size_t i = 2; i*i <= prime_bound; ++i) {
        if(prime[i]) {
            for(size_t j = i*i; j <= prime_bound; j += i) {
                prime[j] = false;
            }
        }
    }
    primes.pb(2);
    for(size_t i = 3; i <= prime_bound; i += 2) {
        if(prime[i])
            primes.pb(i);
    }
}

bool prime_proof(ll cand) {

    switch(cand%10) {
        case 0:
        case 2:
        case 4:
        case 5:
        case 6:
        case 8:
            cand -= (cand%10);
            for(auto d : {1, 3, 7, 9}) {
                if(is_prime(cand+d))
                    return false;
            }
            break;
        default:
            auto n_digits = to_string(cand).length();
            for(size_t i = 0; i < n_digits; ++i) {
                auto pos_dig = (cand/ten_pows[i])%10;
                if(i != n_digits-1) {
                    if(is_prime(cand-pos_dig*ten_pows[i]))
                        return false;
                }
                for(ll delta = -pos_dig; delta < 10-pos_dig; ++delta) {
                    if(is_prime(cand+ten_pows[i]*delta))
                        return false;
                }
            }
    }
    return true;
}

int main() {
    cin >> num_squbes;
    ten_pows.pb(1);
    for(size_t i = 1; i <= 18; ++i) 
        ten_pows.pb(ten_pows[i-1]*10);
    for(auto sb : search_bounds) {
        prime_bound = sqrt(sb/8);
        init();
        candidates.clear();
        for(auto p1 : primes) {
            for(auto p2 : primes) {
                if(p1 == p2)
                    continue;
                auto cand = p1*p1*p2*p2*p2;
                if(cand > sb)
                    break;
                if(to_string(cand).find("200") != string::npos)
                    candidates.pb(cand);
            }
        }
        sort(candidates.begin(), candidates.end());
        size_t ans = 0;
        for(auto c : candidates) {
            ans += prime_proof(c);
            if(ans >= num_squbes) {
                cout << c << endl;
                return 0;
            }
        }
    }
    return 0;
}