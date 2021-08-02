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

int rows;

int main() {
    (void)!freopen("../problem_inputs/p011_grid.txt", "r", stdin);
    cin >> rows;
    vector<vector<int>> grid;
    for(int i = 0; i < rows; ++i) {
        vector<int> row(rows);
        for(int j = 0; j < rows; ++j) {
            cin >> row[j];
        }
        grid.pb(row);
    }
    int ans = 0;
    // Horizontal & vertical
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j <= rows-4; ++j) {
            ans = max(ans, grid[i][j]*grid[i][j+1]*grid[i][j+2]*grid[i][j+3]);
            ans = max(ans, grid[j][i]*grid[j+1][i]*grid[j+2][i]*grid[j+3][i]);
        }
    }
    // Down diagonal
    for(int i = 0; i <= rows-4; ++i) {
        for(int j = 0; j <= rows-4; ++j) 
            ans = max(ans, grid[i][j]*grid[i+1][j+1]*grid[i+2][j+2]*grid[i+3][j+3]);
    }
    // Up diagonal
    for(int i = 3; i < rows; ++i) {
        for(int j = 0; j <= rows-4; ++j)
            ans = max(ans, grid[i][j]*grid[i-1][j+1]*grid[i-2][j+2]*grid[i-3][j+3]);
    }
    cout << ans << endl;
    return 0;
}