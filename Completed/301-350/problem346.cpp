#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

set<ll> reps;
ll MAX = 1E12;
ll ans;

int main() {
    reps.insert(1);
    for(ll n = 2; n*n+n+1 < MAX; n++) {
        ll sum = n*n+n+1;
        ll n_pow = n*n*n;
        while(sum < MAX) {
            reps.insert(sum);
            sum += n_pow;
            n_pow *= n;
        }
    }
    for(ll r : reps) ans += r;
    cout << ans << "\n";
    return 0;
}