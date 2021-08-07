#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back

const ld epsilon = 1e-15;
const ld target = -6E11;

ld S(ld r) {
    ld scale = 1/(1-r);
    ld r_power = pow(r, 5000);
    ld inside = (897 + 14100*r_power-3*scale*(r-r_power));
    return scale*inside;
}

int main() {
    ld lb = 1.002;
    ld ub = 1.003;
    while(abs(lb-ub) > epsilon) {
        ld mid = (lb+ub)/2;
        if(S(mid) < target) {
            ub = mid;
        } else {
            lb = mid;
        }
    }
    cout << setprecision(15) << (ub+lb)/2 << "\n";
    return 0;
}