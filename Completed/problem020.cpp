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
    vector<int> digits;
    digits.pb(1);
    for(int i = 2; i <= 100; ++i) {
        int carry = 0;
        for(size_t j = 0; j < digits.size(); ++j) {
            auto val = digits[j]*i+carry;
            carry = val/10;
            digits[j] = val%10;
        }
        while(carry > 0) {
            digits.pb(carry%10);
            carry /= 10;
        }
    }
    cout << accumulate(digits.begin(), digits.end(), 0) << endl;
    return 0;
}