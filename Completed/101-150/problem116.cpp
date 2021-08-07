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
    auto dp1 = vector<size_t>(51, 0);
    auto dp2 = vector<size_t>(51, 0);
    auto dp3 = vector<size_t>(51, 0);
    dp1[0] = dp1[1] = 1;
    dp2[0] = dp2[1] = dp2[2] = 1;
    dp3[0] = dp3[1] = dp3[2] = dp3[3] = 1;
    for(size_t i = 2; i <= 50; ++i) {
        dp1[i] = dp1[i-1]+dp1[i-2];
        if(i >= 3)
            dp2[i] = dp2[i-1]+dp2[i-3];
        if(i >= 4)
            dp3[i] = dp3[i-1]+dp3[i-4];
    }
    cout << dp1[50]+dp2[50]+dp3[50]-3 << endl;
    return 0;
}