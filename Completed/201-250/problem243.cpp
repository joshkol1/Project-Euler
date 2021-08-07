#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const ll MAX = 6469693230LL;
ll primes[9] = {2,3,5,7,11,13,17,19,23};
ll curr = 1;
ll best = MAX;

void search(int depth) {
    if(depth >= 9) {
        ll tot = curr;
        for(int i = 0; i < 9; i++) {
            if(curr%primes[i] == 0) {
                tot = tot/primes[i]*(primes[i]-1);
            }
        }
        if(tot*94744 < 15499*(curr-1)) {
            best = min(best, curr);
        }
        return;
    }
    ll c_pow = 1;
    for(int i = 0; c_pow*curr < MAX; i++) {
        curr *= c_pow;
        search(depth+1);
        curr /= c_pow;
        c_pow *= primes[depth];
    }
}

int main() {
    search(0);
    cout << best << "\n";
    return 0;
}