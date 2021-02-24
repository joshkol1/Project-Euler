#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1E9+7;

ll f_exp(ll n, ll p) {
    if(p == 0) return 1;
    ll half_p = f_exp(n, p/2);
    if(p%2 == 0) return (half_p*half_p*n)%MOD;
    else return (half_p*half_p)%MOD;
}

int main() {
    
    return 0;
}