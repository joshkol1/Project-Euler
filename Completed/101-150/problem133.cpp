#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int MAX = 1E5;
int spf[MAX+1];

void init_sieve() {
    for(int i = 2; i <= MAX; i++) {
        if(i%2 == 0) spf[i] = 2;
        else spf[i] = i;
    }
    for(int i = 3; i*i <= MAX; i += 2) {
        if(spf[i] == i) {
            for(int j = i*i; j <= MAX; j += 2*i) {
                if(spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

ll fast_exp(ll b, ll e, ll m) {
    b %= m;
    ll ret = 1;
    while(e > 0) {
        if(e&1) ret = ret*b%m;
        b = b*b%m;
        e >>= 1;
    }
    return ret;
}

int totient(int n) {
    int ans = n;
    while(n != 1) {
        int p = spf[n];
        ans = ans/p*(p-1);
        while(n%p == 0) n /= p;
    }
    return ans;
}

int order(int n, int m) {
    int tot = totient(m);
    int ans = tot;
    for(int i = 2; i*i <= tot; i++) {
        if(tot%i == 0) {
            if(fast_exp(n, i, m) == 1) {
                ans = i;
                break;
            }
            else if(fast_exp(n, tot/i, m) == 1) {
                ans = tot/i;
            }
        }
    }
    return ans;
}

int main() {
    init_sieve();
    ll answer = 10; // Account for 2, 3 and 5
    for(int n = 7; n <= MAX; n += 2) {
        if(spf[n] != n) continue;
        int ord = order(10, n);
        while(ord%2 == 0) ord /= 2;
        while(ord%5 == 0) ord /= 5;
        if(ord != 1) {
            if(n <= 100) cout << n << "\n";
            answer += n;
        }
    }
    cout << answer << "\n";
    return 0;
}