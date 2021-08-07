#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int WIDTH = 32;
const int HEIGHT = 10;
vector<ll> walls;

void generate_walls(ll curr_wall, int depth) {
    if(depth > WIDTH) return;
    if(depth == WIDTH) {
        curr_wall += (1L<<WIDTH);
        walls.pb(curr_wall); return;
    }
    curr_wall += (1L<<depth);
    generate_walls(curr_wall, depth+2);
    generate_walls(curr_wall, depth+3);
}

bool conflict(ll w1, ll w2) {
    ll mask = (1L<<32)-2;
    return ((w1&mask)&(w2&mask)) > 0;
}

int main() {
    generate_walls(0, 0);
    int n_walls = walls.size();
    ll** dp = new ll*[HEIGHT+1];
    for(int i = 0; i < HEIGHT+1; i++) {
        dp[i] = new ll[n_walls];
    }
    for(int l = 1; l <= HEIGHT; l++) {
        for(int i = 0; i < n_walls; i++) {
            if(l == 1) dp[l][i] = 1;
            else {
                for(int j = 0; j < n_walls; j++) {
                    if(conflict(walls[i], walls[j])) continue;
                    dp[l][i] += dp[l-1][j];
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < n_walls; i++) ans += dp[HEIGHT][i];
    cout << ans << "\n";
    return 0;
}