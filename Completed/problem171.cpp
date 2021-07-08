#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

int digit_counts[10];
int digits_used;
const ll MOD = 1E9;
ll factorials[21];
ll ones = 111111111L;
ll answer;

bool square_sum() {
    int sum = 0;
    for(int i = 0; i <= 9; ++i)
        sum += digit_counts[i]*i*i;
    int root = sqrt(sum);
    return sum == root*root;
}

/*
    How many permutations exist when holding an index as digit?
*/
ll n_permutations(int digit) {
    if(digit_counts[digit] == 0)
        return 0;
    ll answer = factorials[19];
    for(int i = 0; i <= 9; ++i) {
        if(i == digit)
            answer /= factorials[digit_counts[i]-1];
        else
            answer /= factorials[digit_counts[i]];
    }
    return answer;
}

void search(int depth) {
    if(depth >= 9) {
        digit_counts[9] = 20-digits_used;
        if(square_sum()) {
            for(int i = 1; i <= 9; ++i) {
                ll good_p = n_permutations(i) % MOD;
                answer += (ones * i * good_p) % MOD;
                answer %= MOD;
            }
        }
        digit_counts[9] = 0;
        return;
    }
    for(int i = 0; i <= 20-digits_used; ++i) {
        digit_counts[depth] = i;
        digits_used += i;
        search(depth+1);
        digit_counts[depth] = 0;
        digits_used -= i;
    }
}

int main() {
    factorials[0] = 1;
    for(int i = 1; i <= 20; ++i) 
        factorials[i] = factorials[i-1] * i;
    search(0);
    cout << answer << "\n";
    return 0;
}