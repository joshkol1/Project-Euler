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

int rad(int n) {
    int ans = 1;
    if(n%2 == 0) {
        ans *= 2;
        while(n%2 == 0)
            n /= 2;
    }
    for(int i = 3; i*i <= n; ++i) {
        if(n%i == 0) {
            ans *= i;
            while(n%i == 0)
                n /= i;
        }
    }
    if(n != 1)
        ans *= n;
    return ans;
}

int main() {
    vector<pair<int, int>> rads;
    for(int n = 1; n <= 1E5; ++n)
        rads.push_back({rad(n), n});
    sort(rads.begin(), rads.end());
    cout << rads[9999].second << endl;
    return 0;
}