#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

vector<ll> fib_nums;

int main() {
    ll a = 1;
    ll b = 2;
    fib_nums.pb(a);
    while(b < 1E17L) {
        fib_nums.pb(b);
        ll c = a+b; a = b; b = c;
    }
    for(ll f : fib_nums) cout << f << "\n";
    int n_fib = fib_nums.size();
    ll tot = 0;
    for(int i = n_fib-2; i >= 0; i -= 2) {
        tot += fib_nums[i];
    }
    cout << tot << "\n";
    return 0;
}