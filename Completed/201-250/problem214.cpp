#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int MAX = 4E7;
int spf[MAX+1];
int chain[MAX+1];

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

int totient(int n) {
    int ans = n;
    while(n != 1) {
        int p = spf[n];
        while(n%p == 0) n /= p;
        ans = ans/p*(p-1);
    }
    return ans;
}

void find_length(int n) {
    int t = totient(n);
    chain[n] = chain[t]+1;
}

int main() {
    init_sieve();
    chain[1] = 1;
    ll ans = 0;
    for(int i = 2; i <= MAX; i++) {
        find_length(i);
        ans += (spf[i] == i && chain[i] == 25)*i;
    }
    cout << ans << "\n";
    return 0;
}