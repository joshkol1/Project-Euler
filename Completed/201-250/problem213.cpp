#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

/*
    dp[f][i][j][m]: probability that fly f
    is at location (i, j) after m moves.
*/
long double dp[900][30][30][51];
long double source_p[30][30];

/*
    Compute the probability of subsequent moves from every square
*/
void comp_source_probs() {
    for(int r = 0; r < 30; r++) {
        for(int c = 0; c < 30; c++) {
            bool r_cond = (r == 0 || r == 29);
            bool c_cond = (c == 0 || c == 29);
            if(r_cond && c_cond) source_p[r][c] = 0.5;
            else if(r_cond ^ c_cond) source_p[r][c] = 1.0/3;
            else source_p[r][c] = 0.25;
        }
    }
}

/*
    Calculate state probabilities for fly f, where
    0 <= f <= 899.
*/
void process(int f) {
    int f_row = f/30;
    int f_col = f%30;
    dp[f][f_row][f_col][0] = 1;
    for(int m = 1; m <= 50; m++) {
        for(int l = 0; l < 900; l++) {
            int l_row = l/30;
            int l_col = l%30;
            if(l_row != 29) {
                dp[f][l_row][l_col][m] += source_p[l_row+1][l_col]*dp[f][l_row+1][l_col][m-1];
            }
            if(l_row != 0) {
                dp[f][l_row][l_col][m] += source_p[l_row-1][l_col]*dp[f][l_row-1][l_col][m-1];
            }
            if(l_col != 29) {
                dp[f][l_row][l_col][m] += source_p[l_row][l_col+1]*dp[f][l_row][l_col+1][m-1];
            }
            if(l_col != 0) {
                dp[f][l_row][l_col][m] += source_p[l_row][l_col-1]*dp[f][l_row][l_col-1][m-1];
            }
        }
    }
}

int main() {
    comp_source_probs();
    long double answer = 0;
    for(int f = 0; f < 900; f++) process(f);
    for(int l = 0; l < 900; l++) {
        long double empty_prob = 1;
        for(int f = 0; f < 900; f++) {
            empty_prob *= (1-dp[f][l/30][l%30][50]);
        }
        answer += empty_prob;
    }
    cout << setprecision(15) << answer << "\n";
    return 0;
}