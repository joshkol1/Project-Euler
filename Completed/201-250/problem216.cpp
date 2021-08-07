#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 bigint;
#define pb push_back

bigint fast_exp(bigint b, bigint e, bigint m) {
    b %= m;
    bigint ret = 1;
    while(e > 0) {
        if(e&1) ret = ret*b%m;
        b = b*b%m;
        e >>= 1;
    }
    return ret;
}

bool miller_rabin(bigint n, int k=100) {
    bigint n_copy = n-1;
    int r = 0;
    while(!(n_copy&1)) {
        ++r;
        n_copy >>= 1;
    }
    bigint d = n_copy;
    for(int i = 0; i < k; ++i) {
        bigint a = 2 + rand() % (n-4);
        auto x = fast_exp(a, d, n);
        if(x == 1 || x == n-1)
            continue;
        bool good = false;
        for(int j = 0; j < r; ++j) {
            x = (x*x)%n;
            if(x == n-1) {
                good = true;
                break;
            }
        }
        if(!good)
            return false;
    }
    return true;
}

int main() {
    ll N;
    int k;
    cin >> N >> k;
    int ans = 0;
    for(ll i = 2; i <= N; ++i) {
        ans += miller_rabin(2*i*i-1, k);
    }
    cout << ans << "\n";
    return 0;
}