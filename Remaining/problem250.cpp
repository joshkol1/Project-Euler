#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

ll MOD = 1E16;
int mod_count[250];
ll choose[30001][30001];
ll dp[250][250];

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
    for(int i = 1; i <= 250250; i++) {
        mod_count[fast_exp(i%250, i, 250)]++;
    }
    for(int i = 0; i < 250; i++) {
        cout << i << " " << mod_count[i] << "\n";
    }
    return 0;
}