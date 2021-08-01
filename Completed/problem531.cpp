#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<array>
#include<assert.h>
#include<cstring>
#include<math.h>
#include<climits>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back

size_t M;
size_t N;
size_t* spf;
size_t* totient;

ll gcd(ll a, ll b) {
    return (a == 0) ? b : gcd(b%a, a);
}

ll mod_inv(ll b, ll m) {
    ll e = totient[m]-1;
    b %= m;
    ll ret = 1;
    while(e > 0) {
        if(e&1) ret = ret*b%m;
        b = b*b%m;
        e >>= 1;
    }
    return ret;
}

// Initialize smallest prime factor & totient array
void init() {
    spf = new size_t[N+1];
    for(size_t i = 1; i <= N; ++i) {
        if(i%2 == 0)    
            spf[i] = 2;
        else
            spf[i] = i;
    }
    for(size_t i = 2; i*i <= N; ++i) {
        if(spf[i] == i) {
            for(size_t j = i*i; j <= N; j += i) 
                spf[j] = i;
        }
    }
    totient = new size_t[N+1];
    totient[1] = 1;
    for(size_t i = 2; i <= N; ++i) {
        size_t i_copy = i;
        size_t tot = i;
        while(i_copy != 1) {
            auto p = spf[i_copy];
            tot = tot/p*(p-1);
            while(i_copy%p == 0)
                i_copy /= p;
        }
        totient[i] = tot;
    }
}

/*
    Given integers a and b, return gcd(a, b) and find x, y such that
    a*x+b*y=gcd(a, b)
*/
ll extended_euclidean(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    int d = extended_euclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

/*
    Find solution x to x = a (mod n) and x = b (mod m)
*/
ll crt(ll a, ll n, ll b, ll m) {
    ll g = gcd(n, m);
    if((a-b)%g != 0)
        return 0; // No solution
    ll lcm = m/g*n;
    ll c, d;
    extended_euclidean(n, m, c, d);
    ll x = ((d*a*m+c*b*n)/g)%lcm;
    if(x < 0)
        x += lcm;
    return (ll)x;
}

int main() {
    cin >> M >> N;
    init();
    ll ans = 0;
    for(size_t i = M; i < N; ++i) {
        for(size_t j = i+1; j < N; ++j)
            ans += crt(totient[i], i, totient[j], j);
    }
    delete[] spf;
    delete[] totient;
    cout << ans << endl;
    return 0;
}