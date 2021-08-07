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

vector<int> ten_pows;

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

bool circ_prime(int n) {
    auto n_copy = n;
    if(!prime(n))
        return false;
    if(n < 10)
        return true;
    auto n_digits = to_string(n).length();
    do {
        n = (n%ten_pows[n_digits-1])*10+(n/ten_pows[n_digits-1]);
        if(!prime(n))
            return false;
    } while(n != n_copy);
    return true;
}

int main() {
    int ans = 0;
    ten_pows.pb(1);
    for(int i = 1; i <= 5; ++i)
        ten_pows.pb(ten_pows[i-1]*10);
    for(int i = 2; i < 1000000; ++i) 
        ans += circ_prime(i);
    cout << ans << endl;
    return 0;
}