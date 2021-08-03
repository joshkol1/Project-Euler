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

// Return pandigital product if it exists, otherwise 0.
ll pandigital(int n) {
    string pand = "";
    for(int i = 1; pand.length() < 9; ++i) 
        pand += to_string(i*n);
    if(pand.length() != 9)
        return 0;
    for(int i = 1; i <= 9; ++i) {
        if(pand.find(to_string(i)) == string::npos)
            return 0;
    }
    return stoll(pand);
}

int main() {
    ll best_pand = 0;
    for(int n = 1; n <= 100000; ++n)
        best_pand = max(best_pand, pandigital(n));
    cout << best_pand << endl;
    return 0;
}