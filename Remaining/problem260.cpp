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
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back

bool losing[1001][1001];

int main() {
    // states: (0, j, i) where j <= i
    for(size_t i = 1; i <= 1000; ++i) {
        for(size_t j = 1; j < i; ++j) {
            bool is_losing;
            for(size_t k = 1; k < j; ++k) {
                if(losing[k][i])
                    break;
                losing[j][i] |= (!losing[k][i]);
                if(losing[j][i])
                    break;
            }
            for(size_t k = 1; k < i; ++k) {
                if(k >= j)
                    losing[j][i] |= (!losing[j][k]);
                else
                    losing[j][i] |= (!losing[k][j]);
                if(losing[j][i])
                    break;
            }
            for(size_t k = 1; k < j; ++k) {
                losing[j][i] |= (!losing[k][k+i-j]);
                if(losing[j][i])
                    break;
            }
        }
    }
    for(size_t i = 0; i <= 1000; ++i) {
        for(size_t j = 0; j <= i; ++j) {
            if(!losing[j][i])
                cout << 0 << " " << j << " " << i << endl;
        }
    }
    return 0;
}