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
    int rows;
    cin >> rows;
    ll ans = 1;
    ll avg = 1;
    for(int i = 0; i < rows/2; ++i) {
        avg += (5+8*i);
        ans += 4*avg;
    }
    cout << ans << endl;
    return 0;
}