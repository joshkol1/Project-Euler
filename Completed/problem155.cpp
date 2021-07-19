#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<array>
#include<math.h>
#include<assert.h>
#include<utility>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back

const ld epsilon = 1e-9;

bool ld_cmp(ld a, ld b) {
    if(abs(a-b) < epsilon)
        return false;
    return a < b;
}

// capacitances[i]: all capacitances which can be made with i capacitors
vector<set<ld, decltype(ld_cmp)*>> capacitances;
ld base_capacitance = 1;
ld parallel_capacitance = 0;
ld series_capacitance = 0;

void parallel_search(size_t max_caps, size_t curr_caps, size_t last_caps) {
    assert(max_caps >= curr_caps);
    if(max_caps == curr_caps) {
        capacitances[max_caps].insert(parallel_capacitance);
        return;
    }
    for(size_t i = last_caps; i <= max_caps-max(size_t{1}, curr_caps); ++i) {
        for(auto& f : capacitances[i]) {
            parallel_capacitance += f;
            parallel_search(max_caps, curr_caps+i, i);
            parallel_capacitance -= f;
        }
    }
}

void series_search(size_t max_caps, size_t curr_caps, size_t last_caps) {
    assert(max_caps >= curr_caps);
    if(max_caps == curr_caps) {
        capacitances[max_caps].insert(1/series_capacitance);
        return;
    }
    for(size_t i = last_caps; i <= max_caps-max(size_t{1}, curr_caps); ++i) {
        for(auto& f : capacitances[i]) {
            series_capacitance += 1/f;
            series_search(max_caps, curr_caps+i, i);
            series_capacitance -= 1/f;
        }
    }
}

void enumerate(size_t n_caps) {
    if(n_caps == 1) {
        capacitances[n_caps].insert(base_capacitance);
        return;
    }
    // Case 1 : subcircuits are all in series
    series_search(n_caps, 0, 1);
    // Else at least two parallel subcircuits, search for those
    parallel_search(n_caps, 0, 1);
}

int main() {
    size_t N;
    cin >> N;
    capacitances = vector<set<ld, decltype(ld_cmp)*>>(N+1);
    for(size_t i = 0; i <= N; ++i) {
        set<ld, decltype(ld_cmp)*> s(ld_cmp);
        capacitances[i] = s;
    }
    set<ld, decltype(ld_cmp)*> cap_set(ld_cmp);
    for(size_t i = 1; i <= N; ++i) {
        enumerate(i);
        for(auto& d : capacitances[i])
            cap_set.insert(d);
    }
    cout << cap_set.size() << "\n";
    return 0;
}