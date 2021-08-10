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
    vector<pair<ll, ll>> initial = {{1, 1}, {4, 2}};
    vector<pair<ll, ll>> multiplier = {{9, 4}, {9, -4}};
    set<ll> nuggets = {2};
    for(auto& i : initial) {
        for(auto& m : multiplier) {
            auto solutions = get_pell_solutions(i, m, 15, 5);
            for(auto& p : solutions) {
                auto k = p.second;
                auto rad = (ll)(sqrt(5)*k);
                if(rad%5 == 1) {
                    nuggets.insert((rad-1)/5);
                }
            }
        }
    }
    auto it = nuggets.begin();
    for(size_t i = 0; i < 14; ++i)
        ++it;
    cout << *it << endl;
    return 0;
}