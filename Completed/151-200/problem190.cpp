#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

/*
    Using Lagrange multipliers, we can verify that
    x_i = (2*i)/(m+1). Just brute force rest
*/
ll pow_sum;

ll prod(int m) {
    long double ans = 1;
    for(int i = 1; i <= m; i++) {
        ans *= pow((2*i+0.0)/(m+1), i);
    }
    return (ll) ans;
}

int main() {
    for(int i = 2; i <= 15; i++) {
        pow_sum += prod(i);
    }
    cout << pow_sum << "\n";
    return 0;
}