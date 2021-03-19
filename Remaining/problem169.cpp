#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t bigint;
#define pb push_back

/*
    This is brute force, but too slow. 
    TODO: solve for recurrence relation?
*/

int ways;

void search(bigint v, int t_exp) {
    if(v == 0) {
        ways++; return;
    }
    bigint one = 1;
    if(v > (one<<(t_exp+2))-2) return;
    bigint two_pow = one<<t_exp;
    for(int i = 0; i <= 2; i++) {
        if(v >= two_pow*i) {
            search(v-two_pow*i, t_exp-1);
        }
    }
}

void print_bigint(bigint n) {
    string ans = "";
    while(n > 0) {
        ans += (char)(n%10+'0');
        n /= 10;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}

int main() {
    bigint n = 1;
    int ten_pow; cin >> ten_pow;
    for(int i = 0; i < ten_pow; i++) n *= 10;
    int two_exp = 0;
    bigint two_pow = 1;
    for(int i = 0; two_pow <= n; i++) {
        two_exp++;
        two_pow <<= 1;
    }
    two_exp--;
    two_pow >>= 1;
    search(n, two_exp);
    cout << ways << "\n";
    return 0;
}