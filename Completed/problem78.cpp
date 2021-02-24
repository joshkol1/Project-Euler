#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t bigint;
#define pb push_back

/*
    Source: eq. 20 of https://mathworld.wolfram.com/PartitionFunctionP.html
    
    Suppose p(k) is the partition function of k. Also, assume that
    p(0) = 1 and p(k) = 0 for k < 0. Then, we have the following:

    p(n) = p(n-1)+p(n-2)-p(n-5)-p(n-7)+p(n-12)+p(n-15)-p(n-22)-...
    
    where the values 1, 2, 5, 7, ... are the pentagonal number function 
    k(3k-1)/2 evaluated at 1, -1, 2, -2, 3, -3, ...
*/

const ll MOD = 1E6;
const int MAX_SEARCH = 1E6;
ll part[MAX_SEARCH+1];

int pent(int n) {
    return n*(3*n-1)/2;
}

void compute(int n) {
    for(int i = 1; ; i++) {
        int sign;
        if(i%2 == 0) sign = -1;
        else sign = 1;
        int delta = pent(i);
        if(n-delta < 0) break;
        part[n] += (sign*part[n-delta]); 
        part[n] %= MOD;
        if(part[n] < 0) part[n] += MOD;
        delta = pent(-i);
        if(n-delta < 0) break;
        part[n] += (sign*part[n-delta]); 
        part[n] %= MOD;
        if(part[n] < 0) part[n] += MOD;
    }
}

int main() {
    part[0] = 1;
    for(int i = 1; i <= MAX_SEARCH; i++) {
        compute(i);
        if(part[i] == 0) {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}