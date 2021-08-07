#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

/*
    See formula at https://mathworld.wolfram.com/Squarefree.html
*/

const ll BOUND = 1L<<50;
const int MAX = 1<<25;
int spf[MAX+1];
int mobius[MAX+1];

void init_sieve() {
    for(int i = 1; i <= MAX; i++) {
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

void init_mobius() {
    mobius[1] = 1;
    for(int i = 2; i <= MAX; i++) {
        int i_copy = i;
        int k = 0;
        bool squarefree = true;
        while(i_copy != 1) {
            if(i_copy%(spf[i_copy]*spf[i_copy]) == 0) {
                squarefree = false; break;
            }
            i_copy /= spf[i_copy];
            k++;
        }
        if(squarefree) mobius[i] = (k%2) ? -1 : 1;
    }
}

int main() {
    init_sieve();
    init_mobius();
    ll ans = 0;
    for(ll d = 1; d < MAX; d++) {
        ans += mobius[d]*((BOUND-1)/(d*d));
    }
    cout << ans << "\n";
    return 0;
}