#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

bool used[10];
ll MOD = 1E9;
const long double ROOT5 = sqrtl(5);
const long double PHI = (1+ROOT5)/2;

bool pand_lead(long double leading) {
    for(int i = 1; i < 10; i++) used[i] = false;
    for(int i = 0; i < 9; i++) {
        ll whole = (ll)leading;
        if(whole == 0) return false;
        if(used[whole]) return false;
        used[whole] = true;
        leading -= whole;
        leading *= 10;
    }
    return true;
}

bool pand_trail(ll trail) {
    if(trail < 1E8) return false;
    for(int i = 0; i < 10; i++) used[i] = false;
    while(trail > 0) {
        if(used[trail%10]) return false;
        if(trail%10 == 0) return false;
        used[trail%10] = true;
        trail /= 10;
    }
    return true;
}

int main() {
    ll p_trail = 1;
    ll c_trail = 1;
    for(int i = 3; ; i++) {
        ll temp_trail = c_trail;
        c_trail += p_trail;
        p_trail = temp_trail;
        c_trail %= MOD;
        long double log_Fn = i*log10l(PHI)-log10l(ROOT5);
        long double leading = pow(10, log_Fn-(ll)log_Fn);
        if(pand_trail(c_trail) && pand_lead(leading)) {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}