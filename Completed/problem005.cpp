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

ll gcd(ll a, ll b) {
    return (a == 0) ? b : gcd(b%a, a);
}

int main() {
    ll ans = 1;
    for(int i = 1; i <= 20; ++i) 
        ans = ans/gcd(ans, i)*i;
    cout << ans << endl;
    return 0;
}