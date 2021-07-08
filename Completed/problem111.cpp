#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

ll ten_pows[11];
const int MAX_DIGITS = 10;
vector<int> new_digits;
int best_solution;
set<ll> found_primes;

bool prime(ll n) {
    if(n == 1) return false;
    if(n == 2) return true;
    if(n%2 == 0) return false;
    for(ll i = 3; i*i <= n; i+=2) {
        if(n%i == 0) return false;
    }
    return true;
}

void search(int d, int n_digits, int depth) {
    if(best_solution)
        return;
    if(depth + n_digits >= MAX_DIGITS) {
        vector<int> all_digits;
        for(int i = 0; i < n_digits; ++i)
            all_digits.pb(d);
        for(auto& v : new_digits)
            all_digits.pb(v);
        sort(all_digits.begin(), all_digits.end());
        // Is there a permutation that is prime?
        do {
            ll candidate = 0;
            if(all_digits[0] == 0)
                continue;
            for(int i = 0; i < MAX_DIGITS; ++i)
                candidate += ten_pows[i] * (ll)all_digits[MAX_DIGITS-i-1];
            if(prime(candidate)) {
                best_solution = n_digits;
                break;
            }
        } while(next_permutation(all_digits.begin(), all_digits.end())); 
        return;
    }
    for(int i = 0; (i <= 9) && (!best_solution); ++i) {
        if(i == d)
            continue;
        new_digits.pb(i);
        search(d, n_digits, depth+1);
        new_digits.pop_back();
    }
}

void generate_primes(int d, int depth) {
    if(depth >= MAX_DIGITS-best_solution) {
        vector<int> all_digits;
        for(int i = 0; i < best_solution; ++i)
            all_digits.pb(d);
        for(auto& v : new_digits)
            all_digits.pb(v);
        sort(all_digits.begin(), all_digits.end());
        do {
            ll candidate = 0;
            if(all_digits[0] == 0)
                continue;
            for(int i = 0; i < MAX_DIGITS; ++i)
                candidate += ten_pows[i] * (ll)all_digits[MAX_DIGITS-i-1];
            if(prime(candidate)) {
                found_primes.insert(candidate);
            }
        } while(next_permutation(all_digits.begin(), all_digits.end()));
        return;
    }
    for(int i = 0; i <= 9; ++i) {
        if(i == d)
            continue;
        new_digits.pb(i);
        generate_primes(d, depth+1);
        new_digits.pop_back();
    }
}

int main() {
    ten_pows[0] = 1;
    for(int i = 1; i <= 10; ++i) {
        ten_pows[i] = ten_pows[i-1]*10;
    }
    for(int d = 0; d <= 9; ++d) {
        best_solution = 0;
        for(int n_digits = MAX_DIGITS-1; (n_digits >= 1) && (!best_solution); --n_digits) {
            search(d, n_digits, 0);
        }
        new_digits.clear();
        generate_primes(d, 0);
    }
    cout << accumulate(found_primes.begin(), found_primes.end(), 0L) << "\n";
    return 0;
}