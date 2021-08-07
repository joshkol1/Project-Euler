#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
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

bool square(ll n) {
    ll root = sqrt(n);
    return root*root == n;
}

int main() {
    ll ans = 0;
    for(ll k = 1; 6*k+2 <= 1E9; ++k) {
        auto cand = 3*k*k+2*k;
        if(square(cand))
            ans += 6*k+4;
        cand += 2*k+1;
        if(square(cand))
            ans += 6*k+2;
    }
    cout << ans << endl;
    return 0;
}