#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

/*
    If starting cuboid has dimensions b*w*h (height of h), then # of cubes on layer k
    where k >= 1 is 2*(bw+wh+bh+2(k-1)(h+b+w+k-2))
    we need n = 2*(bw+wh+bh+2(k-1)(h+b+w+k-2)) to have 1000 solutions in positive integers
    (h, b, w, k)
*/

ll n_solutions(ll n) {
    ll ans = 0;
    if(n%2)
        return 0;
    for(ll b = 1; b < n/2; ++b) {
        for(ll w = b; w <= (n/2)/b; ++w) {
            for(ll h = w; b*w + w*h + b*h <= n/2; ++h) {
                ll pairwise = b*w + w*h + b*h;
                ll sum = b + w + h;
                for(ll k = 1; ; ++k) {
                    ll cubes = 2*(pairwise + 2*(k-1)*(sum + k - 2));
                    if(cubes > n)
                        break;
                    if(cubes == n) {
                        ++ans;
                        break;
                    }
                }
            }
        }
    }
    return ans;
}

int main() {
    for(ll i = 154; i <= 50000; ++i) {
        ll sols = n_solutions(i);
        if(sols == 1000) {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}