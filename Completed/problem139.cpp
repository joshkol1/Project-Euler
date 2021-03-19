#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int MAX = 1E8;
ll ans;

int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b%a, a);
}

int main() {
    for(int m = 2; 2*m*m < MAX; m++) {
        for(int n = 1; 2*m*m+2*m*n < MAX && n < m; n++) {
            if(gcd(m, n) != 1) continue;
            int a = m*m-n*n;
            int b = 2*m*n;
            int c = m*m+n*n;
            if(gcd(gcd(a, b), c) != 1) continue;
            int d = abs(b-a);
            if(c%d == 0) {
                int perim = a+b+c;
                ans += (MAX/perim);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}