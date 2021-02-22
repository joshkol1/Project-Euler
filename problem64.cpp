#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double eps = 1e-9;

bool square(int n) {
    double rt = sqrt(n);
    return abs(rt-round(rt)) < eps;
}

long gcd(long a, long b) {
    if(a == 0) return b;
    return gcd(b%a, a);
}

long cf_period(long n) {
    vector<long> seq;
    set<tuple<long, long, long>> seen;
    vector<tuple<long, long, long>> t_seq;
    /*
        Radical expression maintained at each step is
        (a+b*sqrt(n))/c.
    */
    long a = 0;
    long b = 1;
    long c = 1;
    while(true) {
        long fl = (a+b*sqrt(n))/c;
        seq.push_back(fl);
        a -= fl*c;
        long old_c = c;
        c = b*b*n-a*a;
        a *= -old_c;
        b *= old_c;
        long all_gcd = gcd(gcd(a, b), c);
        a /= all_gcd; b /= all_gcd; c /= all_gcd;
        if(seen.count({a, b, c}) > 0) {
            long period = 1;
            auto rit = t_seq.rbegin();
            tuple<long, long, long> des = {a, b, c};
            while(*rit != des) {
                period++; rit++;
            }
            return period;
        }
        seen.insert({a, b, c});
        t_seq.push_back({a, b, c});
    }
    return -1; // Will never reach this
}

int main() {
    int ans = 0;
    for(long i = 2; i <= 10000; i++) {
        if(square(i)) continue;
        ans += (cf_period(i)%2 == 1);
    }
    cout << ans << "\n";
    return 0;
}