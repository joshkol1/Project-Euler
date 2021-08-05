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

bool same_digits(int n1, int n2) {
    auto s1 = to_string(n1);
    auto s2 = to_string(n2);
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

int main() {
    for(int n = 1; ; ++n) {
        if(!same_digits(n, 2*n))
            continue;
        if(!same_digits(n, 3*n))
            continue;
        if(!same_digits(n, 4*n))
            continue;
        if(!same_digits(n, 5*n))
            continue;
        if(!same_digits(n, 6*n))
            continue;
        cout << n << endl;
        break;
    }
    return 0;
}