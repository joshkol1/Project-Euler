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

string binary_string(int n) {
    string ans = "";
    while(n) {
        ans += to_string(n&1);
        n >>= 1;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

bool palindrome(string s) {
    string s_copy(s);
    reverse(s_copy.begin(), s_copy.end());
    return s == s_copy;
}

int main() {
    int ans = 0;
    for(int i = 1; i < 1000000; ++i) {
        if(palindrome(to_string(i)) && palindrome(binary_string(i)))
            ans += i;
    }
    cout << ans << endl;
    return 0;
}