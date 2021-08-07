#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back

/*
    Area of triangle as proportion of L-section
*/
ld tri_area(int n) {
    ld x = (1+1.0/n-sqrt(2.0/n))/(1+1.0/(n*n));
    ld y = 1-sqrt(2*x-x*x);
    ld slice_area = (1-x)-(1-y)*(1-x)/2-asin(1-x)/2+x*y/2;
    return 4*slice_area/(4-M_PI);
}

int main() {
    for(int i = 1; ; i++) {
        if(tri_area(i) < 0.001) {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}