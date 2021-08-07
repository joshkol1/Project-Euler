#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

/*
    Turns out it's just the Fibonacci sequence, 
    the bitstring can't have two consecutive ones.
    
    To show the recurrence, notice that all strings 
    satisfying this are built of 0's or 01's ==>
    build block length n from blocks size 1 or 2, which
    is clearly Fibonacci.

    Oh, and the condition we need to check is if
    n XOR 2n XOR 3n == 0. Nim game
*/

int main() {
    int ans = 0;
    for(ll i = 1; i <= 1L<<32; i++) {
        if((i^(2*i)^(3*i)) == 0) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}