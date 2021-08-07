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
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    for(size_t i = 5; i <= 50; ++i)
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4];
    cout << dp[50] << endl;
    return 0;
}