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
    int n_prime = 0;
    int total = 1;
    for(int n = 3; ; n += 2) {
        total += 4;
        n_prime += prime(n*n-n+1);
        n_prime += prime(n*n-2*n+2);
        n_prime += prime(n*n-3*n+3);
        if(n_prime*10 < total) {
            cout << n << endl;
            break;
        }
    }
    return 0;
}