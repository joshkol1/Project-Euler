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
    set<int> primes_below = {2, 3, 5, 7};
    for(int n = 9; ; n += 2) {
        if(prime(n)) {
            primes_below.insert(n);
            continue;
        }
        bool counter = true;
        for(int i = 1; 2*i*i < n; ++i) {
            if(primes_below.count(n-2*i*i)) {
                counter = false;
                break;
            }
        }
        if(counter) {
            cout << n << endl;
            break;
        }
    }
    return 0;
}