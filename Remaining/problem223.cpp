#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<array>
#include<math.h>
#include<assert.h>
using namespace std;
typedef long long ll;
#define pb push_back

int main() {
    ll max_perim;
    ll ans = 0;
    cin >> max_perim;
    for(ll a = 2; a <= max_perim/3; ++a) {
        if(a%10000 == 0)
            cout << a << "\n";
        ll product = a*a-1;
        ll x_ub = sqrt(2*a*a-1)-a;
        ll x_lb = max(product/(max_perim-a), 1LL);
        for(ll x = x_ub; x >= x_lb; --x) {
            if(product%x != 0)
                continue;
            ll y = product/x;
            if((x+y)%2 != 0)
                continue;
            ++ans;
        }
    }
    cout << ans << "\n";
    return 0;
}