#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t bigint;
#define pb push_back

set<pair<ll, ll>> found_pairs;

int gcd(ll a, ll b) {
    if(a == 0) return b;
    return gcd(b%a, a);
}

int main() {
    for(int n1 = 1; n1*n1 <= 1E8; n1++) {
        for(int m1 = n1+1; m1*m1+n1*n1 <= 1E8; m1++) {
            if(gcd(m1, n1) != 1) continue;
            ll s1 = m1*m1-n1*n1;
            ll s2 = 2*m1*n1;
            ll m = max(s1, s2);
            ll n = min(s1, s2);
            if(gcd(m, n) != 1) continue;
            ll a = m*m-n*n;
            ll b = 2*m*n;
            bigint area = a;
            area = area*b/2;
            if(area%84 == 0) continue;
            if(a > b) swap(a, b);
            found_pairs.insert({a, b});
        }
    }
    cout << found_pairs.size() << "\n";
    return 0;
}