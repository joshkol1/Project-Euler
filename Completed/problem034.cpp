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
    vector<int> factorial = {1, 1};
    for(int i = 2; i <= 9; ++i)
        factorial.pb(factorial[i-1]*i);
    // Maximum of 7 digits by induction
    int ans = 0;
    for(int n = 10; n < 10000000; ++n) {
        int s = 0;
        int n_copy = n;
        while(n_copy != 0) {
            s += factorial[n_copy%10];
            n_copy /= 10;
        }
        if(s == n)
            ans += n;
    }
    cout << ans << endl;
    return 0;
}