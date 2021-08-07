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
    vector<int> vals;
    for(int i = 1; i < 1000; ++i)
        if(i%3 == 0 || i%5 == 0)
            vals.pb(i);
    cout << accumulate(vals.begin(), vals.end(), 0) << endl;
    return 0;
}