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

vector<pair<ll, ll>> get_pell_solutions(pair<ll, ll>& initial_solution, size_t n_terms, ll n) {
    vector<pair<ll, ll>> solutions;
    solutions.pb(initial_solution);
    for(size_t i = 1; solutions.size() < n_terms; ++i) {
        auto x1 = solutions[0].first;
        auto y1 = solutions[0].second;
        auto x = solutions[i-1].first;
        auto y = solutions[i-1].second;
        auto new_x = x*x1*x1+n*x*y1*y1+2*n*y*y1*x1;
        auto new_y = y*x1*x1+n*y*y1*y1+2*x*y1*x1;
        solutions.emplace_back(new_x, new_y);
    }
    return solutions;
}

int main() {
    pair<ll, ll> initial_solution = {1, 1};
    auto solutions = get_pell_solutions(initial_solution, 20, 2);
    for(auto& p : solutions) {
        auto k = p.first;
        auto b = (2+(ll)(sqrt(2)*k))/4;
        auto tot = (1+(ll)(sqrt(8)*b-1))/2;
        if(tot > 1E12) {
            cout << b << endl;
            break;
        }
    }
    return 0;
}