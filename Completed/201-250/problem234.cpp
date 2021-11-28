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
#include<cstring>

typedef long long ll;
typedef long double ld;
#define pb push_back

const ll semi_bound = 999966663333LL;
const int prime_bound = 1.1E6; // 1E6 plus wiggle room to get first prime over 1 million
bool isPrime[prime_bound+1];
std::vector<ll> primes;

void init_sieve() {
    memset(isPrime, true, sizeof isPrime);
    primes.pb(2);
    for(int i = 4; i <= prime_bound; i += 2) {
        isPrime[i] = false;
    }
    for(int i = 3; i*i <= prime_bound; i += 2) {
        if(isPrime[i]) {
            for(int j = i*i; j <= prime_bound; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for(ll i = 3; i <= prime_bound; i += 2) {
        if(isPrime[i]) {
            primes.pb(i);
            if(i*i >= semi_bound) {
                break;
            }
        }
    }
}

int main() {
    init_sieve();
    ll answer = 0;
    for(size_t i = 0; i < primes.size()-1; ++i) {
        auto p1 = primes[i];
        auto p2 = primes[i+1];
        if(i == primes.size()-2) {
            for(ll p1_multiple = p1*p1+p1; p1_multiple <= semi_bound; p1_multiple += p1) {
                answer += p1_multiple;
            }
            for(ll p2_multiple = semi_bound/p2*p2; p2_multiple >= p1*p1; p2_multiple -= p2) {
                answer += p2_multiple;
            }
            if(p1*p2 <= semi_bound) {
                answer -= 2*p1*p2;
            }
        }
        else {
            answer += (p2*p2/p1-p1)*p1*(p2*p2/p1+p1+1)/2;
            answer += (p2-p1*p1/p2-1)*(p1*p1/p2+p2)*p2/2;
            answer -= 2*p1*p2;
        }
    }
    std::cout << answer << std::endl;
    return 0;
}