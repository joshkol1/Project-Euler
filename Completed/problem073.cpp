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

int gcd(int a, int b) {
    return (a == 0) ? b : gcd(b%a, a);
}

int main() {
    // 1/3 < n/d < 1/2, and d <= 12000
    int ans = 0;
    for(int d = 4; d <= 12000; ++d) {
        for(int n = d/3+1; n <= d/2; ++n) {
            if(3*n == d || 2*n == d)
                continue;
            ans += (gcd(n, d) == 1);
        }
    }
    cout << ans << endl;
    return 0;
}