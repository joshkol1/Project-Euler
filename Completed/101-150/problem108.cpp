#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<array>
#include<assert.h>
#include<string>
#include<math.h>
#include<climits>
#include<utility>
#include<functional>
#include<numeric>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back

/*
    1/x+1/y=1/n --> x+y = xy/n --> (x-n)(y-n) = n^2
    So, we need div(n^2) > 1,000
*/

ll best_prod = 1;
vector<ll> primes = {2,3,5,7,11,13,17};
vector<int> exps;
ll curr_prod = 1;

void init() {
    for(ll p : primes) best_prod *= p;
}

void search(int depth) {
    if(depth >= 1 && (depth >= primes.size() || exps[depth-1] == 0)) {
        int n_factors = 1;
        for(int e : exps) n_factors *= (2*e+1);
        n_factors = (n_factors+1)/2;
        if(n_factors > 1000 && curr_prod < best_prod) {
            best_prod = curr_prod;
        }
        return;
    }
    int c_exp = 0;
    ll p_pow = 1;
    int bound;
    if(depth == 0) bound = 100;
    else bound = exps[depth-1];
    while(p_pow*curr_prod < best_prod && c_exp <= bound) {
        curr_prod *= p_pow;
        exps.pb(c_exp);
        search(depth+1);
        curr_prod /= p_pow;
        exps.pop_back();
        p_pow *= primes[depth];
        c_exp++;
    }
}

int main() {
    init();
    search(0);
    cout << best_prod << "\n";
    return 0;
}