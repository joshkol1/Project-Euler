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

bool right(int x1, int x2, int y1, int y2) {
    if(x1*x2+y1*y2 == x2*x2+y2*y2)
        return true;
    if(x1*x2+y1*y2 == x1*x1+y1*y1)
        return true;
    if(x1*x2+y1*y2 == 0)
        return true;
    return false;
}

int main() {
    int ans = 0;
    for(int x1 = 0; x1 <= 50; ++x1) {
        for(int y1 = 0; y1 <= 50; ++y1) {
            for(int x2 = x1; x2 <= 50; ++x2) {
                for(int y2 = 0; y2 <= 50; ++y2) {
                    if(y1*x2 == y2*x1)
                        continue;
                    if(x1 == x2 && y1 < y2)
                        continue;
                    ans += right(x1, x2, y1, y2);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}