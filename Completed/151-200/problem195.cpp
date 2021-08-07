#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

long double max_product = 2*1053779/sqrt(3);

/*
    TODO: writeup of solution
*/

ll gcd(ll a, ll b) {
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

/*
    Find the primitive solution to diophantine equation a^2-ab+b^2=k^2
    in (a, b). Return the gcd used to compute it.
*/
ll primitive_solution(ll t1, ll t2) {
    ll a = t2*(t2-2*t1);
    ll b = t1*(t1-2*t2);
    ll c = t2*t2-t1*t2+t1*t1;
    ll d = gcd(gcd(a, b), c);
    return d;
}

int main() {
    ll answer = 0;
    for(ll t1 = 2; t1 <= 3*max_product; ++t1) {
        for(ll t2 = -1; -t2*t1 <= 3*max_product && -t2 < t1; --t2) {
            if(abs(gcd(t1, t2)) != 1)
                continue;
            ll d = primitive_solution(t1, t2);
            answer += (ll)(max_product*d/(-t1*t2));
        }
    }
    cout << answer << "\n";
    return 0;
}