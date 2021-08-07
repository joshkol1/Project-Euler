#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int MAX = 1E6;
int n_solutions[MAX];
int ans;

int main() {
    for(int m = 1; m <= MAX; m++) {
        for(int k = m/4+1; k < m; k++) {
            int v = m*(4*k-m);
            if(v >= MAX) break;
            n_solutions[v]++;
        }
    }
    for(int i = 1; i < MAX; i++) {
        ans += (n_solutions[i] == 10);
    }
    cout << ans << "\n";
    return 0;
}