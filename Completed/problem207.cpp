#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

int main() {
    for(ll x = 2; ; x++) {
        ll m = x*(x-1);
        ll num = log2(x);
        ll den = x-1;
        if(num*12345<den) {
            cout << m << "\n";
            break;
        }
    }
    return 0;
}