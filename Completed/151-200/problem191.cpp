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
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back

int main() {
    auto dp = vector<ll>(31, 0);
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;
    dp[3] = 7;
    for(size_t i = 4; i <= 30; ++i)
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    ll ans = dp[30];
    for(size_t i = 0; i < 30; ++i)
        ans += dp[i]*dp[29-i];
    cout << ans << endl;
    return 0;
}