#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

set<int> psf_numbers;
const int UB = 1E9;
const int wiggle = 10000000;

int main() {
    auto spf = new int[UB+wiggle];
    for(int i = 2; i < UB+wiggle; ++i)
        spf[i] = i;
    set<int> primes;
    for(int i = 2; i*i < UB+wiggle; ++i) {
        if(spf[i] == i) {
            for(int j = i*i; j < UB+wiggle; j += i) {
                if(spf[j] == j)
                    spf[j] = i;
            }
        }
    }
    for(int i = 2; i < UB+wiggle; ++i) {
        if(spf[i] == i)
            primes.insert(i);
    }
    for(int i = 2; i < UB; ++i) {
        bool admissible = true;
        int n = i;
        auto ptr = primes.begin();
        while(n != 1) {
            int p = spf[n];
            if(p != *ptr) {
                admissible = false;
                break;
            }
            while(n%p == 0)
                n /= p;
            ++ptr;
        }
        if(admissible) {
            auto np_ptr = primes.upper_bound(i);
            if(*np_ptr - i == 1)
                np_ptr = next(np_ptr);
            psf_numbers.insert(*np_ptr-i);
        }
    }
    cout << accumulate(psf_numbers.begin(), psf_numbers.end(), 0LL) << "\n";
    delete[] spf;
    return 0;
}