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
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back

int main() {
    int a = 1;
    int b = 1;
    int ans = 0;
    while(b < 4000000) {
        if((a+b)%2 == 0)
            ans += (a+b);
        b = a+b;
        a = b-a;
    }
    cout << ans << endl;
    return 0;
}