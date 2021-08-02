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
    (void)!freopen("../problem_inputs/p013_numbers.txt", "r", stdin);
    string n;
    vector<string> nums;
    while(cin >> n)
        nums.pb(n);
    int carry = 0;
    string ans = "";
    for(size_t i = nums[0].length(); i-- > 0; ) {
        int tot = carry;
        for(auto& num : nums)
            tot += (num[i]-'0');
        ans += to_string(tot%10);
        carry = tot/10;
    }
    reverse(ans.begin(), ans.end());
    ans = to_string(carry) + ans;
    cout << ans.substr(0, 10) << endl;
    return 0;
}