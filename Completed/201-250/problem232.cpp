#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

long double dp[100][100][2];
long double best_prob;

/*
    Return the probability that player 2 wins from state (n1, n2, t).
*/
long double prob(int n1, int n2, int turn) {
    if(n1 >= 100) return 0;
    if(n2 >= 100) return 1;
    return dp[n1][n2][turn];
}

void calculate(int n1, int n2) {
    /*
        Fine if we overshoot goal of 100 by a bit, just want to cover all possible best moves.
        For example at 97, might be best to just go for 4 rather than 1 and 2.
    */
    for(int t = 1; (1<<(t-1))+n2 <= 200; t++) {
        int denom = (1<<t)+1;
        long double new_p = (2.0L/denom)*prob(n1, n2+(1<<(t-1)), 0)+(1-2.0L/denom)*prob(n1+1, n2, 1);
        dp[n1][n2][1] = max(dp[n1][n2][1], new_p);
    }
    dp[n1][n2][0] = 0.5L*prob(n1+1, n2, 1)+0.5L*prob(n1, n2, 1);
}

int main() {
    for(int i = 99; i >= 0; i--) {
        for(int j = 99; j >= 0; j--) {
            calculate(i, j);
        }
    }
    cout << setprecision(8) << prob(0, 0, 0) << "\n";
    return 0;
}