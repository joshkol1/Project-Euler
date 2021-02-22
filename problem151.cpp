#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// dp[a][b][c][d]: expected value when starting with a 1's, b 2's, c 4's, d 8's
double dp[16][8][4][2];
int par[4];
int ch[4];
double p[4];

int remaining(int a, int b, int c, int d) {
    return a+2*b+4*c+8*d;
}

void compute(int a, int b, int c, int d) {
    par[0] = a; par[1] = b; par[2] = c; par[3] = d;
    int n_paper = a+b+c+d;
    for(int i = 0; i < 4; i++) p[i] = (par[i]+0.0)/n_paper;
    double ans = 0;
    if(n_paper == 1) ans++;
    for(int i = 0; i < 4; i++) {
        // If we have paper type i, split it & add result to DP
        if(p[i] > 1e-7) { 
            for(int j = 0; j < 4; j++) ch[j] = par[j];
            ch[i]--;
            for(int j = 0; j < i; j++) ch[j]++;
            ans += p[i]*dp[ch[0]][ch[1]][ch[2]][ch[3]];
        }
    }
    dp[a][b][c][d] = ans;
}

int main() {
    // We need to compute bottom up by area of paper remaining
    for(int paper = 2; paper <= 15; paper++) {
        for(int i = 0; i < 16; i++) {
            for(int j = 0; j < 8; j++) {
                for(int k = 0; k < 4; k++) {
                    for(int l = 0; l < 2; l++) {
                        if(paper != remaining(i, j, k, l)) continue;
                        compute(i, j, k, l);
                    }
                }
            }
        }
    }
    cout << dp[1][1][1][1] << "\n";
    return 0;
}