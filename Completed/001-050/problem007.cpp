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

bool prime(int n) {
    if(n == 1)
        return false;
    if(n == 2)
        return true;
    if(n%2 == 0)
        return false;
    for(int i = 3; i*i <= n; ++i) {
        if(n%i == 0)
            return false;
    }
    return true;
}

int main() {
    vector<int> primes;
    int n = 2;
    while(primes.size() < 10001) {
        if(prime(n))
            primes.pb(n);
        ++n;
    }
    cout << primes[10000] << endl;
    return 0;
}