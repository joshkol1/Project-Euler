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

bool bouncy(int n) {
    auto n_string = to_string(n);
    auto increasing = true;
    auto decreasing = true;
    for(size_t i = 1; i < n_string.length(); ++i) {
        if(n_string[i-1] < n_string[i])
            decreasing = false;
        if(n_string[i-1] > n_string[i])
            increasing = false;
    }
    return !(increasing || decreasing);
}

int main() {
    int non_bouncy = 0;
    for(int n = 1; ; ++n) {
        non_bouncy += !bouncy(n);
        if(non_bouncy*100 == n) {
            cout << n << endl;
            break;
        }
    }
    return 0;
}