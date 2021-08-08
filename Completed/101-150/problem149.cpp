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
#include<functional>
#include<numeric>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back

vector<vector<ll>> get_table(size_t n, ll MOD) {
    vector<ll> terms;
    vector<vector<ll>> grid;
    for(ll i = 1; i <= n*n; ++i) {
        if(i <= 55) {
            auto new_term = (300007*i*i*i-200003*i+100003)%MOD - 500000;
            terms.pb(new_term);
        } else {
            terms.pb((terms[i-25]+terms[i-56]+1000000)%MOD - 500000);
        }
    }
    for(size_t i = 0; i < n; ++i) {
        vector<ll> new_row;
        for(size_t j = 0; j < n; ++j)
            new_row.pb(terms[n*i+j]);
        grid.pb(new_row);
    }
    return grid;
}

ll kadane(vector<ll>& terms) {
    ll ans = LLONG_MIN;
    ll max_here = 0;
    for(auto n : terms) {
        max_here += n;
        if(ans < max_here)
            ans = max_here;
        if(max_here < 0)
            max_here = 0;
    }
    return ans;
}

int main() {
    size_t grid_size = 2000;
    ll MOD = 1E6;
    auto grid = get_table(grid_size, MOD);
    ll ans = 0;
    for(auto& row : grid)
        ans = max(ans, kadane(row));
    for(size_t i = 0; i < 2000; ++i) {
        vector<ll> col;
        for(auto& r : grid)
            col.pb(r[i]);
        ans = max(ans, kadane(col));
    }
    for(size_t start_col = 0; start_col < grid_size; ++start_col) {
        vector<ll> diag;
        for(size_t row = 0; row < grid_size-start_col; ++row)
            diag.pb(grid[row][start_col+row]);
        ans = max(ans, kadane(diag));
        diag = vector<ll>();
        for(size_t col = start_col; col < grid_size; ++col)
            diag.pb(grid[grid_size-1-(col-start_col)][col]);
        ans = max(ans, kadane(diag));
    }
    for(size_t start_row = 0; start_row < grid_size; ++start_row) {
        vector<ll> diag;
        for(size_t col = 0; col < grid_size-start_row; ++col)
            diag.pb(grid[start_row+col][col]);
        ans = max(ans, kadane(diag));
        diag = vector<ll>();
        for(size_t col = 0; col < start_row; ++col)
            diag.pb(grid[start_row-col][col]);
        ans = max(ans, kadane(diag));
    }
    cout << ans << endl;
    return 0;
}