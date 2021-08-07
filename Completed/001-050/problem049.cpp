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

int are_permutations(int n1, int n2) {
    auto s1 = to_string(n1);
    auto s2 = to_string(n2);
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

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
    for(int n = 1001; n < 9999; ++n) {
        for(int d = 2; n+2*d <= 9999; d += 2) {
            if(!prime(n))
                break;
            if(!prime(n+d) || !prime(n+2*d))
                continue;
            if(are_permutations(n, n+d) && are_permutations(n, n+2*d)) {
                if(n == 1487 && n+d == 4817)
                    continue;
                cout << n << n+d << n+2*d << endl;
                return 0;
            }
        }
    }
    cout << "Sequence not found :(" << endl;
    return 1;
}