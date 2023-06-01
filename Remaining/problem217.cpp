#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<array>
#include<assert.h>
#include<cstring>
#include<math.h>
#include<climits>
#include<numeric>

typedef long long ll;
typedef long double ld;
#define pb push_back

ll MOD;
ll ways_right[25][217];

void init() {
    for(int i = 0; i < 15; ++i) {
        MOD *= 3;
    }
    for(int i = 0; i < 10; ++i) {
        ways_right[1][i] = 1;
    }
    for(int i = 2; i < 25; ++i) {
        for(int j = 0; j <= i*9; ++j) {
            for(int k = 0; k <= std::min(j, 9); ++k) {
                ways_right[i][j] += ways_right[i-1][j-k];
            }
        }
    }
}

ll solve() {
    ll answer = 0;
    for(int i = 1; i < 25; ++i) {
        for(int j = 0; j <= i*9; ++j) {
            std::cout << ways_right[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}

int main() {
    init();
    std::cout << solve() << "\n";
    return 0;
}