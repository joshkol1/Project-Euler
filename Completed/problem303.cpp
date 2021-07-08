#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t bigint;
#define pb push_back

vector<int> digits;
const size_t max_depth = 20;
bigint current_value;
bigint ten_pows[max_depth];
bigint smallest_multiple[10001];
set<size_t> left_to_process;

void generate(size_t depth) {
    if(left_to_process.size() == 0)
        return;
    if(depth >= max_depth) {
        if(current_value == 0)
            return;
        vector<size_t> to_remove;
        for(auto& v : left_to_process) {
            if(smallest_multiple[v] == 0 && current_value%v == 0) {
                smallest_multiple[v] = current_value;
                to_remove.pb(v);
            }
        }
        for(auto& v : to_remove)
            left_to_process.erase(v);
        return;
    }
    for(int i = 0; i < 3; ++i) {
        digits.pb(i);
        current_value += ten_pows[max_depth-depth-1]*i;
        generate(depth+1);
        current_value -= ten_pows[max_depth-depth-1]*i;
        digits.pop_back();
    }
}

int main() {
    ten_pows[0] = 1;
    for(size_t i = 1; i < max_depth; ++i)
        ten_pows[i] = ten_pows[i-1]*10;
    for(size_t i = 1; i <= 10000; ++i) {
        if(i == 9999)
            continue;
        left_to_process.insert(i);
    }
    generate(0);
    ll tot = 0;
    for(size_t i = 1; i <= 10000; ++i) {
        if(i == 9999) {
            tot += 10002000200020002LL/9;
            continue;
        }
        tot += smallest_multiple[i]/i;
    }
    cout << tot << "\n";
    return 0;
}