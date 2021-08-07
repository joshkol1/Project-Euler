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

/* 
    Non-bouncy: increasing or decreasing. Up to 100 digits
    100 slots, 10 numbers --> 109C9
    # is increasing & decreasing --> all digits are equal. 
*/

size_t choose(size_t n, size_t k) {
    k = min(k, n-k);
    size_t ans = 1;
    for(size_t i = 1; i <= k; ++i)
        ans = ans*(n-k+i)/i;
    return ans;
}

size_t n_increasing(size_t n_digits) {
    return choose(n_digits+9, 9)-1;
}

size_t n_decreasing(size_t n_digits) {
    return choose(n_digits+9, 9)-1;
}

int main() {
    auto ans = n_increasing(100);
    for(size_t i = 1; i <= 100; ++i)
        ans += n_decreasing(i);
    ans -= 900;
    cout << ans << endl;
    return 0;
}