#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

ll MOD = 1E16;
vector<int> S;
const int UB = 5000;
int S_sum;
int S_size;

void fill_S() {
    for(int i = 2; i <= UB; ++i) {
        bool prime = true;
        for(int j = 2; j*j <= i; ++j) {
            if(i%j == 0) {
                prime = false;
                break;
            }
        }
        if(prime)
            S.pb(i);
    }
    S_size = S.size();
    for(auto& v : S)
        S_sum += v;
}

int main() {
    fill_S();
    auto dp = new ll*[S_sum+1];
    for(int i = 0; i <= S_sum; ++i) {
        dp[i] = new ll[S_size+1];
    }
    for(int i = 0; i <= S_size; ++i)
        dp[0][i] = 1;
    for(int sum = 1; sum <= S_sum; ++sum) {
        for(int size = 1; size <= S_size; ++size) {
            dp[sum][size] = dp[sum][size-1];
            if(sum-S[size-1] >= 0) {
                ll n_mod = dp[sum-S[size-1]][size-1] % MOD;
                dp[sum][size] = (dp[sum][size] + n_mod) % MOD;
            }
        }
    }
    ll final_answer = 0;
    for(int sum = 2; sum <= S_sum; ++sum) {
        bool prime = true;
        for(int j = 2; j*j <= sum; ++j) {
            if(sum%j == 0) {
                prime = false;
                break;
            }
        }
        if(prime)
            final_answer = (final_answer + dp[sum][S_size]) % MOD;
    }
    cout << final_answer << "\n";
    for(int i = 0; i <= S_sum; ++i)
        delete[] dp[i];
    delete[] dp;
    return 0;
}