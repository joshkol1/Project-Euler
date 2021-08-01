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

int main() {
    ll N = 10000;
    ll low = N/2+1;
    ll high = (1+sqrt(2))/2*N;
    for(ll x = low; x < high; ++x) {
        for(ll y = x+1; y < high; ++y) {
            if(x*(x-N)+y*(y-N) == 0)
                cout << x << " " << y << endl;
        }
    }
    return 0;
}