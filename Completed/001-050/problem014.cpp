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
    int max_terms = 0;
    int ans = 0;
    auto chain_length = vector<int>(1000001, 0);
    chain_length[1] = 1;
    for(ll n = 2; n < 1000000; ++n) {
        auto n_copy = n;
        int terms = 0;
        while(n_copy != 1) {
            ++terms;
            if(n_copy%2 == 0)
                n_copy /= 2;
            else
                n_copy = 3*n_copy+1;
            if(n_copy <= 1000000 && chain_length[n_copy] != 0) {
                terms += chain_length[n_copy];
                break;
            }
        }
        if(max_terms < terms) {
            max_terms = terms;
            ans = n;
        }
    }
    cout << ans << endl;
    return 0;
}