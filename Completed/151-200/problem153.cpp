#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const ll search_range = 1E8;

ll gcd(ll a, ll b) {
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

int main() {
    ll answer = 0;
    for(ll n = 1; n <= search_range; ++n) {
        answer += (search_range/n)*n;
    }
    for(ll p = 1; p*p <= search_range; ++p) {
        for(ll q = p; p*p+q*q <= search_range; ++q) {
            if(gcd(p, q) != 1)
                continue;
            ll magn = p*p+q*q;
            ll max_k = search_range/magn;
            ll sum = 0;
            for(ll k = 1; k <= max_k; ++k) {
                sum += k*(search_range/(magn*k));
            }
            if(q == 1)
                answer += 2*p*sum;
            else
                answer += 2*(p+q)*sum;
        }
    }
    cout << answer << "\n";
    return 0;
}