#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
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
    auto dp = vector<vector<ll>>();
    for(size_t n = 0; n <= 100; ++n) {
        vector<ll> new_row(101, 0);
        if(n == 0) {
            dp.pb(new_row);
            continue;
        }
        new_row[n] = 1;
        for(size_t i = 1; i <= n/2; ++i) {
            for(size_t j = i; j <= n-i; ++j)
                new_row[i] += dp[n-i][j];
        }
        dp.push_back(new_row);
    }
    cout << accumulate(dp[100].begin(), dp[100].end(), 0LL) - 1 << endl;
    return 0;
}