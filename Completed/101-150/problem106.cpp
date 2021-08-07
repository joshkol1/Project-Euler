#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

/*
    Since property 2 is satisfied and all elements are 
    distinct, we simply have to test all pairs of 
    subsets with size >= 2. 
    
    Suppose we list elements of each subset in 
    increasing order. Then, we don't have to test for 
    equality if and only if pairwise elements at 
    same indices return same comparison value (all 
    bigger or smaller for one set). 

    For the final answer, each set could be size 2 thru
    6, meaning total elements tested is 4, 6, 8, 10, 12.
    For each total size, we can choose in 12 C n ways.
    Since sets are "identical", answer is sum of 
    f(n)*12Cn, where f(n) is # subset pairs that need
    testing for n total elements.
*/

int dp[13];
vector<int> first;
vector<int> second;

int choose(int n, int k) {
    int ans = 1;
    for(int i = 1; i <= k; i++) {
        ans *= (n-k+i); ans /= i;
    }
    return ans;
}

bool good_subsets() {
    int n = first.size();
    if(first[0] > second[0]) {
        for(int i = 1; i < n; i++) {
            if(first[i] < second[i]) return true;
        }
    }
    else {
        for(int i = 1; i < n; i++) {
            if(first[i] > second[i]) return true;
        }
    }
    return false;
}

/*
    For set size n, how many subset pairs need to
    be tested? Store answer in dp[n].
*/
void solve(int n) {
    for(int i = 0; i < 1<<n ; i++) {
        if(__builtin_popcount(i) != n/2) continue;
        first.clear();
        second.clear();
        for(int j = 0; j < n; j++) {
            if(i&(1<<j)) {
                first.pb(j);
            }
            else {
                second.pb(j);
            }
        }
        dp[n] += good_subsets();
    }
    /*
        Overcounted each pair twice, so divide by 2.
    */
    dp[n] /= 2;
}

int main() {
    int ans = 0;
    for(int i = 4; i <= 12; i += 2) {
        solve(i);
        ans += choose(12, i)*dp[i];
    }
    cout << ans << "\n";
    return 0;
}