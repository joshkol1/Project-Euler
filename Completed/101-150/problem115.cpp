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
    size_t m = 50;
    auto dp = vector<size_t>(51, 1);
    ++dp[50];
    for(size_t i = 51; dp[dp.size()-1] <= 1000000; ++i) {
        dp.push_back(dp[i-1]);
        for(size_t j = m; j < i; ++j) {
            dp[i] += dp[i-j-1];
        }
        ++dp[i];
    }
    cout << dp.size()-1 << endl;
    return 0;
}