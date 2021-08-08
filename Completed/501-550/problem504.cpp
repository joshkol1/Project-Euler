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

int gcd(int a, int b) { 
    return (a == 0) ? b : gcd(b%a, a);
}

bool is_square(int n) {
    if(n < 0)
        return false;
    int root = sqrt(n);
    return root*root == n;
}

int interior_points(int a, int b, int c, int d) {
    // A = i+b/2-1 --> 2*A = 2*i+b-2
    // 2*i = 2*A-b+2
    int boundary = gcd(a, b)+gcd(a, d)+gcd(c, b)+gcd(c, d);
    int area = (a+c)*(b+d);
    return ((area-boundary+2)%2 == 0) ? (area-boundary+2)/2 : -1;
}

int main() {
    int ans = 0;
    for(int a = 1; a <= 100; ++a) {
        for(int b = 1; b <= 100; ++b) {
            for(int c = 1; c <= 100; ++c) {
                for(int d = 1; d <= 100; ++d) {
                    ans += is_square(interior_points(a, b, c, d));
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}