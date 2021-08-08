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

bool square(int n) {
    int root = sqrt(n);
    return root*root == n;
}

int main() {
    int sols = 0;
    for(int m = 1; ; ++m) {
        for(int i = 1; i <= m; ++i) {
            for(int j = i; j <= m; ++j) {
                sols += square((i+j)*(i+j)+m*m);
            }
        }
        if(sols > 1E6) {
            cout << m << endl;
            break;
        }
    }
    return 0;
}