#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back

const ld eps = 1e-10;
ll ten_pow[19];
int n_found;
ll ans;

bool square(ll n) {
    double rt = sqrt(n);
    return abs(rt-round(rt)) < eps;
}

/*
    How many ways can n be expressed as a sum of a cube
    and a square?
*/
int ways(ll n) {
    int ans = 0;
    for(ll i = 1; i*i*i <= n; i++) {
        ll rem = n-i*i*i;
        ans += square(rem);
    }
    return ans;
}

void test_palindromes(int n_digits) {
    ll ub = ten_pow[(n_digits+1)/2];
    for(ll i = 1; i < ub; i++) {
        if(n_found >= 5) return;
        ll pal = i;
        if(i%10 == 0) continue;
        for(int j = 0; j < n_digits/2; j++) {
            pal += ten_pow[n_digits-j-1]*(i/ten_pow[j]%10);
        }
        if(ways(pal) == 4) {
            ans += pal; n_found++;
        }
    }
}

int main() {
    ll t_pow = 1;
    for(int i = 0; i < 19; i++) {
        ten_pow[i] = t_pow; t_pow *= 10;
    }
    for(int i = 1; i <= 10; i++) {
        test_palindromes(i);
    }
    cout << ans << "\n";
    return 0;
}