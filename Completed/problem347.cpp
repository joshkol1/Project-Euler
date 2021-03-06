#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int MAX = 1E7;
bool prime[MAX+1];
set<int> prime_factors[MAX+1];
map<pair<int, int>, int> largest;
ll total;

void init_sieve() {
    memset(prime, true, sizeof prime);
    prime[1] = false;
    for(int i = 2; i <= MAX; i++) {
        if(prime[i]) {
            for(int j = 2*i; j <= MAX; j += i) {
                prime[j] = false;
                prime_factors[j].insert(i);
            }
        }
    }
}

void update(int n) {
    if(prime_factors[n].size() != 2) return;
    int p1 = *prime_factors[n].begin();
    int p2 = *prime_factors[n].rbegin();
    largest[make_pair(p1, p2)] = n;
}

int main() {
    init_sieve();
    for(int i = 2; i <= MAX; i++) {
        update(i);
    }
    for(auto const& p : largest) {
        total += p.second;
    }
    cout << total << "\n";
    return 0;
}