#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long double pref_sum[62];
long double exps[62];
long double partial[62];

/*
    
*/

long double f_exp(long double base, ll n) {
    if(n == 0) return 1;
    long double half = f_exp(base, n/2);
    if(n%2) return half*half*base;
    else return half*half;
}

long double pow(ll n) {
    ll num = (1L<<n)-1;
    long double base = (num+0.0)/(1L<<n);
    return f_exp(base, 32);
}

void process(ll n) {
    exps[n] = pow(n);
    pref_sum[n] = pref_sum[n-1] + exps[n];
    partial[n] = n*exps[n] - pref_sum[n-1];
}

int main() {
    for(int i = 1; i <= 61; i++) {
        process(i);
        cout << i << " iterations: ";
        cout << setprecision(15) << partial[i] << "\n";
    }
    return 0;
}