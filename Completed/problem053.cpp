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
    int ans = 0;
    for(ll n = 1; n <= 100; ++n) {
        ll choose = 1;
        for(ll r = 1; r <= n/2; ++r) {
            choose = choose*(n-r+1)/r;
            if(choose > 1000000) {
                ans += (n-2*r+1);
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}