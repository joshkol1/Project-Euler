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
#include<functional>
#include<numeric>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back

bool naive_prime(ll n) {
    if(n == 1)
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

ll get_hamming(vector<ll>& factors, ll current_value, size_t index, ll limit) {
    if(index >= factors.size())
        return 1;
    ll ans = 0;
    for(size_t i = 0; current_value <= limit; ++i) {
        ans += get_hamming(factors, current_value, index+1, limit);
        current_value *= factors[index];
    }
    return ans;
}

int main() {
    vector<ll> primes;
    primes.pb(2);
    for(ll n = 3; n < 100; n += 2) {
        if(naive_prime(n))
            primes.pb(n);
    }
    cout << get_hamming(primes, 1, 0, 1E9) << endl;
    return 0;
}