#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

/*
    Recall that 1^2+2^2+...+n^2 = n(n+1)(2n+1)/6
    Therefore, all sums of consecutive palindromes can 
    be written as:
    (1^2+2^2+...+n^2)-(1^2+2^2+..+k^2) = 
    1/6*(2n^2+2nk+2k^2+3n+3k+1)(n-k), where k <= n-2.
    This yields some quick bounds:
        1. 1/6*(6k^2+6k+1) < 10^8
        2. 1/6*(2n^2+3n+1) < 10^8
    We can just iterate over all pairs of n and k to 
    generate all solutions. Use a set to not count
    same numbers multiple times, if they can be generated
    in multiple ways.
*/

const ll MAX = 1E8;
const ll K_MAX = 1E4;
ll ans;
set<ll> found_pals;

bool palindrome(ll v) {
    ll v_copy = v;
    ll rev = 0;
    while(v > 0) {
        rev *= 10;
        rev += v%10;
        v /= 10;
    }
    return rev == v_copy;
}

int main() {
    for(ll n = 1; 2*n*n+3*n+1 <= 6*MAX; n++) {
        ll k_bound = min(K_MAX, n-1);
        for(ll k = 0; k < k_bound; k++) {
            ll v = (2*n*n+2*n*k+2*k*k+3*n+3*k+1)*(n-k)/6;
            if(v < 1E8 && palindrome(v)) {
                found_pals.insert(v);
            }
        }
    }
    for(ll pal : found_pals) ans += pal;
    cout << ans << "\n";
    return 0;
}