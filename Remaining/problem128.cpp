#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
#include<assert.h>
using namespace std;
typedef long long ll;
#define pb push_back

const size_t max_prime = 1E6;

vector<int> previous;
vector<int> current;
vector<int> nxt;
array<bool, max_prime+1> prime;

void init_sieve() {
    fill(prime.begin(), prime.end(), true);
    prime[1] = false;
    prime[2] = true;
    for(size_t i = 4; i <= max_prime; i += 2)
        prime[i] = false;
    for(size_t i = 3; i*i <= max_prime; i += 2) {
        if(prime[i]) {
            for(size_t j = i*i; j <= max_prime; j += 2*i)
                prime[j] = false;
        }
    }
}

void fill_layers(int current_layer) {
    assert(current_layer >= 3);
    current_layer -= 2;
    previous.clear();
    current.clear();
    nxt.clear();
    int prev_start = 2+3*current_layer*(current_layer-1);
    int current_start = 2+3*current_layer*(current_layer+1);
    int next_start = 2+3*(current_layer+1)*(current_layer+2);
    int bound_above = 2+3*(current_layer+2)*(current_layer+3);
    for(int i = prev_start; i < current_start; ++i)
        previous.pb(i);
    for(int i = current_start; i < next_start; ++i)
        current.pb(i);
    for(int i = next_start; i < bound_above; ++i)
        nxt.pb(i);
}

void search(int n_terms) {
    if(n_terms <= 2) {
        cout << n_terms << "\n";
        return;
    }
    // PD(n) = 3 for n = 1 through 7
    int terms_found = 2;
    int current_layer = 3;
    while(terms_found < n_terms) {
        fill_layers(current_layer);
        size_t prev_pointer = 0;
        size_t next_pointer = 0;
        for(size_t i = 0; i < current.size(); ++i) {
            int pd_count = 0;
            int current_val = current[i];
            if(i == 0) {
                pd_count += prime[current.size()-1];
                int next_second = *next(nxt.begin());
                int next_last = *nxt.rbegin();
                pd_count += prime[next_second-current_val];
                pd_count +=  prime[next_last-current_val];
            } else if(i == current.size()-1) {
                pd_count += prime[current.size()-1];
                
            } else {

            }
            // Check for prime differences with previous layer
            // Check for prime differences with next layer

            if(pd_count == 3) {
                ++terms_found;
                if(terms_found == n_terms) {
                    cout << current[i] << "\n";
                    return;
                }
            }
        }
        ++current_layer;
    }
}

int main() {
    init_sieve();
    int n_terms;
    cin >> n_terms;
    search(n_terms);
    return 0;
}