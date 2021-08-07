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
    (void)!freopen("../../problem_inputs/p008_number.txt", "r", stdin);
    string num = "";
    string temp;
    while(cin >> temp)
        num += temp;
    ll ans = 0;
    for(size_t i = 0; i <= num.size()-13; ++i) {
        ll prod = 1;
        for(size_t j = i; j < i+13; ++j)
            prod *= (num[j]-'0');
        ans = max(ans, prod);
    }
    cout << ans << endl;
    return 0;
}