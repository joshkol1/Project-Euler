#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

int grid[1001][1001];
ll pref[1001][1001];
ll min_sum = LONG_LONG_MAX;

void init_grid() {
    int t = 0;
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= i; j++) {
            t = (615949*t+797807)%(1<<20);
            grid[i][j] = t-(1<<19);
            if(j == 0) {
                pref[i][j] = grid[i][j];
            }
            else {
                pref[i][j] = pref[i][j-1]+grid[i][j];
            }
        }
    }
}

void process_top(int i, int j) {
    ll curr_sum = 0;
    for(int r = 0; r <= 1000-i; r++) {
        curr_sum += (pref[i+r][j+r]-pref[i+r][j-1]);
        min_sum = min(min_sum, curr_sum);
    }
}

int main() {
    init_grid();
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= i; j++) {
            process_top(i, j);
        }
    }
    cout << min_sum << "\n";
    return 0;
}