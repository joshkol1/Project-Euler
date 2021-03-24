#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int MAX = 120000;
int spf[MAX+1];
ll rad[MAX+1];
set<int> pf;
ll c_total;

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

void init_rad() {
    rad[1] = 1;
    for(int i = 2; i <= MAX; i++) {
        int i_copy = i;
        int prod = 1;
        while(i_copy != 1) {
            int p = spf[i_copy];
            prod *= p;
            while(i_copy%p == 0) i_copy /= p;
        }
        rad[i] = prod;
    }
}

int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b%a, a);
}

void process(int c) {
    int inc = (c%2) ? 1 : 2;
    int remain = c/rad[c];
    for(int a = 1; a < c/2; a += inc) {
        if(rad[a]*rad[c-a] >= remain) continue;
        if(gcd(a, c-a) == 1) c_total += c;
    }
}

int main() {
    init_sieve();
    init_rad();
    for(int c = 4; c < MAX; c++) {
        if(rad[c] == c) continue;
        process(c);
    }
    cout << c_total << "\n";
    return 0;
}