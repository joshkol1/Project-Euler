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
    int ans = 0;
    for(int a = 1; a < 10; ++a) {
        for(int n = 1; (n-1)*log(10) <= n*log(a); ++n)
            ++ans;
    }
    cout << ans << endl;
    return 0;
}