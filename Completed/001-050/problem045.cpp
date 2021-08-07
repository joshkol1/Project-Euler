#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<array>
#include<assert.h>
#include<string>
#include<math.h>
#include<climits>
#include<utility>
#include<functional>
#include<numeric>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back

bool is_pentagonal(ll n) {
    ll root = round(sqrt(1+24*n));
    if(root*root != 1+24*n)
        return false;
    return root%6 == 5;
}

bool is_hexagonal(ll n) {
    ll root = round(sqrt(1+8*n));
    if(root*root != 1+8*n)
        return false;
    return root%4 == 3;
}

int main() {
    for(ll n = 286; ; ++n) {
        ll c = n*(n+1)/2;
        if(is_pentagonal(c) && is_hexagonal(c)) {
            cout << c << endl;
            break;
        }
    }
    return 0;
}