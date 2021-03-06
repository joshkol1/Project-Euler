#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

long double log_123 = log2l(123);
long double log_124 = log2l(124);
long double log_10 = log2l(10);
int first_n; // This is 90

void g_first_sol() {
    for(int i = 1; ; i++) {
        int k = (i-log_123)/log_10;
        if(log_123+k*log_10 < i && i < log_124+k*log_10) {
            first_n = i;
            return;
        }
    }
}

int main() {
    g_first_sol();
    cout << first_n << "\n";
    return 0;
}