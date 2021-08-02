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
    auto div_sum = vector<int>(10001, 1);
    for(int n = 1; n <= 10000; ++n) {
        for(int i = 2; i*i <= n; ++i) {
            if(n%i == 0) {
                div_sum[n] += i;
                if(i*i != n)
                    div_sum[n] += (n/i);
            }
        }
    }
    int ans = 0;
    for(int n = 2; n <= 10000; ++n) {
        if(div_sum[n] > 10000)
            continue;
        if(n != div_sum[n] && n == div_sum[div_sum[n]])
            ans += (n+div_sum[n]);
    }
    cout << ans/2 << endl;
    return 0;
}