#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

/*
    Theorem: Suppose we wish to calculate (m choose n), where
    m = m_k*p^k + m_{k-1}*p^(k-1) + ... + m_1*p + m_0
    n = n_k*p^k + n_{k-1}*p^(k-1) + ... + n_1*p + n_0
    
    Then, (m choose n) = (m0 choose n0) * ... * (m_k choose n_k) mod p

    Source: https://en.wikipedia.org/wiki/Lucas%27s_theorem
*/

/*
    Suppose we fix m (row of triangle). We need to see how many of 
    (m choose n), where 0 <= n <= m, are != 0 mod 7. This is simply the 
    product of the digits of m. 

    Sum above over 0 <= n <= 10^9-1
*/

int MAX;
vector<int> digits;
ll answer;

void increment() {
    if(digits.empty()) {
        digits.pb(0);
        return;
    }
    digits[0]++;
    uint ind = 0;
    while(digits[ind] == 7 && ind < digits.size()) {
        digits[ind] = 0;
        digits[ind+1]++;
        ind++;
    }
    if(ind == digits.size()) {
        digits.pb(1);
    }
}

void add_choices() {
    ll to_add = 1;
    for(int d : digits) to_add *= (d+1);
    answer += to_add;
}

int main() {
    cin >> MAX;
    for(int i = 0; i < MAX; i++) {
        increment();
        add_choices();
    }
    cout << answer << "\n";
    return 0;
}