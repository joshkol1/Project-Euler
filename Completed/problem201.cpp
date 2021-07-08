#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

vector<int> S;
const int N = 100;
const int SSET_SIZE = 50;
const int max_sum = N*(N+1)*(2*N+1)/6 - SSET_SIZE*(SSET_SIZE+1)*(2*SSET_SIZE+1)/6;

int main() {
    // dp[i][j][k]: how many ways to make sum of k, using i terms, up to index j?
    auto dp = new int[SSET_SIZE+1][N+1][max_sum+1]();
    for(int i = 1; i <= 100; ++i) 
        S.pb(i*i);
    for(int i = 0; i <= N; ++i) {
        dp[0][i][0] = 1;
    }
    for(int terms = 1; terms <= SSET_SIZE; ++terms) {
        for(int index = 1; index <= N; ++index) {
            for(int sum = 1; sum <= max_sum; ++sum) {
                if(sum-S[index-1] >= 0)
                    dp[terms][index][sum] += dp[terms-1][index-1][sum-S[index-1]];
                dp[terms][index][sum] += dp[terms][index-1][sum];
            }
        }
    }
    ll answer = 0;
    for(int sum = 1; sum <= max_sum; ++sum) {
        if(dp[SSET_SIZE][N][sum] == 1)
            answer += sum;
    }
    cout << answer << "\n";
    delete[] dp;
    return 0;
}