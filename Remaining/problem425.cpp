#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int MAX = 1000;
bool prime[MAX+1];
bool relative[MAX+1];
int ans;

void init_sieve() {
    memset(prime, true, sizeof prime);
    prime[0] = false;
    prime[1] = false;
    for(int i = 4; i <= MAX; i += 2) {
        prime[i] = false;
    }
    for(int i = 3; i <= MAX; i += 2) {
        if(prime[i]) {
            for(int j = i*i; j <= MAX; j += i) {
                prime[j] = false;
            }
        }
    }
}

void search(int n, int prev){
    if(n >= prev) {
        relative[n] = true;
    }
    int n_copy = n;
    int ten_pow = 1;
    while(n > 0) {
        int unit_d = n%10;
        for(int i = -unit_d; i <= 9-unit_d; i++) {
            int gen = n_copy+i*ten_pow;
            if(prime[gen] && !relative[gen]) {
                search(gen, n_copy);
            }
        }
        n /= 10;
        ten_pow *= 10;
    }
    for(int i = 1; i <= 9; i++) {
        int gen = n_copy+i*ten_pow;
        if(gen <= MAX && prime[gen] && !relative[gen]) {
            search(gen, n_copy);
        }
    }
}

int main() {
    init_sieve();
    search(2, -1);
    for(int i = 3; i <= MAX; i += 2) {
        if(!relative[i] && prime[i]) {
            cout << i << "\n";
            ans += i;
        }
    }
    cout << ans << "\n";
    return 0;
}