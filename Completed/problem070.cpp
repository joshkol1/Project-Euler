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

int totient(int n, vector<int>& spf) {
    int totient = n;
    while(n != 1) {
        auto p = spf[n];
        totient = totient/p*(p-1);
        while(n%p == 0)
            n /= p;
    }
    return totient;
}

bool same_digits(int n1, int n2) {
    auto s1 = to_string(n1);
    auto s2 = to_string(n2);
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

int main() {
    int search_bound = 1E7;
    vector<int> spf(search_bound);
    for(int n = 2; n < search_bound; ++n)
        spf[n] = (n%2 == 0) ? 2 : n;
    for(int n = 3; n*n < search_bound; n += 2) {
        if(spf[n] == n) {
            for(int j = n*n; j < search_bound; j += 2*n) {
                if(spf[j] == j)
                    spf[j] = n;
            }
        }
    }
    int ans = 0;
    double best_ratio = search_bound;
    for(int n = 2; n < search_bound; ++n) {
        auto tot = totient(n, spf);
        if(same_digits(n, tot) && n/(tot+0.0) < best_ratio) {
            best_ratio = n/(tot+0.0);
            ans = n;
        }
    }
    cout << ans << endl;
    return 0;
}