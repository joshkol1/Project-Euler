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

int main() {
    auto n_solutions = vector<int>(1001, 0);
    for(int a = 1; a <= 1000; ++a) {
        for(int b = a; b <= 1000; ++b) {
            for(int c = b; c <= 1000-a-b; ++c) {
                if(a*a+b*b==c*c) {
                    ++n_solutions[a+b+c];
                    break;
                }
            }
        }
    }
    int ans = 0;
    int best_sols = 0;
    for(int n = 1; n <= 1000; ++n) {
        if(n_solutions[n] > best_sols) {
            best_sols = n_solutions[n];
            ans = n;
        }
    }
    cout << ans << endl;
    return 0;
}