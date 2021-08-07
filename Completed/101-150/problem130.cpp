#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int MAX = 1E8;
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
    int comp_count = 0;
    ll answer = 0;
    for(int n = 3; n <= MAX && comp_count < 25; n++) {
        if(n%2 == 0 || n%5 == 0) continue;
        if(spf[n] == n) continue;
        if((n-1)%order(10, 9*n) == 0) {
            answer += n; comp_count++;
        }
    }
    cout << answer << "\n";
    return 0;
}