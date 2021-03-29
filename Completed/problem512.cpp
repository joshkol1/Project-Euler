#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int MAX_NUM = 250000000;
int spf[MAX_NUM];

/*
    Since we only care about odd numbers,
    have index i map to 2*i+1
*/
void init_sieve() {
    for(int i = 1; i < MAX_NUM; i++) {
        spf[i] = 2*i+1;
    }
    for(int i = 1; (2*i+1)*(2*i+1) < MAX_NUM*2; i++) {
        int n = 2*i+1;
        if(spf[i] == n) {
            int index = (n*n-1)/2;
            for(int j = index; j < MAX_NUM; j += n) {
                if(spf[j] == 2*j+1) {
                    spf[j] = n;
                }
            }
        }
    }
}

int main() {
    init_sieve();
    ll ans = 1;
    for(int n = 3; n < 2*MAX_NUM; n += 2) {
        int totient = n;
        int n_copy = n;
        while(n_copy != 1) {
            int p = spf[(n_copy-1)/2];
            totient = totient/p*(p-1);
            while(n_copy%p == 0) n_copy /= p;
        }
        ans += totient;
    }
    cout << ans << "\n";
    return 0;
}