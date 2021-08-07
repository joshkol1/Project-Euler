#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int MAX = 1E8;
int spf[MAX+1];
ll ans;

void init_sieve() {
    spf[1] = 1;
    for(int i = 2; i <= MAX; i++) {
        if(i%2 == 0) {
            spf[i] = 2;
        }
        else {
            spf[i] = i;
        }
    }
    for(int i = 3; i*i <= MAX; i++) {
        if(spf[i] == i) {
            for(int j = i*i; j <= MAX; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

/*
    return smallest n such that p^exp | n!
*/
int search(int p, int exp) {
    if(exp == 1) return p;
    if(exp == 2) return 2*p;
    if(p == 2 && exp == 3) return 4;
    if(exp == 3) return 3*p;
    int low = 1;
    int high = p*exp;
    while(low < high) {
        int m = (low+high)/2;
        int m_copy = m;
        int fvp = 0;
        while(m_copy > 0) {
            fvp += m_copy/p; m_copy /= p;
        }
        if(fvp > exp) {
            high = m-1;
        }
        else if(fvp < exp) {
            low = m+1;
        }
        else {
            high = m;
        }
    }
    int ans = min(low, high);
    int ans_copy = ans;
    int fvp = 0;
    while(ans_copy > 0) {
        fvp += ans_copy/p; ans_copy /= p;
    }
    if(fvp >= exp) return ans;
    return ans+1;
}

/*
    Return s(n), the smallest # m s.t. n | m!
*/
int smallest_fact(int n) {
    if(n == 1) return 0;
    int a = 0;
    while (n != 1) {
        int e = 0;
        int p = spf[n];
        while(n%p == 0) {
            e++; n /= p;
        }
        int fact = search(p, e);
        a = max(a, fact);
    }
    return a;
}

int main() {
    init_sieve();
    for(int i = 2; i <= MAX; i++) {
        ans += smallest_fact(i);
    }
    cout << ans << "\n";
    return 0;
}