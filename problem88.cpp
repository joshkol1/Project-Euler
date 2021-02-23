#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

/*
    MAX: largest value of k we consider
*/
const int MAX = 12000;
const int INF = 1E9;
vector<int> factors;
/*
    smallest_f[i]: smallest number that's product-sum of i terms
*/
int smallest_f[MAX+1];
vector<int> used_terms;
int current_p = 1;
int cum_sum = 0;

bool prime(int n) {
    if(n == 1) return true;
    for(int i = 2; i*i <= n; i++) {
        if(n%i == 0) return false;
    }
    return true;
}

/* 
    Generate all factors of n besides 1 and itself. Put into "factors".
*/
void gen_factors(int n) {
    factors.clear();
    for(int i = 2; i*i <= n; i++) {
        if(n%i == 0) {
            factors.pb(i);
            if(i*i != n) factors.pb(n/i);
        }
    }
    sort(factors.begin(), factors.end());
}

/* 
    Find all #'s of terms that n can be written as a product-sum.
    Update smallest_f[# terms] if n is smaller than curret val
    Basically, use DFS with backtracking and only use elements
    that are >= other values we've used.
*/
void search(int n, int min_ind) {
    /*
        Product is n ---> sum up factors used, make the other values
        1's. 
    */
    if(current_p == n) {
        int n_terms = (n-cum_sum) + used_terms.size();
        if(n_terms <= MAX) {
            smallest_f[n_terms] = min(smallest_f[n_terms], n);
        }
        return;
    }
    for(size_t i = min_ind; i < factors.size(); i++) {
        int f = factors.at(i);
        if(f > n/current_p) break;
        current_p *= f;
        cum_sum += f;
        used_terms.pb(f);
        search(n, i);
        used_terms.pop_back();
        cum_sum -= f;
        current_p /= f;
    }
}

int main() {
    for(int i = 0; i <= MAX; i++) smallest_f[i] = INF;
    for(int i = 4; i <= 2*MAX; i++) {
        if(!prime(i)) {
            gen_factors(i); 
            search(i, 0);
        }
    }
    set<int> unique_vals;
    for(int i = 2; i <= MAX; i++) {
        unique_vals.insert(smallest_f[i]);
    }
    ll ans = 0;
    for(int v : unique_vals) ans += v;
    cout << ans << "\n";
    return 0;
}