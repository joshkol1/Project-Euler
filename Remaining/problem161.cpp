#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

int grid[9][12];
int num_placed;
ll total_ways;

void search(int r, int c) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 12; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
    if(num_placed == 36) {
        total_ways++;
        return;
    }
    /*
        Try placing all the pieces
    */
    if(c >= 12) {
        c = 0; r++;
    }
    if(grid[r][c] != 0) {
        search(r, c+1);
        return;
    }
    /*
        Horizontal long bar
    */
    if(c <= 9 && !grid[r][c+1] && !grid[r][c+2]) {
        grid[r][c] = 1; grid[r][c+1] = 1; grid[r][c+2] = 1;
        num_placed++;
        search(r, c+3);
        grid[r][c] = 0; grid[r][c+1] = 0; grid[r][c+2] = 0;
        num_placed--;
    }
    /*
        Vertical long bar
    */
    if(r <= 6 && !grid[r+1][c] && !grid[r+2][c]) {
        grid[r][c] = 1; grid[r+1][c] = 1; grid[r+2][c] = 1;
        num_placed++;
        search(r, c+1);
        grid[r][c] = 0; grid[r+1][c] = 0; grid[r+2][c] = 0;
        num_placed--;
    }
    /*
        Red L
    */
    if(c <= 10 && r <= 7 && !grid[r][c+1] && !grid[r+1][c]) {
        grid[r][c] = 1; grid[r][c+1] = 1; grid[r+1][c] = 1;
        num_placed++;
        search(r, c+2);
        grid[r][c] = 0; grid[r][c+1] = 0; grid[r+1][c] = 0;
        num_placed--;
    }
    /*
        Green L
    */
    if(c <= 10 && r <= 7 && !grid[r][c+1] && !grid[r+1][c+1]) {
        grid[r][c] = 1; grid[r][c+1] = 1; grid[r+1][c+1] = 1;
        num_placed++;
        search(r, c+2);
        grid[r][c] = 0; grid[r][c+1] = 0; grid[r+1][c+1] = 0;
        num_placed--;
    }
    /*
        Blue L
    */
    if(c <= 10 && r <= 7 && !grid[r+1][c] && !grid[r+1][c+1]) {
        grid[r][c] = 1; grid[r+1][c] = 1; grid[r+1][c+1] = 1;
        num_placed++;
        search(r, c+1);
        grid[r][c] = 0; grid[r+1][c] = 0; grid[r+1][c+1] = 0;
        num_placed--;
    }
    /*
        Orange L
    */
    if(c >= 1 && r <= 7 && !grid[r+1][c] && !grid[r+1][c-1]) {
        grid[r][c] = 1; grid[r+1][c] = 1; grid[r+1][c-1] = 1;
        num_placed++;
        search(r, c+1);
        grid[r][c] = 0; grid[r+1][c] = 0; grid[r+1][c-1] = 0;
        num_placed--;
    }
}

int main() {
    search(0, 0);
    cout << total_ways << "\n";
    return 0;
}