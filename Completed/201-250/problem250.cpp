#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const ll N_TERMS = 250250;
const ll MOD = 1E16;
ll S[N_TERMS+1];
ll dp[N_TERMS+1][250];

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
    for(int i = 1; i <= N_TERMS; ++i)
        S[i] = fast_exp(i%250, i, 250);
    dp[0][0] = 1;
    for(int index = 1; index <= N_TERMS; ++index) {
        for(int m = 0; m < 250; ++m) {
            dp[index][m] = dp[index-1][m];
            int diff = m - S[index];
            if(diff < 0) diff += 250;
            ll add_mod = dp[index-1][diff] % MOD;
            dp[index][m] = (dp[index][m] + add_mod) % MOD; 
        }
    }
    cout << dp[N_TERMS][0] - 1 << "\n";
    return 0;
}