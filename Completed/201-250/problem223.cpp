#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<array>
#include<assert.h>
#include<cstring>
#include<math.h>
#include<climits>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back

typedef pair<size_t, size_t> Pair;

size_t N;
size_t* spf;

// Initialize smallest prime factor & totient array
void init() {
    spf = new size_t[N+1];
    for(size_t i = 1; i <= N; ++i) {
        if(i%2 == 0)    
            spf[i] = 2;
        else
            spf[i] = i;
    }
    for(size_t i = 2; i*i <= N; ++i) {
        if(spf[i] == i) {
            for(size_t j = i*i; j <= N; j += i) {
                if(spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

// Get prime factorization of a^2-1
vector<Pair> get_factors(size_t a) {
    vector<Pair> answer;
    auto m = a+1;
    auto n = a-1;
    size_t two_pow = 0;
    while(m%2 == 0) {
        m /= 2;
        ++two_pow;
    }
    while(n%2 == 0) {
        n /= 2;
        ++two_pow;
    }
    if(two_pow)
        answer.pb({2, two_pow});
    while(m != 1) {
        auto p = spf[m];
        size_t p_exp = 0;
        while(m%p == 0) {
            m /= p;
            ++p_exp;
        }
        answer.pb({p, p_exp});
    }
    while(n != 1) {
        auto p = spf[n];
        size_t p_exp = 0;
        while(n%p == 0) {
            n /= p;
            ++p_exp;
        }
        answer.pb({p, p_exp});
    }
    return answer;
}

void search_factors(size_t cf, vector<Pair>& v, size_t& ans, size_t a) {
    if(v.size() == 0) {
        auto a_sq = a*a-1;
        if((cf < a) || ((cf-a_sq/cf)&1))
            return;
        auto c = (cf+a_sq/cf)/2;
        auto b = (cf-a_sq/cf)/2;
        if(a <= b && b <= c && a+b+c <= N)
            ++ans;
        return;
    }
    auto f = v[v.size()-1];
    v.pop_back();
    size_t p_pow = 1;
    for(size_t i = 0; i <= f.second; ++i) {
        search_factors(cf*p_pow, v, ans, a);
        p_pow *= f.first;
    }
    v.push_back(f);
}

int main() {
    cin >> N;
    init();
    size_t ans = (N-1)/2;
    for(size_t a = 2; a <= N/3; ++a) {
        auto factorization = get_factors(a);
        search_factors(1, factorization, ans, a);
    }
    cout << ans << endl;
    return 0;
}