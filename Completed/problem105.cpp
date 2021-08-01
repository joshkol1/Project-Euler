#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

vector<int> values;
set<int> sums;
int prob_ans;

void process() {
    sort(values.begin(), values.end());
    int n_vals = values.size();
    int all_sum = 0;
    for(int v : values) all_sum += v;
    /*
        Ensure if |B| > |C|, then S(B) > S(C)
    */
    int pref_sum = values[0];
    int suf_sum = 0;
    for(int i = 1; i < n_vals; i++) {
        pref_sum += values[i];
        suf_sum += values[n_vals-i];
        if(pref_sum < suf_sum) return;
    }
    /*
        Check that subset sums are distinct
    */
    for(int i = 1; i < 1<<n_vals; i++) {
        int subset_sum = 0;
        for(int j = 0; j < n_vals; j++) {
            if(i&(1<<j)) subset_sum += values[j];
        }
        if(sums.count(subset_sum) > 0) return;
        sums.insert(subset_sum);
    }
    prob_ans += all_sum;
}

int main() {
    freopen("../problem_inputs/p105_sets.txt", "r", stdin);
    for(int i = 0; i < 100; i++) {
        values.clear();
        sums.clear();
        string line; cin >> line;
        stringstream s_stream(line);
        while(s_stream.good()) {
            string v; getline(s_stream, v, ',');
            values.pb(stoi(v));
        }
        process();
    }
    cout << prob_ans << "\n";
    return 0;
}