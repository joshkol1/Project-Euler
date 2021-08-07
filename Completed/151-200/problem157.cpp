#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<array>
#include<math.h>
#include<assert.h>
using namespace std;
typedef long long ll;
#define pb push_back

ll two_pows[19];
ll five_pows[19];

ll gcd(ll a, ll b) {
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

int main() {
    ll ans = 0;
    for(size_t i = 0; i < 19; ++i) {
        if(i == 0) {
            two_pows[i] = 1;
            five_pows[i] = 1;
        }
        else {
            two_pows[i] = two_pows[i-1]*2;
            five_pows[i] = five_pows[i-1]*5;
        }
    }
    for(int n = 1; n <= 9; ++n) {
        ll ten_pow = two_pows[n]*five_pows[n];
        ll rhs = ten_pow*ten_pow;
        for(int i = 0; i <= 2*n; ++i) {
            for(int j = 0; j <= 2*n; ++j) {
                ll f1 = two_pows[i]*five_pows[j];
                if(f1 > rhs/f1)
                    continue;
                ll p_a = f1+ten_pow;
                ll p_b = rhs/f1+ten_pow;
                ll cf = gcd(p_a, p_b);
                for(ll f = 1; f*f <= cf; ++f) {
                    if(cf%f)
                        continue;
                    if(f*f == cf)
                        ++ans;
                    else
                        ans += 2;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}