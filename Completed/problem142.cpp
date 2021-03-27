#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back

double eps = 1e-9;
ll sum_bound = 2000000;
ll best_sum = 2000000;

int gcd(ll a, ll b) {
    if(a == 0) return b;
    return gcd(b%a, a);
}

bool square(ll n) {
    ld root = sqrt(n);
    return abs(root-round(root)) < eps;
}

int main() {
    for(ll x = 18; x < sum_bound; x++) {
        for(ll b = 1; b*b*b*b < x; b++) {
            for(ll a = b+1; a*a*a*a < x; a += 2) {
                ll a4 = a*a*a*a;
                ll b4 = b*b*b*b;
                ll a2b2 = a*a*b*b;
                for(ll k = 1; k*k*(a4+2*a2b2+b4) < x; k++) {
                    if(gcd(a, b) != 1) continue;
                    ll m = k*(a*a-b*b);
                    ll n = k*2*a*b;
                    if(!square(2*x-m*m)) continue;
                    if(!square(2*x-2*m*m-n*n)) continue;
                    if(!square(2*x-m*m-n*n)) continue;
                    ll terms_sum = 3*x-2*m*m-n*n;
                    sum_bound = min(sum_bound, terms_sum);
                    best_sum = min(best_sum, sum_bound);
                }
            }
        }
    }
    cout << best_sum << "\n";
    return 0;
}