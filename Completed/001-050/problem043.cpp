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

int main() {
    ll ans = 0;
    vector<ll> digits = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17};
    do {
        bool good = true;
        for(size_t i = 0; i < primes.size(); ++i) {
            if((digits[i+1]*100+digits[i+2]*10+digits[i+3])%primes[i] != 0) {
                good = false;
                break;
            }
        }
        if(good) {
            ll n = 0;
            for(size_t i = 0; i < digits.size(); ++i)
                n = 10*n+digits[i];
            ans += n;
        }
    } while(next_permutation(digits.begin(), digits.end()));
    cout << ans << endl;
    return 0;
}