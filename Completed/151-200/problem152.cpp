#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<array>
#include<assert.h>
using namespace std;
typedef long long ll;
#define pb push_back

ll gcd(ll a, ll b) {
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

ll lcm(ll a, ll b) {
    return a/gcd(a, b)*b;
}

bool prime(ll n) {
    if(n == 1)
        return false;
    else if(n == 2)
        return true;
    else if(n%2 == 0)
        return false;
    for(ll i = 3; i*i <= n; i += 2) {
        if(n%i == 0)
            return false;
    }
    return true;
}

struct Frac{
    ll num, den;

    Frac(ll num = 0, ll den = 0) : num(num), den(den) {}

    void simplify() {
        if(num == 0) {
            den = 1;
            return;
        }
        ll cf = gcd(num, den);
        num /= cf;
        den /= cf;
    }

    Frac operator+(const Frac& f2) const {
        ll cd = lcm(den, f2.den);
        ll new_num = num*(cd/den) + f2.num*(cd/f2.den);
        ll cf = gcd(new_num, cd);
        return Frac(new_num/cf, cd/cf);
    }

    Frac operator-(const Frac& f2) const {
        ll cd = lcm(den, f2.den);
        ll new_num = num*(cd/den) - f2.num*(cd/f2.den);
        ll cf = gcd(new_num, cd);
        return Frac(new_num/cf, cd/cf);
    }

    void operator+=(const Frac& f2) {
        Frac frac_sum = *this + f2;
        num = frac_sum.num;
        den = frac_sum.den;
        simplify();
    }

    void operator-=(const Frac& f2) {
        Frac frac_sum = *this - f2;
        num = frac_sum.num;
        den = frac_sum.den;
        simplify();
    }

    bool operator<(const Frac& f2) {
        ll common_den = lcm(den, f2.den);
        return (common_den/den)*num < (common_den/f2.den)*f2.num;
    }

    bool operator==(const Frac& f2) {
        ll common_den = lcm(den, f2.den);
        return (common_den/den)*num == (common_den/f2.den)*f2.num;
    }

    friend ostream& operator<<(ostream& os, const Frac& f) {
        os << f.num << "/" << f.den;
        return os;
    }
};

vector<ll> candidates;
vector<ll> post_sums;
ll cands_lcm = 1;
ll n_ways;

void search(size_t index, ll current_sum) {
    if(current_sum > cands_lcm/2)
        return;
    if(current_sum == cands_lcm/2) {
        ++n_ways;
        return;
    }
    if(index >= candidates.size())
        return;
    if(current_sum+post_sums[index] < cands_lcm/2)
        return;
    search(index+1, current_sum);
    search(index+1, current_sum+candidates[index]);
}

int main() {
    set<ll> possible_denominators;
    for(ll i = 2; i <= 80; ++i)
        possible_denominators.insert(i);
    for(ll i = 79; i >= 5; i -= 2) {
        if(!prime(i)) 
            continue;
        vector<Frac> fractions;
        for(int j = 1; i*j <= 80; ++j) {
            if(possible_denominators.count(i*j) > 0) 
                fractions.emplace_back(1, i*i*j*j);
        }
        size_t n = fractions.size();
        // bitwise subsets
        bool good = false;
        for(size_t j = 1; j < 1u<<n; ++j) {
            Frac sum = {0, 1};
            for(size_t k = 0; k < n; ++k) {
                if(j&(1<<k)) {
                    sum += fractions[k];
                    sum.simplify();
                }
            }
            if(sum.den%i != 0) {
                good = true;
                break;
            }
        }
        if(!good || i == 13) {
            for(int j = 1; i*j <= 80; ++j)
                possible_denominators.erase(i*j);
        }
    }
    for(auto& d : possible_denominators) {
        candidates.pb(d*d);
        cands_lcm = lcm(cands_lcm, d*d);
        if(d == 12)
            candidates.pb(d*d);
    }
    for(size_t i = 0; i < candidates.size(); ++i) 
        candidates[i] = cands_lcm/candidates[i];
    post_sums = vector<ll>(candidates.size());
    for(size_t i = candidates.size(); i-- > 0; ) {
        if(i == candidates.size()-1)
            post_sums[i] = candidates[i];
        else
            post_sums[i] = post_sums[i+1]+candidates[i];
    }
    search(0, 0);
    cout << n_ways << "\n";
    return 0;
}