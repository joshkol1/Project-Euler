#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int DIGITS = 18;
int counts[10];
ll fact[DIGITS+1];

void init_fact() {
    fact[0] = 1;
    for(int i = 1; i <= DIGITS; i++) {
        fact[i] = fact[i-1]*i;
    }
}

int main() {
    init_fact();
    ll answer = 0;
    int bitmask = 3;
    int good = 0;
    for(int i = 0; i < 1<<20; i++) {
        int n_digits = 0;
        for(int j = 0; j < 10; j++) {
            counts[j] = (i&(bitmask<<(2*j)))>>(2*j);
            n_digits += counts[j];
        }
        if(n_digits != DIGITS) continue;
        ll ways = fact[DIGITS];
        for(int j = 0; j < 10; j++) {
            ways /= fact[counts[j]];
        }
        ways = ways*(DIGITS-counts[0])/DIGITS;
        answer += ways;
    }
    cout << good << "\n";
    cout << answer << "\n";
    return 0;
}