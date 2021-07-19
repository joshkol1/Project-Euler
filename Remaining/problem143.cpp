#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const ll max_pqr = 120000;

ll gcd(ll a, ll b) {
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

int main() {
    ll ans = 0;
    for(ll a = 1; a < max_pqr; ++a) {
        ll a_sq = a*a;
        for(ll b = a+1; a_sq+b*(a+b) <= max_pqr*max_pqr; ++b) {
            if(gcd(a, b) != 1)
                continue;
            ++ans;
        }
    }
    cout << ans << "\n";
    return 0;
}