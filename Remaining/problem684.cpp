#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    s(n): If n%9 == 0, then do all nines. Else, do
    (n%9)(all nines). 
    Number of digits: (n+8)/9 (integer division)
    ===> first digit = n - 9*[(n-1)/9]
    Therefore, s(n) = (n - 9*[(n-1)/9] + 1) * 10^((n-1)/9) - 1
    S(k)
*/

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