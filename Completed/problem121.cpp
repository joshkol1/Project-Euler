#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

vector<ll> poly;
const int turns = 15;

void mult(ll r) {
    poly.pb(0);
    for(int i = poly.size()-2; i >= 0; i--) {
        poly[i+1] += -r*poly[i];
    }
}

int main() {
    poly.pb(1);
    for(ll i = 1; i <= turns; i++) mult(i);
    ll good = 0;
    for(int i = 0; i <= turns/2; i++) {
        good += abs(poly.at(i));
    }
    ll outcomes = 1;
    for(ll i = 2; i <= turns+1; i++) outcomes *= i;
    cout << outcomes/good << "\n";
    return 0;
}