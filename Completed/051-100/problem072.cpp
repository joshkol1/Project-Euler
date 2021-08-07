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

int naive_totient(int n) {
    int totient = n;
    if(n%2 == 0) {
        totient /= 2;
        while(n%2 == 0)
            n /= 2;
    }
    for(int p = 3; p*p <= n; p += 2) {
        if(n%p == 0) {
            totient = totient/p*(p-1);
            while(n%p == 0)
                n /= p;
        }
    }
    if(n != 1)
        totient = totient/n*(n-1);
    return totient;
}

int main() {
    ll ans = 0;
    for(int n = 2; n <= 1000000; ++n)
        ans += naive_totient(n);
    cout << ans << endl;
    return 0;
}