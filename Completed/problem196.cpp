#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

ll S(ll n) {
    ll ans = 0;
    ll window_min = (n-3)*(n-2)/2+1;
    ll window_max = (n+2)*(n+3)/2;
    auto row_starts = new ll[5];
    for(size_t i = 0; i < 5; ++i) {
        ll prod_term = n-3+i;
        row_starts[i] = prod_term*(prod_term+1)/2+1;
    }
    size_t pf_bound = sqrt(window_max);
    
    auto is_prime = new bool[pf_bound+1];
    fill(is_prime, is_prime+pf_bound+1, true);
    is_prime[1] = false;
    vector<ll> factor_primes;
    for(size_t i = 2; i*i <= pf_bound; ++i) {
        if(is_prime[i]) {
            for(size_t j = i*i; j <= pf_bound; j += i)
                is_prime[j] = false;
        }
    }
    for(size_t i = 2; i <= pf_bound; ++i) {
        if(is_prime[i])
            factor_primes.pb(i);
    }

    // segmented_sieve[i]: is i+window_min prime?
    size_t n_values = window_max-window_min+1;
    auto segmented_sieve = new bool[n_values];
    fill(segmented_sieve, segmented_sieve+n_values, true);
    for(auto& p : factor_primes) {
        ll min_multiple = (window_min)/p*p;
        if(window_min%p != 0)
            min_multiple += p;
        for(size_t i = min_multiple-window_min; i < n_values; i += p)
            segmented_sieve[i] = false;
    }

    auto goodLoc = [&] (auto r, auto c) {
        // Row i has i+(n-2) elements
        return c >= 0 && c < r+(n-2);
    };

    size_t mid_begin = row_starts[2]-row_starts[0];
    size_t mid_end = row_starts[3]-row_starts[0];
    // we don't need to check the last term in row, as it is triangular ---> not prime
    for(size_t i = mid_begin; i < mid_end-1; ++i) {
        if(!segmented_sieve[i])
            continue;
        size_t row = 2;
        size_t col = i-mid_begin;
        bool good = false;
        // Test for this one being endpoint
        for(int v_disp = -1; v_disp <= 1; ++v_disp) {
            for(int h_disp = -1; h_disp <= 1; ++h_disp) {
                if(v_disp == 0 && h_disp == 0)
                    continue;
                if(!goodLoc(row+v_disp, col+h_disp))
                    continue;
                ll n2 = row_starts[row+v_disp]+col+h_disp;
                size_t i2 = n2-row_starts[0];
                if(!segmented_sieve[i2])
                    continue;
                for(int vd_2 = -1; vd_2 <= 1; ++vd_2) {
                    for(int hd_2 = -1; hd_2 <= 1; ++hd_2) {
                        if(vd_2 == 0 && hd_2 == 0)
                            continue;
                        if(v_disp+vd_2 == 0 && h_disp+hd_2 == 0)
                            continue;
                        if(!goodLoc(row+v_disp+vd_2, col+h_disp+hd_2))
                            continue;
                        ll n3 = row_starts[row+v_disp+vd_2]+col+h_disp+hd_2;
                        size_t i3 = n3-row_starts[0];
                        if(segmented_sieve[i3])
                            good = true;
                    }
                }
            }
        }
        // Test for this one being middle point
        for(int vd_1 = -1; vd_1 <= 1; vd_1 += 2) {
            for(int hd_1 = -1; hd_1 <= 1; ++hd_1) {
                if(!goodLoc(row+vd_1, col+hd_1))
                    continue;
                ll n1 = row_starts[row+vd_1]+col+hd_1;
                size_t i1 = n1-row_starts[0];
                if(!segmented_sieve[i1])
                    continue;
                for(int vd_2 = -1; vd_2 <= 1; vd_2 += 2) {
                    for(int hd_2 = -1; hd_2 <= 1; ++hd_2) {
                        if(vd_1 == vd_2 && hd_1 == hd_2)
                            continue;
                        if(!goodLoc(row+vd_2, col+hd_2))
                            continue;
                        ll n2 = row_starts[row+vd_2]+col+hd_2;
                        size_t i2 = n2-row_starts[0];
                        if(segmented_sieve[i2]) {
                            good = true;
                        }
                    }
                }
            }
        }
        if(good)
            ans += (window_min+i);
    }
    delete[] is_prime;
    delete[] segmented_sieve;
    return ans;
}

int main() {
    ll n1 = 5678027;
    ll n2 = 7208785;
    cout << S(n1)+S(n2) << "\n";
    return 0;
}