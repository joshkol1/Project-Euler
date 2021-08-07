#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const long double D = 30.403243784;
const long double eps = 1e-12;

long double func(long double x) {
    long double exp_part = floor(pow(2.0L, D-x*x));
    return exp_part*1e-9;
}

int main() {
    long double u = -1;
    long double prev_sum = 0;
    for(int i = 0; ; i++) {
        long double prev_u = u;
        u = func(u);
        if(abs(prev_sum-(prev_u+u)) < eps) {
            cout << setprecision(10) << prev_u+u << "\n";
            break;
        }
        prev_sum = prev_u+u;
    }
    return 0;
}