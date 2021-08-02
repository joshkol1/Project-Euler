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
    (void)!freopen("../problem_inputs/p067_grid.txt", "r", stdin);
    int n_rows;
    cin >> n_rows;
    vector<vector<int>> grid;
    for(size_t i = 0; i < n_rows; ++i) {
        vector<int> row(i+1);
        for(size_t j = 0; j <= i; ++j) 
            cin >> row[j];
        grid.pb(row);            
    }
    vector<vector<int>> best_sum;
    for(size_t i = 0; i < n_rows; ++i) {
        vector<int> row_sum;
        if(i == 0) {
            row_sum.pb(grid[i][0]);
            best_sum.pb(row_sum);
            continue;
        }
        for(size_t j = 0; j <= i; ++j) {
            if(j == 0) 
                row_sum.pb(best_sum[i-1][j]+grid[i][j]);
            else if(j == i) 
                row_sum.pb(best_sum[i-1][j-1]+grid[i][j]);
            else
                row_sum.pb(grid[i][j]+max(best_sum[i-1][j-1], best_sum[i-1][j]));
        }
        best_sum.pb(row_sum);
    }
    int ans = 0;
    for(auto n : best_sum[n_rows-1])
        ans = max(n, ans);
    cout << ans << endl;
    return 0;
}