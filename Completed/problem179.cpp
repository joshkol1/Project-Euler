#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int MAX = 1E7;
bool prime[MAX+1];
vector<int> prime_list;

void init_sieve() {
    memset(prime, true, sizeof prime);
    prime[1] = false;
    for(int i = 2; i <= MAX; i++) {
        if(prime[i]) {
            prime_list.pb(i);
            for(int j = 2*i; j <= MAX; j += i) {
                prime[j] = false;
            }
        }
    }
}

int n_divisors(int n) {
    int ans = 1;
    for(int p : prime_list) {
        if(n == 1) break;
        if(prime[n]) {
            ans *= 2; break;
        }
        if(n%p == 0) {
            int c = 1;
            while(n%p == 0) {
                c++; n /= p;
            }
            ans *= c;
        }
    }
    return ans;
}

int main() {
    init_sieve();
    int ans = 0;
    for(int i = 2; i < MAX; i++) {
        if(n_divisors(i) == n_divisors(i+1)) ans++;
    }
    cout << ans << "\n";
    return 0;
}