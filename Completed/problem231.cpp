#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int MAX = 2E7;
int N = MAX;
int K = 1.5E7;
int spf[MAX+1];
int vp[MAX+1];
ll ans;

void init_sieve() {
    for(int i = 2; i <= MAX; i++) {
        if(i%2 == 0) spf[i] = 2;
        else spf[i] = i;
    }
    for(int i = 3; i*i <= MAX; i += 2) {
        if(spf[i] == i) {
            for(int j = i*i; j <= MAX; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

void inc(int n) {
    while(n != 1) {
        int p = spf[n];
        while(n%p == 0) {
            vp[p]++; n /= p;
        }
    }
}

void dec(int n) {
    while(n != 1) {
        int p = spf[n];
        while(n%p == 0) {
            vp[p]--; n /= p;
        }
    }
}

void compute() {
    K = min(K, N-K);
    for(int i = 1; i <= K; i++) {
        inc(N-K+i); dec(i);
    }
}

int main() {
    init_sieve();
    compute();
    for(int i = 1; i <= MAX; i++) ans += i*vp[i];
    cout << ans << "\n";
    return 0;
}