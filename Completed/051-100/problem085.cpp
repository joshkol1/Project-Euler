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
    int best_diff = 2E6;
    int ans = 0;
    for(int w = 1; w*(w+1)/2 <= 4E6; ++w) {
        for(int h = 1; h*(h+1)*w*(w+1)/4 <= 4E6; ++h) {
            auto rects = h*(h+1)*w*(w+1)/4;
            if(abs(rects-2E6) < best_diff) {
                best_diff = abs(rects-2E6);
                ans = w*h;
            }
        }
    }
    cout << ans << endl;
    return 0;
}