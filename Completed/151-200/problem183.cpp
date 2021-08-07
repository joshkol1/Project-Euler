#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

/*
    Say we choose k. Then the product is (N/k)^k, which 
    we wish to maximize over integers k.
    Take log ===> k*log(N) - k*log(k)

    Notice that this is concave, so we need to find
    first value of k where 
    (k+1)*log(N)-(k+1)*log(k+1) < k*log(N)-k*log(k)
    ===> log(N) < (k+1)*log(k+1)-k*log(k).
    Obvious solution is k = N, so we can iterate 
    backwards to find appropriate k.
    
    After this, simplify N/k, and check if denominator
    has only factors of 2 and 5.
*/

const int MAX = 10000;

int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b%a, a);
}

int find_k(int N) {
    int ans = N;
    while(log(N) < (ans+1)*log(ans+1)-ans*log(ans)) {
        ans--;
    }
    return ans+1;
}

int main() {
    int ans = 0;
    for(int i = 5; i <= MAX; i++) {
        int k = find_k(i);
        k /= gcd(i, k);
        while(k%2 == 0) k /= 2;
        while(k%5 == 0) k /= 5;
        if(k == 1) ans -= i;
        else ans += i;
    }
    cout << ans << "\n";
    return 0;
}