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

int main() {
    bool found = false;
    for(ll d = 1; !found ; ++d) {
        for(ll n = 1; d*(3*d-1)/2 >= 1+3*n; ++n) {
            auto c1 = is_pentagonal(n*(3*n-1)/2+d*(3*d-1)/2);
            auto c2 = is_pentagonal(n*(3*n-1)+d*(3*d-1)/2);
            if(c1 && c2) {
                cout << d*(3*d-1)/2 << endl;
                found = true;
                break;
            }
        }
    }
    return 0;
}