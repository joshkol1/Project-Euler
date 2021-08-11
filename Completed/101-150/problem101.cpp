#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<array>
#include<assert.h>
#include<string>
#include<math.h>
#include<climits>
#include<utility>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back

ll poly(ll n) {
    ll ans = 0;
    ll term = 1;
    for(ll i = 0; i < 11; ++i) {
        ans += term;
        term *= -n;
    }
    return ans;
}

ll bop_fit(ll k) {
    auto poly_terms = vector<ll>();
    for(ll i = 1; i <= k; ++i)
        poly_terms.pb(poly(i));
    vector<vector<ll>> finite_differences;
    finite_differences.pb(poly_terms);
    size_t index = 0;
    while(finite_differences[index].size() != 1) {
        vector<ll> new_diffs;
        auto prev_row = finite_differences[index];
        for(size_t i = 0; i < prev_row.size()-1; ++i)
            new_diffs.pb(prev_row[i+1]-prev_row[i]);
        finite_differences.pb(new_diffs);
        ++index;
    }
    finite_differences[index].pb(finite_differences[index][0]);
    while(index > 0) {
        auto lt1 = *finite_differences[index].rbegin();
        auto lt2 = *finite_differences[index-1].rbegin();
        finite_differences[index-1].pb(lt1+lt2);
        --index;
    }
    return *finite_differences[0].rbegin();
}

int main() {
    ll ans = 0;
    for(ll k = 1; k <= 10; ++k)
        ans += bop_fit(k);
    cout << ans << endl;
    return 0;
}