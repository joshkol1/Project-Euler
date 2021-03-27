#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

ll ten_pows[11];

bool prime(ll n) {
    if(n == 1) return false;
    if(n == 2) return false;
    for(ll i = 3; i*i <= n; i+=2) {
        if(n%i == 0) return false;
    }
    return true;
}

int main() {
    ten_pows[0] = 1;
    ll ten_p = 1;
    for(int i = 1; i <= 10; i++) {
        ten_p *= 10; ten_pows[i] = ten_p;
    }
    
    return 0;
}