#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t bigint;
#define pb push_back

map<bigint, ll> func;

ll ways(bigint n) {
    if(n <= 1) return 1;
    if(func[n] != 0) return func[n];
    if(n%2 == 1) {
        ll f = ways((n-1)/2);
        func[n] = f;
    }
    else {
        ll f1 = ways(n/2);
        ll f2 = ways(n/2-1);
        func[n] = f1+f2;
    }
    return func[n];
}

int main() {
    bigint val = 1<<25;
    for(int i = 0; i < 25; i++) val *= 5;
    cout << ways(val) << "\n";
    return 0;
}