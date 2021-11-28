#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<numeric>
#include<iomanip>
typedef long long ll;
typedef long double ld;
#define pb push_back

std::vector<ll> factors[100000];

ll gcd(ll a, ll b) {
    if(a == 0) {
        return b;
    }
    return gcd(b%a, a);
}

void generate_factors() {
    for(ll i = 0; i < 100000; ++i) {
        factors[i] = std::vector<ll>();
    }
    for(ll i = 1; i < 100000; ++i) {
        for(ll j = i; j < 100000; j += i) {
            factors[i].pb(j);
        }
    }
}

int main() {
    generate_factors();
    std::string pandigital = "1023456789";
    do {
        // Can process each pandigital here

    } while(std::next_permutation(pandigital.begin(), pandigital.end()));
}