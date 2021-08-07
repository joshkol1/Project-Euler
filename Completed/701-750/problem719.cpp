#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAX = 1E6;
ll ans;
bool seen[MAX+1];

/*
    Just do a brute-force split over the squared value
    and see if any of the final sums equal target.
    Slight optimization: stop search when cumulative
    sum exceeds target.
*/
void search(ll target, ll re, ll cum_sum) {
    if(seen[target]) return;
    if(re == 0) {
        if(cum_sum == target) {
            seen[target] = true;
            ans += target*target;
        }
    }
    if(cum_sum >= target) return;
    ll last_digs = 0;
    ll t_pow = 1;
    while(re != 0) {
        last_digs += (re%10)*t_pow;
        re /= 10; t_pow *= 10;
        search(target, re, cum_sum+last_digs);
    }
}

int main() {
    for(ll i = 2; i <= MAX; i++) {
        search(i, i*i, 0);
    }
    cout << ans << "\n";
    return 0;
}