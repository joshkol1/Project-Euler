#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

/*
    TODO: add explanation. Just find all numbers
    (k+1)^3-k^3 = 3k^2+3k+1 below 1,000,000 that are
    prime.
*/

bool prime(int n) {
    if(n == 1) return false;
    for(int i = 2; i*i <= n; i++) {
        if(n%i == 0) return false;
    }
    return true;
}

int main() {
    int ans = 0;
    for(int k = 1; 3*k*k+3*k+1 < 1E6; k++) {
        if(prime(3*k*k+3*k+1)) ans++;
    }
    cout << ans << "\n";
    return 0;
}