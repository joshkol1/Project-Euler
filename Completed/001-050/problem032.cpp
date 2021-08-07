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

bool pandigital(int n) {
    for(int i = 1; i*i < n; ++i) {
        if(n%i == 0) {
            auto l1 = to_string(i).length();
            auto l2 = to_string(n/i).length();
            auto l3 = to_string(n).length();
            if(l1+l2+l3 != 9)
                continue;
            set<int> digits;
            auto n1 = i;
            auto n2 = n/i;
            auto n3 = n;
            while(n1 > 0) {
                digits.insert(n1%10);
                n1 /= 10;
            }
            while(n2 > 0) {
                digits.insert(n2%10);
                n2 /= 10;
            }
            while(n3 > 0) {
                digits.insert(n3%10);
                n3 /= 10;
            }
            if(digits.size() != 9)
                continue;
            bool all_digits = true;
            for(int i = 1; i <= 9; ++i) {
                if(!digits.count(i)) {
                    all_digits = false;
                    break;
                }
            }
            if(all_digits)
                return true;
        }
    }
    return false;
}

int main() {
    int ans = 0;
    for(int n = 1; n < 10000; ++n) {
        if(pandigital(n))
            ans += n;
    }
    cout << ans << endl;
    return 0;
}