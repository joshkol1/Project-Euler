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
    int ans = 0;
    for(int i = 100; i <= 999; ++i) {
        for(int j = 100; j <= 999; ++j) {
            auto prod = to_string(i*j);
            auto rev(prod);
            reverse(rev.begin(), rev.end());
            if(prod == rev)
                ans = max(ans, i*j);
        }
    }
    cout << ans << endl;
    return 0;
}