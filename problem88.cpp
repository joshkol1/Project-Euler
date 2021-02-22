#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const double eps = 1e-9;

const int MAX = 30000;
vector<int> factors;
bool prime[MAX+1];
int max_nums[MAX+1];
int min_prod[12001];

void init_sieve() {
    memset(prime, true, sizeof prime);
    prime[1] = false;
    for(int i = 2; i <= MAX; i++) {
        if(prime[i]) {
            for(int j = 2*i; j <= MAX; j += i) {
                prime[j] = false;
            }
        }
    }
}

void pf(int n) {
    factors.clear();
    if(prime[n]) {
        factors.pb(n);
        return;
    }
    for(int i = 2; i*i <= n; i++) {
        if(prime[i]) {
            while(n%i == 0) {
                factors.pb(i);
                n /= i;
            }
        }
    }
    if(prime[n]) factors.pb(n);
}

int main() {
    init_sieve();
    for(int i = 2; i <= MAX; i++) {
        if(prime[i]) continue;
        pf(i);
        int sum = 0;
        for(int p : factors) sum += p;
        max_nums[i] = (i-sum)+factors.size();
        /*
        cout << i << ": ";
        cout << max_nums[i] << "\n";
        */
        if(min_prod[sum] == 0) {
            min_prod[sum] = i;
        }
    }
    int cnt = 0;
    for(int i = 2; i <= 12000; i++) {
        if(min_prod[i] != 0) cnt++;
    }
    for(int i = 2; i <= 100; i++) {
        cout << min_prod[i] << "\n";
    }
    //cout << cnt << "\n";
    return 0;
}