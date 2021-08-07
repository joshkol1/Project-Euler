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
    if(n < 0)
        n = -n;
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
    int max_primes = 0;
    int max_a, max_b;
    for(ll a = -999; a <= 999; ++a) {
        for(ll b = -1000; b <= 1000; ++b) {
            for(ll n = 0; ; ++n) {
                if(!prime(n*n+a*n+b)) {
                    if(n+1 > max_primes) {
                        max_primes = n+1;
                        max_a = a;
                        max_b = b;
                    }
                    break;
                }
            }
        }
    }
    cout << max_a*max_b << endl;
}