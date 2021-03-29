#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const ll MAX = 1E12;
const ll MOD = 1E5;

ll fast_exp(ll b, ll e, ll m) {
    b %= m;
    ll ret = 1;
    while(e > 0) {
        if(e&1) ret = ret*b%m;
        b = b*b%m;
        e >>= 1;
    }
    return ret;
}

int main() {
    ll vp2 = 0;
    ll vp5 = 0;
    ll ans = 1;
    for(ll p2 = 2; p2 <= MAX; p2*=2) {
        vp2 += MAX/p2;
    }
    for(ll p5 = 5; p5 <= MAX; p5*=2) {
        vp5 += MAX/p5;
    }
    ans *= (2, vp5-vp2, MOD);
    for(int i = 3; i < MOD; i += 2) {
        if(i%2 )
    }
    return 0;
}