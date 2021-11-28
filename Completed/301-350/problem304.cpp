#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<numeric>
#include<iomanip>
#include <string.h>
#include <assert.h>
typedef long long ll;
typedef long double ld;
#define pb push_back

const ll MOD = 1234567891011;
const ll prime_lb = 1E14;
// Segmented sieve - index i is prime_lb+i
const int sieve_size = 5E6;
bool is_prime[sieve_size+1];
std::vector<ll> primes;
// Prime factors to use in segmented sieve
std::vector<ll> prime_factors;
const int pf_bound = 2E7;

void get_prime_factors() {
    auto isPrime = std::vector<bool>(pf_bound+1, true);
    isPrime[1] = false;
    for(int i = 4; i <= pf_bound; i += 2) {
        isPrime[i] = false;
    }
    for(int i = 3; i*i <= pf_bound; i += 2) {
        if(isPrime[i]) {
            for(int j = i*i; j <= pf_bound; j += i) {
                isPrime[j] = false;
            }
        }
    }
    prime_factors.pb(2);
    for(int i = 3; i <= pf_bound; i += 2) {
        if(isPrime[i]) {
            prime_factors.pb(i);
        }
    }
}

void get_sieve_primes() {
    memset(is_prime, true, sizeof is_prime);
    for(auto p : prime_factors) {
        auto start_index = (prime_lb%p == 0) ? 0 : p-(prime_lb%p);
        for(int index = start_index; index <= sieve_size; index += p) {
            is_prime[index] = false;
        }
    }
    for(int i = 0; i <= sieve_size; ++i) {
        if(is_prime[i]) {
            primes.pb(prime_lb+i);
        }
    }
}

std::vector<std::vector<ll>> matrix_mult(
    std::vector<std::vector<ll>>& m1, std::vector<std::vector<ll>>& m2, ll mod) {
    if(m1[0].size() != m2.size()) {
        throw std::runtime_error("Dimension mismatch");
    }
    auto prod = std::vector<std::vector<ll>>(m1.size(), std::vector<ll>(m2[0].size()));
    for(size_t i = 0; i < m1.size(); ++i) {
        for(size_t j = 0; j < m2[0].size(); ++j) {
            ll entry = 0;
            for(size_t k = 0; k < m2.size(); ++k) {
                entry = ((__int128_t)m1[i][k]*m2[k][j]+entry)%mod;
            }
            prod[i][j] = entry;
        }
    }
    return prod;
}

std::vector<std::vector<ll>> matrix_pow(std::vector<std::vector<ll>>& mat, ll e, ll mod) {
    std::vector<std::vector<ll>> ret = {{1, 0}, {0, 1}};
    std::vector<std::vector<ll>> mat_copy(mat);
    while(e > 0) {
        if(e&1) ret = matrix_mult(ret, mat_copy, mod);
        mat_copy = matrix_mult(mat_copy, mat_copy, mod);
        e >>= 1;
    }
    return ret;
}

int main() {
    get_prime_factors();
    get_sieve_primes();
    ll answer = 0;
    std::vector<std::vector<ll>> fib_matrix = {{0, 1}, {1, 1}};
    auto fib_mat_pow = matrix_pow(fib_matrix, prime_lb, MOD);
    ll f_a = fib_mat_pow[0][1]%MOD;
    ll f_b = fib_mat_pow[1][1]%MOD;
    ll init_index = prime_lb;
    for(size_t i = 0; i < 100000; ++i) {
        auto n_increments = primes[i]-init_index;
        for(int i = 0; i < n_increments; ++i) {
            auto temp = f_a;
            f_a = f_b;
            f_b = (f_b+temp)%MOD;
        }
        answer = (answer+f_a)%MOD;
        init_index = primes[i];
    }
    std::cout << answer << std::endl;
    return 0;
}