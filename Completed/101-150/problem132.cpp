#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int MAX = 1E8;
const int EXPONENT = 1E9;
bool prime[MAX+1];

ll fast_exp(ll b, ll e, ll m) {
    b %= m;
    ll ret = 1;
    while(e > 0) {
        if(e&1) ret = ret*b%m;
        b = b*b%m;
        e >>= 1;
    }
    return ret;
}

int order(int n, int p) {
    int ans = p-1;
    for(int i = 2; i*i <= p-1; i++) {
        if((p-1)%i == 0) {
            if(fast_exp(n, i, p) == 1) {
                ans = i;
                break;
            }
            else if(fast_exp(n, (p-1)/i, p) == 1) {
                ans = min(ans, (p-1)/i);
            }
        }
    }
    return ans;
}

void init_sieve() {
    prime[2] = true;
    for(int i = 3; i <= MAX; i++) {
        prime[i] = i%2;
    }
    for(int i = 3; i*i <= MAX; i += 2) {
        if(prime[i]) {
            for(int j = i*i; j <= MAX; j += i) {
                prime[j] = false;
            }
        }
    }
}

int main() {
    init_sieve();
    int count = 0;
    ll p_sum = 0;
    for(int i = 7; i <= MAX && count < 40; i++) {
        if(!prime[i]) continue;
        if(EXPONENT%order(10, i) == 0) {
            count++; p_sum += i;
        }
    }
    cout << p_sum << "\n";
    return 0;
}