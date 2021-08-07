#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const ll ROWS = 50;
unordered_map<ll, ll> pf;
set<ll> squarefree;
ll ans;

/*
    Return true if current num is squarefree
*/
bool check_square() {
    for(auto const& pair : pf) {
        if(pair.second >= 2) return false;
    }
    return true;
}

/*
    Calculate all values in a single row, add all 
    squarefree entries to "squarefree"
*/
void calculate(ll row) {
    pf.clear();
    ll prod = 1;
    for(ll i = 1; i <= row/2; i++) {
        prod *= (row+1-i);
        prod /= i;
        ll num = row+1-i;
        ll den = i;
        for(ll j = 2; j*j <= num; j++) {
            while(num%j == 0) {
                pf[j]++;
                num /= j;
            }
        }
        if(num != 1) pf[num]++;
        for(ll j = 2; j*j <= den; j++) {
            while(den%j == 0) {
                pf[j]--;
                den /= j;
            }
        }
        if(den != 1) pf[den]--;
        if(check_square()) {
            squarefree.insert(prod);
        }
    }
}

int main() {
    squarefree.insert(1);
    for(ll i = 1; i <= ROWS; i++) {
        calculate(i);
    }
    for(ll sqfr : squarefree) {
        ans += sqfr;
    }
    cout << ans << "\n";
    return 0;
}