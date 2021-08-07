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
    for(int i = 3; i*i <= n; i += 2) {
        if(n%i == 0)
            return false;
    }
    return true;
}

bool truncatable(int n) {
    if(!prime(n))
        return false;
    int n_copy = n;
    int ten_pow = 1;
    for(size_t i = 0; i < to_string(n).length()-1; ++i)
        ten_pow *= 10;
    while(ten_pow != 1) {
        n_copy %= ten_pow;
        if(!prime(n_copy))
            return false;
        ten_pow /= 10;
    }
    n_copy = n;
    while(n_copy != 0) {
        if(!prime(n_copy))
            return false;
        n_copy /= 10;
    }
    return true;
}

int main() {
    int ans = 0;
    int found = 0;
    for(int n = 11; found < 11; n += 2) {
        if(truncatable(n)) {
            ans += n;
            ++found;
        }
    }
    cout << ans << endl;
    return 0;
}