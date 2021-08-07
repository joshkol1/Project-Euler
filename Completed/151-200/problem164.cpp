#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

/*
    dp[k][n]: # of k digit strings ending in n
*/
ll dp[21][1000];

int main() {
    for(int n = 100; n <= 999; n++) {
        if((n/100)+(n/10)%10+n%10 <= 9) dp[3][n]++;
    }
    for(int k = 4; k <= 20; k++) {
        for(int n = 0; n <= 999; n++) {
            int s = (n/100)+(n/10)%10+n%10;
            if(s <= 9) {
                int s2 = (n/100)+(n/10)%10;
                int d = n/10;
                for(int i = 0; i <= 9-s2; i++) {
                    dp[k][n] += dp[k-1][100*i+d];
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i <= 999; i++) ans += dp[20][i];
    cout << ans << "\n";
    return 0;
}