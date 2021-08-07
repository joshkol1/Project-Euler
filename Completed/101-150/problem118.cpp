#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

int dig[] = {1,2,3,4,5,6,7,8,9};
set<ll> products;
ll cur_prod = 1;

/*
    Cycle through all permutations of digit set. Then,
    do a brute-force search over all "splittings" into
    numbers, making sure to prune when term is not prime

    Key insight: if a pandigital set contains all primes,
    then the product of its elements uniquely identifies
    it.
*/

bool prime(ll n) {
    if(n == 1) return false;
    for(ll i = 2; i*i <= n; i++) {
        if(n%i == 0) return false;
    }
    return true;
}

void search(int ind) {
    if(ind >= 9) {
        products.insert(cur_prod);
        return;
    }
    ll b_val = 0;
    for(int i = ind; i < 9; i++) {
        b_val = b_val*10+dig[i];
        if(prime(b_val)) {
            cur_prod *= b_val;
            search(i+1);
            cur_prod /= b_val;
        }
    }
}

int main() {
    do {
        search(0);
    } while(next_permutation(dig, dig+9));
    cout << products.size() << "\n";
    return 0;
}