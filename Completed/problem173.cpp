#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

int MAX = 1E6;
int ans;

int main() {
    int ans = 0;
    for(int i = 8; i <= MAX; i++) {
        for(int j = 2; j*j < i; j += 2) {
            if(i%j == 0 && (i/j)%2 == 0) ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}