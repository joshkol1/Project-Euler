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

vector<int> prime_factors(int n) {
    vector<int> ans;
    if(n%2 == 0) {
        ans.pb(2);
        while(n%2 == 0)
            n /= 2;
    }
    for(int i = 3; i*i <= n; ++i) {
        if(n%i == 0) {
            ans.pb(i);
            while(n%i == 0)
                n /= i;
        }
    }
    if(n != 1)
        ans.pb(n);
    return ans;
}

int main() {
    for(int n = 1; ; ++n) {
        if(prime_factors(n).size() != 4)
            continue;
        if(prime_factors(n+1).size() != 4) {
            ++n;
            continue;
        }
        if(prime_factors(n+2).size() != 4) {
            n += 2;
            continue;
        }
        if(prime_factors(n+3).size() != 4) {
            n += 3;
            continue;
        }
        cout << n << endl;
        break;
    }
    return 0;
}