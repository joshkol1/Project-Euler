#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<set>
#include<array>
#include<assert.h>
#include<string>
#include<math.h>
#include<climits>
#include<utility>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

/* Get hamming #'s up to N */
std::vector<ull> get_hamming(ull N) {
    std::vector<ull> hamming;
    std::vector<ull> two_powers;
    std::vector<ull> three_powers;
    std::vector<ull> five_powers;
    for(ull i = 1; i <= N; i *= 2) {
        two_powers.push_back(i);
    }
    for(ull i = 1; i <= N; i *= 3) {
        three_powers.push_back(i);
    }
    for(ull i = 1; i <= N; i *= 5) {
        five_powers.push_back(i);
    }
    for(auto two_pow : two_powers) {
        for(auto three_pow : three_powers) {
            auto base = two_pow*three_pow;
            for(auto five_pow : five_powers) {
                if(base*five_pow > N) {
                    break;
                }
                hamming.push_back(base*five_pow);
            }
        }
    }
    std::sort(hamming.begin(), hamming.end());
    return hamming;
}

bool isPrime(ull n) {
    if(n == 2) {
        return true;
    }
    if(n%2 == 0) {
        return false;
    }
    for(ull i = 3; i*i <= n; i += 2) {
        if(n%i == 0) {
            return false;
        }
    }
    return true;
}

// Find index of last element <= to value
int binary_search(std::vector<ull>& list, ull value) {
    int low = 0;
    int high = list.size()-1;
    while(low < high-1) {
        int mid = (low+high)/2;
        if(list[mid] > value) {
            high = mid-1;
        }
        else if(list[mid] == value) {
            return mid;
        }
        else {
            low = mid;
        }
    }
    if(list[high] <= value) {
        return high;
    }
    else if(list[low] <= value) {
        return low;
    }
    else {
        return -1;
    }
}

/* Note: unsigned long long required to avoid overflow errors. How evil. */
int main() {
    ull N = 1E12;
    ull answer = 0;
    ull MOD = 1L<<32;
    auto hamming = get_hamming(N);
    std::vector<ull> hamming_pref;
    for(size_t i = 0; i < hamming.size(); ++i) {
        if(i == 0) {
            hamming_pref.push_back(hamming[i]);
        }
        else {
            hamming_pref.push_back((hamming[i]+hamming_pref[i-1])%MOD);
        }
    }
    std::vector<ull> good_primes;
    for(auto hn : hamming) {
        if(hn <= 5) {
            continue;
        }
        if(isPrime(hn+1)) {
            good_primes.push_back(hn+1);
        }
    }
    std::set<ull> prime_combos{1};
    for(auto gp : good_primes) {
        std::set<ull> new_terms;
        for(auto pc : prime_combos) {
            if(gp*pc > N) {
                break;
            }
            new_terms.insert(gp*pc);
        }
        for(auto nt : new_terms) {
            prime_combos.insert(nt);
        }
    }
    for(auto pc : prime_combos) {
        auto max_hamming = N/pc;
        int index = binary_search(hamming, max_hamming);
        auto to_add = ((hamming_pref[index]%MOD)*(pc%MOD))%MOD;
        answer = (answer+to_add)%MOD;
    }
    std::cout << answer << std::endl;
    return 0;
}