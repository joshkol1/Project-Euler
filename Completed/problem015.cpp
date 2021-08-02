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
    int rows, cols;
    cin >> rows >> cols;
    ll ans = 1;
    if(rows < cols)
        swap(rows, cols);
    for(int i = 1; i <= cols; ++i) {
        ans = ans*(rows+i)/i;
    }
    cout << ans << endl;
    return 0;
}