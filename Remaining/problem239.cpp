#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

bool prime(int n) {
    if(n == 1) return false;
    for(int i = 2; i*i <= n; i++) {
        if(n%i == 0) return false;
    }
    return true;
}

int main() {
    for(int i = 1; i <= 100; i++) {
        if(prime(i)) cout << i << "\n";
    }
    return 0;
}