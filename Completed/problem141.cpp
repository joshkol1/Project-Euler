#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const double eps = 1e-9;
const int MAX_M = 1E6;
const ll MAX_PROG = 1E12;

int spf[MAX_M];
vector<int> pf;
vector<int> exps;
set<ll> prog_squares;
ll curr_prod;
ll curr_m;

void init_sieve() {
    for(int i = 2; i < MAX_M; i++) {
        spf[i] = (i%2) ? i : 2;
    }
    for(int i = 3; i*i < MAX_M; i++) {
        if(spf[i] == i) {
            for(int j = i*i; j < MAX_M; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

bool square(ll n) {
    ll n_sqrt = sqrt(n);
    return abs(n_sqrt-sqrt(n)) < eps;
}

/*
    Find prime factorization of m*m and store in 
    exps and pfs
*/
void find_pf(ll m) {
    int index = 0;
    while(m != 1) {
        int p = spf[m];
        pf.pb(p); exps.pb(0);
        while(m%p == 0) {
            exps[index]++; m /= p;
        }
        exps[index] *= 2;
        index++;
    }
}

void search(int depth) {
    int n_pf = pf.size();
    if(depth >= n_pf) {
        ll q = (curr_m*curr_m)/curr_prod;
        ll prog = curr_m*q+curr_prod;
        if(prog >= MAX_PROG) return;
        if(square(prog)) {
            prog_squares.insert(prog);
        }
        return;
    }
    ll p = pf[depth];
    ll p_pow = 1;
    for(int i = 0; i <= exps[depth]; i++) {
        if(curr_prod >= curr_m) break;
        search(depth+1);
        if(i == exps[depth]) break;
        curr_prod *= p;
        p_pow *= p;
    }
    curr_prod /= p_pow;
}

int main() {
    init_sieve();
    for(ll m = 2; m < MAX_M; m++) {
        pf.clear();
        exps.clear();
        curr_m = m;
        find_pf(m);
        curr_prod = 1;
        search(0);
    }
    ll ans = 0;
    for(ll prog : prog_squares) ans += prog;
    cout << ans << "\n";
    return 0;
}