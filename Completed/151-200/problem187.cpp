#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int MAX = 1E8;
bool prime[MAX];
vector<int> prime_list;
int n_primes;
int ans;

void init_sieve() {
    memset(prime, true, sizeof prime);
    prime[1] = false;
    for(int i = 2; i < MAX; i++) {
        if(prime[i]) {
            prime_list.pb(i);
            n_primes++;
            for(int j = 2*i; j < MAX; j += i) {
                prime[j] = false;
            }
        }
    }
}

int bin_search(int n) {
    int low = 0; int high = n_primes-1;
    while(low < high) {
        int m = (low+high)/2;
        if(prime_list[m] == n) return m;
        else if(prime_list[m] > n) {
            high = m-1;
        }
        else {
            low = m+1;
        }
    }
    if(prime_list[low] > n) return low-1;
    return low;
}

int main() {
    init_sieve();
    for(int i = 0; i < n_primes; i++) {
        if(prime_list[i]*prime_list[i] > MAX) break;
        ans += bin_search(MAX/prime_list[i])-i+1;
    }
    cout << ans << "\n";
    return 0;
}