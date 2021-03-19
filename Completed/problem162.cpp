#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back

/*
    We can count the complement and then subtract
    from the total number of <=16 digit hex strings.
    The complement is hex string with at least one 
    of 0, 1, A missing. We can use the principle of
    inclusion-exclusion to count this:

    Let f(n) = # n digit hex strings with at least one
    of 0, 1, A missing. Then,
    f(n) = #(n digit string with no 0)+#(... no 1)
    +#(... no A)-#(... no 0 and 1)-#(... no 0 and A)
    -#(... no 1 and A)+#(... no 0, 1 and A)
    
    Sum f(n) from n=1 to 16, and subtract from 
    16^16-1 (exclude zero).
*/

int main() {
    ull ans = ULLONG_MAX;
    ull p13 = 1;
    ull p14 = 1;
    ull p15 = 1;
    for(int i = 0; i < 16; i++) {
        ans -= (43*p15-41*p14+13*p13);
        p13 *= 13; p14 *= 14; p15 *= 15;
    }
    cout << uppercase << hex << ans << "\n";
    return 0;
}