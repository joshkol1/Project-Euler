#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

vector<ll> curr_dist;
int curr_sum;
ll t_outcomes;
long double EV;

ll choose(ll n, ll k) {
    ll ans = 1;
    for(ll i = 1; i <= k; i++) {
        ans *= (n-i+1);
        ans /= i;
    }
    return ans;
}

void search(int depth) {
    if(depth == 6) {
        if(20-curr_sum > 10) return;
        curr_dist.pb(20-curr_sum);
        ll outcomes = 1;
        int non_zeros = 0;
        for(int i = 0; i < 7; i++) {
            outcomes *= choose(10, curr_dist[i]);
            if(curr_dist[i] != 0) non_zeros++;
        }
        EV += non_zeros * (outcomes+0.0)/t_outcomes;
        curr_dist.pop_back();
        return;
    }
    for(int i = 0; i <= min(20-curr_sum, 10); i++) {
        curr_sum += i;
        curr_dist.pb(i);
        search(depth+1);
        curr_sum -= i;
        curr_dist.pop_back();
    }
}

int main() {
    t_outcomes = choose(70, 20);
    search(0);
    cout << setprecision(10) << EV << "\n";
    return 0;
}