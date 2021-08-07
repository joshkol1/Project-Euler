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

int main() {
    ll MOD = 1E10;
    ll value = 28433;
    bool found = false;
    for(int i = 0; i < 7830457; ++i) 
        value = (value*2)%MOD;
    cout << (value+1)%MOD << endl;
    return 0;
}