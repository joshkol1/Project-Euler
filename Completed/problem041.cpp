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

bool prime(ll n) {
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

int main() {
    ll best = 0;
    for(int n_digits = 1 ; n_digits <= 9; ++n_digits) {
        vector<ll> digits;
        for(ll i = 1; i <= n_digits; ++i)
            digits.pb(i);
        do {
            ll n = 0;
            for(size_t i = 0; i < digits.size(); ++i)
                n = 10*n+digits[i];
            if(prime(n))
                best = n;
        } while(next_permutation(digits.begin(), digits.end()));
    }
    cout << best << endl;
    return 0;
}