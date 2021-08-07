#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<array>
#include<assert.h>
#include<math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back

const ld epsilon = 1e-12;

/*
    y-value of bottom half of circle at x
*/
ld lower_circle(ld x) {
    if(abs(x) < epsilon || abs(x-0.5) < epsilon)
        return 0.5;
    assert(0 <= x && x <= 0.5);
    return 0.5-sqrt(0.0625-(x-0.25)*(x-0.25));
}

/*
    Integrating the bottom half of circle centered at (1/4, 1/2) from
    a to b, with N slices for Simpson integration
*/
ld lc_integral(ld a, ld b, int N=1000) {
    ld ans = 0;
    ld dx = (b-a)/N;
    for(int i = 0; i < N; ++i) {
        ld low = a+dx*i;
        ld high = a+dx*(i+1);
        ans += dx/6*(lower_circle(low)+4*lower_circle((low+high)/2)+lower_circle(high));
    }
    return ans;
}

/*
    Value of blancmange curve at x
*/
ld blanc(ld x) {
    int n = 0;
    ld ans = 0;
    ld two_pow;
    while((two_pow = pow(2.0L, -n)) > epsilon) {
        ld num = x*(1L<<n);
        ans += abs(num-round(num))*two_pow;
        ++n;
    }
    return ans;
}

/*
    Integral of blancmange curve from 0 to x
*/
ld blanc_integral(ld x) {
    if(abs(x) < epsilon)
        return 0;
    else if(abs(x-0.5) < epsilon)
        return 0.25;
    else if(abs(x-1) < epsilon)
        return 0.5;
    else {
        assert(0 <= x && x <= 1);
        if(0 <= x && x <= 0.5)
            return (x*x)/2+blanc_integral(2*x)/4;
        else
            return 0.5-blanc_integral(1-x);
    }
}

/*
    Calculate intersection of circle and blancmange via binary search
*/  
void find_intersection(ld* inter_x) {
    ld lb = 0;
    ld ub = 0.25;
    while(ub-lb > epsilon) {
        ld mid = (lb+ub)/2;
        ld circle_low = lower_circle(mid);
        ld blanc_point = blanc(mid);
        if(circle_low > blanc_point) 
            lb = mid;
        else
            ub = mid;
    }
    *inter_x = ub;
}

int main() {
    ld inter_x;
    find_intersection(&inter_x);
    ld blanc_area = blanc_integral(0.5) - blanc_integral(inter_x);
    ld lc_area = lc_integral(inter_x, 0.5, 1000000);
    cout << setprecision(8) << blanc_area-lc_area << "\n";
    return 0;
}