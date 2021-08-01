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

size_t N;
size_t* spf;
size_t* totient;

size_t gcd(size_t a, size_t b) {
    return (a == 0) ? b : gcd(b%a, a);
}

size_t mod_inv(size_t b, size_t m) {
    /*
    if(gcd(x, m) != 1)
        throw invalid_argument("x is not coprime with m!");
    */
    size_t e = totient[m]-1;
    b %= m;
    size_t ret = 1;
    while(e > 0) {
        if(e&1) ret = ret*b%m;
        b = b*b%m;
        e >>= 1;
    }
    return ret;
}

// Initialize smasize_test prime factor & totient array
void init() {
    spf = new size_t[N+1];
    for(size_t i = 1; i <= N; ++i) {
        if(i%2 == 0)    
            spf[i] = 2;
        else
            spf[i] = i;
    }
    for(size_t i = 2; i*i <= N; ++i) {
        if(spf[i] == i) {
            for(size_t j = i*i; j <= N; j += i) 
                spf[j] = i;
        }
    }
    totient = new size_t[N+1];
    totient[1] = 1;
    for(size_t i = 2; i <= N; ++i) {
        size_t i_copy = i;
        size_t tot = i;
        while(i_copy != 1) {
            auto p = spf[i_copy];
            tot = tot/p*(p-1);
            while(i_copy%p == 0)
                i_copy /= p;
        }
        totient[i] = tot;
    }
}

size_t crt(const vector<size_t>& remainders, const vector<size_t>& moduli) {
    /*
    if(remainders.size() != moduli.size()) 
        throw invalid_argument("Moduli and remainders must have same # of terms!");
    if(remainders.size() == 0)
        throw invalid_argument("Must have at least one congruence");
    */
    if(remainders.size() == 1)
        return remainders[0];
    auto prev_rem = remainders[0];
    auto prev_mod = moduli[0];
    for(size_t i = 1; i < remainders.size(); ++i) {
        auto n1 = prev_mod;
        auto a1 = prev_rem;
        auto n2 = moduli[i];
        auto a2 = remainders[i];
        auto new_rem = a1*mod_inv(n2, n1)*n2 + a2*mod_inv(n1, n2)*n1;
        new_rem %= (prev_mod*n2);
        prev_mod *= n2;
        prev_rem = new_rem;
    }
    return prev_rem; 
}

size_t max_self_square(size_t n) {
    if(n == 1)
        return 0;
    else if(spf[n] == n) 
        return 1;
    vector<size_t> prime_partition;
    while(n != 1) {
        size_t new_prime = 1;
        size_t p = spf[n];
        while(n%p == 0) {
            new_prime *= p;
            n /= p;
        }
        prime_partition.pb(new_prime);
    }
    auto n_primes = prime_partition.size();
    // Prime powers always have solution 1
    if(n_primes == 1)
        return 1;
    auto rems = vector<size_t>(n_primes);
    size_t br = 0;
    // Exclude 0 and 1<<n_primes-1, since those lead to asize_t 0
    // and asize_t 1 moduli ---> a = 0, 1 which is not maximal
    for(size_t i = 1; i < (1u<<n_primes)-1; ++i) {
        for(size_t j = 0; j < n_primes; ++j)
            rems[j] = ((1<<j)&i)>>j;
        br = max(br, crt(rems, prime_partition));
    }
    return br;
}

int main() {
    cin >> N;
    init();
    size_t ans = 0;
    for(size_t i = 1; i <= N; ++i) 
        ans += max_self_square(i);
    cout << ans << "\n";
    return 0;
}