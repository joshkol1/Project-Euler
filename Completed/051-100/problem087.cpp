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

bool naive_prime(int n) {
    if(n == 1)
        return false;
    if(n == 2)
        return true;
    if(n%2 == 0)
        return false;
    for(int i = 3; i*i <= n; i += 2) {
        if(n%i == 0)
            return false;
    }
    return true;
}

vector<int> prime_squares(int upto) {
    vector<int> ans;
    if(upto >= 4)
        ans.pb(4);
    for(int n = 3; n*n < upto; n += 2) {
        if(naive_prime(n))
            ans.pb(n*n);
    }
    return ans;
}

vector<int> prime_cubes(int upto) {
    vector<int> ans;
    if(upto >= 8)
        ans.pb(8);
    for(int n = 3; n*n*n < upto; n += 2) {
        if(naive_prime(n))
            ans.pb(n*n*n);
    }
    return ans;
}

vector<int> prime_fourths(int upto) {
    vector<int> ans;
    if(upto >= 16)
        ans.pb(16);
    for(int n = 3; n*n*n*n < upto; n += 2) {
        if(naive_prime(n))
            ans.pb(n*n*n*n);
    }
    return ans;
}

int main() {
    int upto = 5E7;
    vector<bool> expressible(upto, false);
    auto squares = prime_squares(upto);
    auto cubes = prime_cubes(upto);
    auto fourths = prime_fourths(upto);
    for(size_t i = 0; i < fourths.size(); ++i) {
        for(size_t j = 0; j < cubes.size(); ++j) {
            for(size_t k = 0; k < squares.size(); ++k) {
                if(fourths[i]+cubes[j]+squares[k] >= upto)
                    break;
                expressible[fourths[i]+cubes[j]+squares[k]] = true;
            }
        }
    }
    int ans = 0;
    for(auto e : expressible)
        ans += e;
    cout << ans << endl;
    return 0;
}