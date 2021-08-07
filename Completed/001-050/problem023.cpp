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
    vector<bool> abundant(28124, false);
    vector<int> abundant_list;
    for(int n = 1; n <= 28123; ++n) {
        int div_sum = 1;
        for(int i = 2; i*i <= n; ++i) {
            if(n%i == 0) {
                div_sum += i;
                if(i*i != n)
                    div_sum += (n/i);
            }
        }
        abundant[n] = (div_sum > n);
        if(abundant[n])
            abundant_list.pb(n);
    }
    int ans = 0;
    for(int n = 1; n <= 28123; ++n) {
        bool can_write = false;
        for(auto d : abundant_list) {
            if(d > n)
                break;
            if(abundant[n-d]) {
                can_write = true;
                break;
            }
        }
        if(!can_write)
            ans += n;
    }
    cout << ans << endl;
    return 0;
}