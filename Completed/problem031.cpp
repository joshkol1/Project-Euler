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

int main() {
    int total = 200;
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200};
    vector<vector<int>> dp;
    dp.pb({1, 1, 1, 1, 1, 1, 1, 1, 1});
    for(int tot = 1; tot <= total; ++tot) {
        vector<int> new_row = {0};
        for(int i = 1; i <= 8; ++i) {
            new_row.pb(new_row[i-1]);
            if(coins[i-1] <= tot) {
                for(int j = 1; j*coins[i-1] <= tot; ++j)
                    new_row[i] += dp[tot-j*coins[i-1]][i-1];
            }
        }
        dp.pb(new_row);
    }
    cout << dp[total][8] << endl;
    return 0;
}