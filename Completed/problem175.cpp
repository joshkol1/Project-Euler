#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const ll NUM = 123456789L;
const ll DEN = 987654321L;
vector<int> bits;
vector<int> counts;

ll gcd(ll a, ll b) {
    if(a == 0) return b;
    return gcd(b%a, a);
}

/*
    Return path taken in Calkin-Wilf tree to get
    num/den from 1/1, with 0 representing left
    and 1 representing right
*/
void calkin_wilf(ll num, ll den) {
    ll cf = gcd(num, den); num /= cf; den /= cf;
    while(num != 1 || den != 1) {
        if(num > den) {
            bits.pb(1);
            if(den == 1) {
                counts.pb(num-1); num = 1;
                continue;
            }
            counts.pb(num/den);
            num %= den;
        }
        else {
            bits.pb(0);
            if(num == 1) {
                counts.pb(den-1); den = 1;
                continue;
            }
            counts.pb(den/num);
            den %= num;
        }
    }
    int n_terms = bits.size();
    if(bits[n_terms-1] == 0) {
        counts.pb(1);
        bits.pb(1);
        n_terms++;
    }
    else {
        counts[n_terms-1]++;
    }
    reverse(bits.begin(), bits.end());
    reverse(counts.begin(), counts.end());
    for(int i = 0; i < n_terms-1; i++) {
        cout << counts[i] << ",";
    }
    cout << counts[n_terms-1] << "\n";
}

int main() {
    calkin_wilf(DEN, NUM);
    return 0;
}