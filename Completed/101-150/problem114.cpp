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
    auto dp = vector<size_t>(51, 0);
    dp[0] = dp[1] = dp[2] = 1;
    dp[3] = 2;
    for(size_t i = 4; i <= 50; ++i) {
        dp[i] = dp[i-1];
        for(size_t j = 3; j < i; ++j)
            dp[i] += dp[i-j-1];
        ++dp[i];
    }
    cout << dp[50] << endl;
    return 0;
}