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

/*
    See https://en.wikipedia.org/wiki/Pell%27s_equation (generalized pell equation)
*/

vector<pair<ll, ll>> get_pell_solutions(pair<ll, ll>& initial, pair<ll, ll>& multiplier, size_t n_terms, ll n) {
    vector<pair<ll, ll>> solutions;
    solutions.pb(initial);
    auto a = multiplier.first;
    auto b = multiplier.second;
    for(size_t i = 1; i < n_terms; ++i) {
        auto x = solutions[i-1].first;
        auto y = solutions[i-1].second;
        solutions.emplace_back(a*x+b*y*n, a*y+b*x);
    }
    return solutions;
}

int main() {
    vector<pair<ll, ll>> initial = {{7, 1}, {8, 2}, {13, 5}, {17, 7}};
    vector<pair<ll, ll>> multiplier = {{9, 4}, {9, -4}};
    set<ll> nuggets;
    for(auto& i : initial) {
        for(auto& m : multiplier) {
            auto solutions = get_pell_solutions(i, m, 15, 5);
            for(auto& p : solutions) {
                auto k = abs(p.second);
                ll rad = (k < 1000) ? (ll)sqrt(44+5*k*k) : (ll)(round(sqrt(5.0L)*k));
                if(rad%5 == 2 && rad > 7) {
                    nuggets.insert((rad-7)/5);
                }
            }
        }
    }
    auto it = nuggets.begin();
    ll ans = 0;
    for(size_t i = 0; i < 30; ++i) {
        ans += *it;
        ++it;
    }
    cout << ans << endl;
    return 0;
}
