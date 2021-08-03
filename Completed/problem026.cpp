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

int cycle_length(int n) {
    vector<int> digits;
    // Map from numerator to index
    map<int, int> nums;
    int num = 1;
    while(num < n)
        num *= 10;
    nums[num] = 1;
    for(int i = 2; ; ++i) {
        num %= n;
        if(num == 0)
            return 0;
        num *= 10;
        if(nums[num]) 
            return i-nums[num];
        nums[num] = i;
    }
    return 0;
}

int main() {
    int max_cycle = 0;
    int max_value = 0;
    for(int n = 2; n < 1000; ++n) {
        int len = cycle_length(n);
        if(len > max_cycle) {
            max_value = n;
            max_cycle = len;
        }
    }
    cout << max_value << endl;
    return 0;
}