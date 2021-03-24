#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int N = 5;
const int DIGITS = 1<<N;
set<int> seen;

bool test(int s) {
    if(__builtin_popcount(s) != DIGITS>>1) return false;
    seen.clear();
    int all_ones = (1<<N)-1;
    for(int i = 0; i < DIGITS-N+1; i++) {
        int gen = ((all_ones<<i)&s)>>i;
        if(seen.count(gen)) return false;
        seen.insert(gen);
    }
    for(int i = 1; i < N; i++) {
        int ones = (1<<i)-1;
        int gen = (s&ones)<<(DIGITS-i);
        if(seen.count(gen)) return false;
        seen.insert(gen);
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll ans = 0;
    for(uint i = 1<<(DIGITS-N-1); i < 1<<(DIGITS-N); i++) {
        if(test(i)) {
            ans += i;
        }
    }
    cout << ans << "\n";
    return 0;
}