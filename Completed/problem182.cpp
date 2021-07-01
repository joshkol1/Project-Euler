#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int P = 1009;
const int Q = 3643;
const int N = P*Q;
const int PHI = (P-1)*(Q-1);
set<int> phi_factors;
int unc_count[PHI+1];
int exp_gcd[PHI];

int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b%a, a);
}

void init() {
    for(int e = 2; e < PHI; e++) {
        exp_gcd[e] = gcd(e, PHI);
    }
    for(int i = 1; i*i <= PHI; i++) {
        if(PHI%i == 0) {
            phi_factors.insert(i);
            phi_factors.insert(PHI/i);
        }
    }
}

/*
    Return b^e (mod m)
*/
ll fast_exp(ll b, ll e, ll m) {
    b %= m;
    ll ret = 1;
    while(e > 0) {
        if(e&1) ret = ret*b%m;
        b = b*b%m;
        e >>= 1;
    }
    return ret;
}

/*
    Return o(m) mod N
*/
int order(int m) {
    for(int e : phi_factors) {
        if(fast_exp(m, e, N) == 1) {
            return e;
        }
    }
    return -1;
}

void process(int m) {
    if(gcd(m, N) != 1) {
        ll s = m;
        int gap = 0;
        for(int e = 2; e < PHI; e++) {
            s = (s*m)%N;
            if(s == m)  {
                gap = e-1; break;
            }
        }
        for(int e = gap+1; e < PHI; e += gap) {
            unc_count[e]++;
        }
        return;
    }
    int ord = order(m);
    for(int e = ord+1; e < PHI; e += ord) {
        if(exp_gcd[e] != 1) continue;
        unc_count[e]++;
    }
}

int main() {
    init();
    for(int m = 2; m < N; m++) {
        process(m);
    }
    int min_unc = 1E8;
    for(int e = 2; e < PHI; e++) {
        if(exp_gcd[e] != 1) continue;
        min_unc = min(min_unc, unc_count[e]);
    }
    ll ans = 0;
    for(int e = 2; e < PHI; e++) {
        if(exp_gcd[e] != 1) continue;
        if(unc_count[e] == min_unc) {
            ans += e;
        }
    }
    cout << ans << "\n";
    return 0;
}