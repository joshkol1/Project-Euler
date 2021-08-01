#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
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

int main() {
    ll val = 600851475143;
    ll ans = 0;
    for(ll i = 2; i*i <= val; ++i) {
        if(val%i == 0) {
            ans = val;
            while(val%i == 0)
                val /= i;
        }
    }
    if(val > 1)
        ans = val;
    cout << ans << endl;
    return 0;
}