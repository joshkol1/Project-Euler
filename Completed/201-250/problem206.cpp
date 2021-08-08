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
    string compare = "1_2_3_4_5_6_7_8_9_0";
    for(ll n = 1E9; ; n += 10) {
        auto square = to_string(n*n);
        if(square.length() != compare.length())
            continue;
        bool good = true;
        for(size_t i = 0; i < compare.length(); i += 2) {
            if(square[i] != compare[i]) {
                good = false;
                break;
            }    
        }
        if(good) {
            cout << n << endl;
            break;
        }
    }
    return 0;
}