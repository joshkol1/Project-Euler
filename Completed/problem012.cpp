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
    for(int i = 1; ; ++i) {
        int n = i*(i+1)/2;
        int divs = 0;
        for(int j = 1; j*j < n; ++j) {
            if(n%j == 0)
                divs += 2;
        }
        if(divs > 500) {
            cout << n << endl;
            return 0;
        }
    }
    return 0;
}