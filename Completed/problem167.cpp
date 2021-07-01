#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

vector<int> terms;
set<int> seen;
int other_even;
size_t start_index;
vector<int> diffs;

// Since some periods are smaller we can get away with computing less terms.
// Only compute # terms up to period_size*2
const auto search_sizes = std::array<size_t, 10>{
    100, 500, 2000, 10000, 50000, 100000, 500000, 1000000, 5000000, 10000000
};
const ll K = 1E11;

/*
    https://mathworld.wolfram.com/UlamSequence.html

    From link, ulam sequence (2, v) with v odd and v >= 5 has exactly two even terms
    Furthermore, the sequence of successive differences is periodic

    We can use that info to generate a bunch of terms. Then, try to find the period
    of the successive differences. The differences will start with n-1 2's at the beginning,
    so we need to search for periods at least length n.

    Once we do this we can use the successive differences to calculate the 10^11th term 
    since they are periodic
*/

/*
    Compute the next term in the Ulam sequence
*/
void add_term() {
    if(!other_even) {
        int smallest_sum = 1E9;
        for(size_t i = 0; i < terms.size(); ++i) {
            for(size_t j = i+1; j < terms.size(); ++j) {
                int sum = terms[i] + terms[j];
                if(sum > smallest_sum || sum <= *seen.rbegin()) 
                    continue;
                bool good = true;
                for(size_t k = 0; k < terms.size(); ++k) {
                    if(k == i || k == j) continue;
                    if(seen.count(sum-terms[k])) {
                        good = false; break;
                    }
                }
                if(good) smallest_sum = sum;
            }
        } 
        if(!(smallest_sum&1)) {
            other_even = smallest_sum;
            start_index = terms.size() + 1;
        }
        terms.pb(smallest_sum);
        seen.insert(smallest_sum);
    } else {
        int candidate;
        if(!(*seen.rbegin() & 1)) {
            candidate = *next(seen.rbegin()) + 2;
        } else {
            candidate = *seen.rbegin() + 2;
        }
        if(seen.count(candidate-other_even)) {
            auto ub_iter = seen.upper_bound(candidate - other_even);
            if(*ub_iter == other_even)
                ub_iter = next(ub_iter);
            seen.insert(*ub_iter + other_even);
            terms.pb(*ub_iter + other_even);
        } else {
            seen.insert(candidate);
            terms.pb(candidate);
        }
        size_t end_index = terms.size() - 1;
        int diff = terms[end_index]-terms[end_index-1];
        if(!(diff&1)) 
            diffs.pb(diff);
    }
}

/*
    If a period is found, return it for current Ulam sequence.
    Otherwise, return 0
*/
size_t period(int n, size_t search_terms) {
    for(size_t p = n; p <= search_terms/2; ++p) {
        bool good = true;
        for(size_t i = 0; i < p; ++i) {
            if(diffs[i] != diffs[i+p]) {
                good = false; break;
            }
        }
        if(good) 
            return p;
    }
    return 0u;
}

int main() {
    ll answer = 0;
    for(int n = 2; n <= 10; ++n) {
        terms.clear(); seen.clear(); diffs.clear(); other_even = 0; start_index = 0;
        terms.pb(2); terms.pb(2*n+1);
        seen.insert(2); seen.insert(2*n+1);
        for(size_t i = 0; i < search_sizes.size(); ++i) {
            while(diffs.size() < search_sizes[i])
                add_term();
            auto per = period(n, search_sizes[i]);
            if(per != 0) {
                ll period_sum = 0;
                ll remainder_sum = 0;
                size_t n_diffs = K - (start_index+1);
                size_t p_remainder = n_diffs%per;
                for(size_t j = 0; j < per; ++j) {
                    period_sum += diffs[j];
                    if(j == p_remainder - 1) {
                        remainder_sum = period_sum;
                    }
                }
                answer += remainder_sum + (n_diffs/per)*period_sum + terms[start_index];
                break;
            }
        }
    }
    cout << answer << "\n";
    return 0;
}