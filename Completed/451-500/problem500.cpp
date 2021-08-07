#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<array>
#include<assert.h>
#include<cstring>
#include<math.h>
#include<climits>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back

const int MAX_PRIME = 1e7;
bool prime[MAX_PRIME];
vector<int> primes;
const ll MOD = 500500507;

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

void get_primes() {
    memset(prime, true, sizeof prime);
    prime[1] = false;
    for(size_t i = 2; i < MAX_PRIME; ++i) {
        if(prime[i]) {
            primes.pb(i);
            for(size_t j = i*i; j < MAX_PRIME; j += i)
                prime[j] = false;
        }
    }
    while(primes.size() > 500500)
        primes.pop_back();
}

int main() {
    get_primes();
    vector<int> counts(500500);
    fill(counts.begin(), counts.end(), 0);
    auto cand_compare = [&](pair<int, int> a, pair<int, int> b) {
        return log(primes[a.first])*a.second > log(primes[b.first])*b.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cand_compare)> candidates(cand_compare);
    for(int i = 0; i < 500500; ++i)
        candidates.push({i, 1});
    for(int i = 0; i < 500500; ++i) {
        auto p = candidates.top();
        candidates.pop();
        ++counts[p.first];
        candidates.push({p.first, p.second*2});
    }
    ll ans = 1;
    for(size_t i = 0; i < 500500; ++i) {
        if(!counts[i])
            break;
        ans *= fast_exp(primes[i], (1<<counts[i])-1, MOD);
        ans %= MOD;
    }
    cout << ans << "\n";
    return 0;
}