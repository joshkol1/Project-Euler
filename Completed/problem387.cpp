#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<array>
#include<assert.h>
using namespace std;
typedef long long ll;
#define pb push_back

bool prime(ll n) {
    if(n == 1)
        return false;
    if(n == 2)
        return true;
    else if(n%2 == 0)
        return false;
    for(ll i = 3; i*i <= n; i += 2) {
        if(n%i == 0)
            return false;
    }
    return true;
}

int main() {
    ll ans = 0;
    vector<vector<pair<ll, int>>> harshads(14);
    vector<pair<ll, int>> single_digits(9);
    for(size_t i = 0; i < 9; ++i)
        single_digits[i] = {i+1, i+1};
    harshads[1] = single_digits;
    for(size_t digits = 2; digits <= 13; ++digits) {
        vector<pair<ll, int>> new_harshads;
        for(auto& n : harshads[digits-1]) {
            for(ll i = 0; i < 10; ++i) {
                if((n.first*10+i)%(n.second+i) == 0) {
                    new_harshads.pb({n.first*10+i, n.second+i});
                }
            }
        }
        harshads[digits] = new_harshads;
    }
    vector<ll> strong_harshads;
    for(size_t i = 2; i <= 13; ++i) {
        for(auto& n : harshads[i]) {
            if(prime(n.first/n.second))
                strong_harshads.pb(n.first);
        }
    }
    for(auto& n : strong_harshads) {
        ans += (10*n+1)*prime(10*n+1);
        ans += (10*n+3)*prime(10*n+3);
        ans += (10*n+7)*prime(10*n+7);
        ans += (10*n+9)*prime(10*n+9);
    }
    cout << ans << "\n";
    return 0;
}