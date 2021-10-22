#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<array>
#include<assert.h>
#include<cmath>
typedef long long ll;
typedef long double ld;
#define pb push_back

long double epsilon = 1e-10;

ll gcd(ll a, ll b) {
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

ll lcm(ll a, ll b) {
    return (a/gcd(a, b))*b;
}

std::pair<ll, ll> frac_sum(const std::pair<ll, ll>& f1, const std::pair<ll, ll>& f2) {
    ll den_lcm = lcm(f1.second, f2.second);
    ll sum_num = f1.first*(den_lcm/f1.second)+f2.first*(den_lcm/f2.second);
    ll frac_gcd = gcd(den_lcm, sum_num);
    return {sum_num/frac_gcd, den_lcm/frac_gcd};
}

bool check(ld x, ld y, ld z) {
    if(std::abs(x*x+y*y-z*z) < epsilon)
        return true;
    if(std::abs(x+y-z) < epsilon) 
        return true;
    if(std::abs(1.0L/x+1.0L/y-1.0L/z) < epsilon) 
        return true;
    if(std::abs(1.0L/(x*x)+1.0L/(y*y)-1.0L/(z*z)) < epsilon) 
        return true;
    return false;
}

int main() {
    std::vector<ld> fractions;
    std::vector<std::pair<ll, ll>> full_form;
    std::set<std::pair<ll, ll>> sums;
    for(ll i = 1; i < 35; ++i) {
        for(ll j = i+1; j <= 35; ++j) {
            if(gcd(i, j) != 1)
                continue;
            ld n = i;
            ld d = j;
            fractions.push_back(n/d);
            full_form.push_back({i, j});
        }
    }
    std::pair<ll, ll> distinct_sum = {0, 1};
    for(size_t i = 0; i < fractions.size(); ++i) {
        for(size_t j = i; j < fractions.size(); ++j) {
            for(size_t k = 0; k < fractions.size(); ++k) {
                if(check(fractions[i], fractions[j], fractions[k])) {
                    auto a = full_form[i];
                    auto b = full_form[j];
                    auto c = full_form[k];
                    auto new_sum = frac_sum(frac_sum(a, b), c);
                    if(!sums.count(new_sum)) {
                        sums.insert(new_sum);
                        distinct_sum = frac_sum(distinct_sum, new_sum);
                    }
                }
            }
        }
    }
    std::cout << distinct_sum.first + distinct_sum.second << std::endl;
    return 0;
}