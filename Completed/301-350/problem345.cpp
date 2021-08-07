#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<array>
#include<assert.h>
using namespace std;
typedef long long ll;
#define pb push_back

int main() {
    (void)!freopen("../../problem_inputs/p345_matrix.txt", "r", stdin);
    size_t N;
    cin >> N;
    vector<vector<int>> grid;
    for(size_t i = 0; i < N; ++i) {
        vector<int> row(N);
        for(size_t j = 0; j < N; ++j)
            cin >> row[j];
        grid.pb(row);
    }
    auto bit_count = new size_t[1u<<N];
    for(size_t i = 0; i < 1u<<N; ++i)
        bit_count[i] = (i&1)+bit_count[i/2];
    auto dp = new int*[N];
    for(size_t i = 0; i < N; ++i)
        dp[i] = new int[1<<N];
    for(size_t i = 0; i < N; ++i) {
        if(i == 0) {
            for(size_t j = 0; j < N; ++j)
                dp[i][1<<j] = grid[i][j];
        }
        else {
            // Pick new element to include
            for(size_t j = 0; j < N; ++j) {
                // Check compatibility of all subsets with current entry
                for(size_t k = 0; k < 1u<<N; ++k) {
                    if((bit_count[k] == i+1) && (k&(1<<j)))
                        dp[i][k] = max(dp[i][k], grid[i][j]+dp[i-1][k^(1<<j)]);
                }
            }
        }
    }
    cout << dp[N-1][(1<<N)-1] << "\n";
    for(size_t i = 0; i < N; ++i)
        delete[] dp[i];
    delete[] bit_count;
    return 0;
}