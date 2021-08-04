#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<array>
#include<assert.h>
#include<string>
#include<math.h>
#include<climits>
#include<utility>
#include<functional>
#include<numeric>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back

bool prime(int n) {
    if(n == 1)
        return false;
    if(n == 2)
        return true;
    if(n%2 == 0)
        return false;
    for(int i = 3; i*i <= n; ++i) {
        if(n%i == 0)
            return false;
    }
    return true;
}

vector<int> primes_below(int n) {
    vector<int> answer;
    if(n <= 2)
        return answer;
    answer.pb(2);
    for(int p = 3; p < n; p += 2) {
        if(prime(p))
            answer.pb(p);
    }
    return answer;
}

size_t max_terms(vector<int>& nums, int bound) {
    size_t ans = 0;
    int sum = 0;
    for(size_t i = 0; ans < bound; ++i) {
        if(sum+nums[i] < bound)
            sum += nums[i];
        else
            break;
        ++ans;
    }
    return ans;
}

int main() {
    int bound = 1000000;
    auto primes = primes_below(1000000);
    auto terms_ub = max_terms(primes, bound);
    bool found= false;
    for(int n_terms = terms_ub; n_terms > 1 && !found; --n_terms) {
        int start_sum = 0;
        for(size_t i = 0; i < n_terms; ++i)
            start_sum += primes[i];
        for(size_t i = n_terms; start_sum < bound; ++i) {
            if(prime(start_sum)) {
                cout << start_sum << endl;
                found = true;
                break;
            }
            start_sum += primes[i];
            start_sum -= primes[i-n_terms];
        }
    }
    return 0;
}