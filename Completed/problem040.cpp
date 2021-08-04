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

int main() {
    int ans = 1;
    size_t target = 1;
    size_t prev_length = 0;
    size_t curr_length = 0;
    for(size_t n = 1; target <= 1000000; ++n) {
        curr_length += to_string(n).length();
        if(curr_length >= target) {
            ans *= (to_string(n)[target-prev_length-1] - '0');
            target *= 10;
        }
        prev_length = curr_length;
    }
    cout << ans << endl;
    return 0;
}