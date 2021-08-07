#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

/*
    We have two decreasing "segments", with the break between the segments 
    being increasing. Suppose we choose k characters for the right segment. 
    Then, we are only in trouble when all right segment values are lower
    than the lowest left segment value. This only happens when we choose
    the k smallest numbers. 
    
    Therefore, the total number of good strings is 
    26Cn * [nC1+...nC(n-1) - (n-1)], where the n-1 comes from the bad strings.
    This simplifies to 26Cn * [2^n-(n+1)] for 1 <= n <= 26.
*/

int main() {
    ll answer = 0;
    ll choose = 1;
    for(ll n = 1; n <= 26; n++) {
        choose = choose*(26-n+1)/n;
        answer = max(answer, choose*((1L<<n)-(n+1)));
    }
    cout << answer << "\n";
    return 0;
}