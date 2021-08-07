#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

bool good(int n) {
    if(n%10 == 0) return false;
    int rev = 0;
    int n_copy = n;
    while(n > 0) {
        rev *= 10;
        rev += n%10;
        n /= 10;
    }
    int sum = n_copy + rev;
    while(sum > 0) {
        if((sum%10)%2 == 0) return false;
        sum /= 10;
    }
    return true;
}

int main() {
    int ans = 0;
    for(int i = 1; i <= 1E9; i++) {
        ans += good(i);
    }
    cout << ans << "\n";
    return 0;
}