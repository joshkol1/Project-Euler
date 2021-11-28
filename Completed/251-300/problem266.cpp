#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<numeric>
#include<iomanip>
typedef long long ll;
typedef long double ld;
#define pb push_back

std::vector<int> primes;
std::vector<ld> prime_logs;
ll MOD = 1e16;

bool isPrime(int n) {
    if(n == 1)
        return false;
    for(int i = 2; i*i <= n; ++i) {
        if(n%i == 0)
            return false;
    }
    return true;
}

void getPrimes(int n) {
    if(n >= 2) {
        primes.push_back(2);
        prime_logs.push_back(std::log(2+ld{0.0}));
    }
    for(int i = 3; i <= n; i += 2) {
        if(isPrime(i)) {
            primes.push_back(i);
            prime_logs.push_back(std::log(i+ld{0.0}));
        }
    }
}

std::vector<int> bestSubset() {
    /* First split list in half & find all subset sums */
    std::vector<std::pair<ld, size_t>> firstHalf;
    std::vector<std::pair<ld, size_t>> secondHalf;
    auto all_primes = std::accumulate(prime_logs.begin(), prime_logs.end(), ld{0});
    auto half_index = prime_logs.size()/2;
    auto other_half = prime_logs.size()-half_index;
    /* Generate all first-half sums */
    for(size_t i = 0; i < 1<<half_index; ++i) {
        ld subset_sum = 0;
        for(size_t j = 0; j < half_index; ++j) {
            if(i&(1<<j)) {
                subset_sum += prime_logs[j];
            }
        }
        firstHalf.emplace_back(subset_sum, i);
    }
    /* Generate all second-half sums */
    for(size_t i = 0; i < 1<<other_half; ++i) {
        ld subset_sum = 0;
        for(size_t j = 0; j < other_half; ++j) {
            if(i&(1<<j)) {
                subset_sum += prime_logs[half_index+j];
            }
        }
        secondHalf.emplace_back(subset_sum, i);
    }
    std::sort(firstHalf.begin(), firstHalf.end());
    std::sort(secondHalf.begin(), secondHalf.end());
    ld best_sum = 0;
    size_t firstHalfIndices = 0;
    size_t secondHalfIndices = 0;
    /* 
       For each first-half product, search for best second-half product
       which doesn't bring the total product over sqrt.
    */ 
    for(auto& p : firstHalf) {
        int low = 0; int high = secondHalf.size();
        while(low != high) {
            int mid = (low+high)/2;
            if(secondHalf[mid].first+p.first < all_primes/2) {
                low = mid+1;
            }
            else {
                high = mid;
            }
        }
        if(p.first+secondHalf[low-1].first > best_sum) {
            best_sum = p.first+secondHalf[low-1].first;
            firstHalfIndices = p.second;
            secondHalfIndices = secondHalf[low-1].second;
        }
    }
    std::vector<int> answer_vector;
    for(size_t i = 0; i < half_index; ++i) {
        if(firstHalfIndices&(1<<i)) {
            answer_vector.push_back(primes[i]);
        }
    }
    for(size_t i = 0; i < other_half; ++i) {
        if(secondHalfIndices&(1<<i)) {
            answer_vector.push_back(primes[half_index+i]);
        }
    }
    return answer_vector;
}

int main() {
    getPrimes(190);
    auto answer_primes = bestSubset();
    ll answer = 1;
    for(auto p : answer_primes)
        answer = (answer*p)%MOD;
    std::cout << answer << std::endl;
    return 0;
}