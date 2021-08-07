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

vector<int> factorial;

size_t chain_length(int n) {
    set<int> found;
    while(!found.count(n)) {
        found.insert(n);
        int new_term = 0;
        while(n != 0) {
            new_term += factorial[n%10];
            n /= 10;
        }
        n = new_term;
    }
    return found.size();
}

int main() {
    factorial.pb(1);
    for(int i = 1; i <= 9; ++i)
        factorial.pb(factorial[i-1]*i);
    int ans = 0;
    for(int i = 1; i < 1000000; ++i) {
        ans += (chain_length(i) == 60);
    }
    cout << ans << endl;
    return 0;
}