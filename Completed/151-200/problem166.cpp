#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

int grid[4][4];
int params[9] = {0, 1, 2, 3, 4, 5, 6, 9, 10};
int row_sum;
int num_ways;

bool validate() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(grid[i][j] < 0 || grid[i][j] >= 10) return false;
        }
    }
    for(int i = 0; i < 4; i++) {
        if(grid[i][0]+grid[i][1]+grid[i][2]+grid[i][3] != row_sum) return false;
        if(grid[0][i]+grid[1][i]+grid[2][i]+grid[3][i] != row_sum) return false;
    }
    if(grid[0][3]+grid[1][2]+grid[2][1]+grid[3][0] != row_sum) return false;
    if(grid[0][0]+grid[1][1]+grid[2][2]+grid[3][3] != row_sum) return false;
    return true;
}

void dfs(int depth) {
    if(depth >= 9) {
        int col3_sum = grid[2][0]+grid[2][1]+grid[2][2];
        if(col3_sum+9 < row_sum || col3_sum > row_sum) return;
        grid[3][3] = row_sum-grid[0][0]-grid[1][1]-grid[2][2];
        grid[3][2] = row_sum-grid[0][2]-grid[1][2]-grid[2][2];
        grid[3][1] = row_sum-grid[0][1]-grid[1][1]-grid[2][1];
        grid[3][0] = row_sum-grid[3][1]-grid[3][2]-grid[3][3];
        grid[2][0] = row_sum-grid[0][0]-grid[1][0]-grid[3][0];
        grid[2][3] = row_sum-grid[2][0]-grid[2][1]-grid[2][2];
        grid[1][3] = row_sum-grid[1][0]-grid[1][1]-grid[1][2];
        num_ways += validate();
        return;
    }
    /*
        Pruning for unsolvable grids
    */
   if(depth == 4) {
        row_sum = grid[0][0]+grid[0][1]+grid[0][2]+grid[0][3];
    }
    if(depth == 7) {
        int row2_sum = grid[1][0]+grid[1][1]+grid[1][2];
        if(row2_sum+9 < row_sum || row2_sum > row_sum) return;
    }
    if(depth == 8) {
        int col2_sum = grid[0][1]+grid[1][1]+grid[2][1];
        if(col2_sum+9 < row_sum || col2_sum > row_sum) return;
    }
    int row = params[depth]/4;
    int col = params[depth]%4;
    for(int i = 0; i <= 9; i++) {
        grid[row][col] = i;
        dfs(depth+1);
    }
}

int main() {
    dfs(0);
    cout << num_ways << "\n";
    return 0;
}