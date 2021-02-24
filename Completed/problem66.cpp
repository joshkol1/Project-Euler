#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t bigint;
#define pb push_back

/*
    Proof of correctness of algorithm found in Theorem 2.6 of: 
    http://www.math.uchicago.edu/~may/VIGRE/VIGRE2008/REUPapers/Yang.pdf
    
    Also, see: https://en.wikipedia.org/wiki/Continued_fraction,
    in particular the section "Infinite continued fractions and convergents",
    which contains the recurrence relation for convergents.

    This problem, due to integer size limits, would be better solved in 
    Python.
*/

const double eps = 1e-9;
const ll MAX_VALUE = 1000;

bool square(ll n) {
    double rt = sqrt(n);
    return abs(rt-round(rt)) < eps;
}

ll gcd(ll a, ll b) {
    if(a == 0) return b;
    return gcd(b%a, a);
}

void print_bigint(bigint n) {
    string ans = "";
    while(n > 0) {
        ans += (char)(n%10+'0');
        n /= 10;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}

bigint minimal_x(ll n) {
    vector<ll> seq;
    set<tuple<ll, ll, ll>> seen;
    vector<tuple<ll, ll, ll>> t_seq;
    /*
        Radical expression maintained at each step is
        (a+b*sqrt(n))/c.
    */
    ll a = 0;
    ll b = 1;
    ll c = 1;
    while(true) {
        ll fl = (a+b*sqrt(n))/c;
        seq.pb(fl);
        a -= fl*c;
        ll old_c = c;
        c = b*b*n-a*a;
        a *= -old_c;
        b *= old_c;
        /* 
            Note: If we don't simplify the radical expressions, they often
            become too big for long long. Sheer luck that they fit when
            simplified in the first place?
        */
        ll all_gcd = gcd(gcd(a, b), c);
        a /= all_gcd; b /= all_gcd; c /= all_gcd;
        /*
            Below happens if we find period. We already have all necessary
            terms from expansion in seq, compute the convergent from them.
        */
        if(seen.count({a, b, c}) > 0) {
            long period = 1;
            auto rit = t_seq.rbegin();
            tuple<long, long, long> des = {a, b, c};
            while(*rit != des) {
                period++; rit++;
            }
            /*
                If we have an odd period, we need to add another cycle
            */
            if(period%2 != 0) {
                ll s = seq.size();
                for(ll i = period; i >= 1; i--) seq.pb(seq.at(s-i));
            }
            /* 
                Need to maintain two previous convergents at each step.
                Recurrence: If convergent is h_n/k_n, then
                (h/k)_n = a_n*(h/k)_(n-1)+(h/k)_(n-2)
            */
            bigint h_prev = seq.at(0);
            bigint k_prev = 1;
            bigint h_curr = seq.at(0)*seq.at(1)+1;
            bigint k_curr = seq.at(1);
            for(uint i = 2; i < seq.size()-1; i++) {
                bigint h_temp = h_curr; bigint k_temp = k_curr;
                h_curr = h_curr*seq.at(i)+h_prev;
                k_curr = k_curr*seq.at(i)+k_prev;
                h_prev = h_temp; k_prev = k_temp;
            }
            return h_curr;
        }
        seen.insert({a, b, c});
        t_seq.pb({a, b, c});
    }
    return -1; // Will never reach this
}

int main() {
    bigint largest_x = 0;
    ll D = 0;
    for(ll i = 2; i <= MAX_VALUE; i++) {
        if(square(i)) continue;
        bigint sol_x = minimal_x(i);
        if(sol_x > largest_x) {
            largest_x = sol_x;
            D = i;
        }
    }
    cout << D << "\n";
    return 0;
}