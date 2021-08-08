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
    for(int a = 3; a <= 1000; ++a) {
        if(a%2 == 0)
            ans += (a*a-2*a);
        else
            ans += (a*a-a);
    }
    cout << ans << endl;
    return 0;
}