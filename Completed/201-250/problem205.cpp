#include<iostream>
#include<iomanip>
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

void get_four_ways(vector<ll>& four_ways, ll tot, size_t index) {
    if(index >= 9) {
        ++four_ways[tot];
        return;
    }
    for(int i = 1; i <= 4; ++i)
        get_four_ways(four_ways, tot+i, index+1);
}

void get_six_ways(vector<ll>& six_ways, ll tot, size_t index) {
    if(index >= 6) {
        ++six_ways[tot];
        return;
    }
    for(int i = 1; i <= 6; ++i)
        get_six_ways(six_ways, tot+i, index+1);
}

int main() {
    auto four_ways = vector<ll>(37, 0);
    auto six_ways = vector<ll>(37, 0);
    get_four_ways(four_ways, 0, 0);
    get_six_ways(six_ways, 0, 0);
    ll four_outcomes = accumulate(four_ways.begin(), four_ways.end(), 0LL);
    ll six_outcomes = accumulate(six_ways.begin(), six_ways.end(), 0LL);
    ll total_outcomes = four_outcomes*six_outcomes;
    ll good_outcomes = 0;
    for(ll i = 7; i <= 36; ++i) {
        for(ll j = 6; j < i; ++j) {
            good_outcomes += four_ways[i]*six_ways[j];
        }
    }
    cout << setprecision(7) << (good_outcomes+0.0)/total_outcomes << endl;
    return 0;
}