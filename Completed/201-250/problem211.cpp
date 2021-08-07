#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int MAX = 64000000;
const int SQRT_MAX = 8000;
const double eps = 1e-9;
int spf[MAX+1];

bool square(ll n) {
    double n_rt = sqrt(n);
    return abs(n_rt-(ll)n_rt) < eps;
}

void init_sieve() {
    for(int i = 2; i <= MAX; i++) {
        spf[i] = (i%2) ? i : 2;
    }
    for(int i = 3; i*i <= MAX; i += 2) {
        if(spf[i] == i) {
            for(int j = i*i; j <= MAX; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

int main() {
    init_sieve();
    ll ans = 1;
    for(int i = 2; i <= MAX; i++) {
        ll dsq_sum = 1;
        int i_copy = i;
        while(i_copy > 1) {
            ll p_sum = 1;
            int p = spf[i_copy];
            while(i_copy%p == 0) {
                i_copy /= p;
                p_sum = 1+p_sum*p*p;
            }
            dsq_sum *= p_sum;
        }
        if(square(dsq_sum)) ans += i;
    }
    cout << ans << "\n";
    return 0;
}