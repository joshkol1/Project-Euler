#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<array>
#include<assert.h>
#include<string>
#include<math.h>
#include<climits>
#include<utility>
#include<functional>
#include<numeric>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back

typedef pair<int, int> Pair;

vector<Pair> get_pf(int n) {
    vector<Pair> pf;
    for(int i = 2; i*i <= n; ++i) {
        int p_exp = 0;
        while(n%i == 0) {
            ++p_exp;
            n /= i;
        }
        if(p_exp) 
            pf.pb({i, p_exp});
    }
    if(n != 1)
        pf.pb({n, 1});
    return pf;
}

int main() {
    vector<vector<Pair>> found_pfs;
    for(int a = 2; a <= 100; ++a) {
        auto pf = get_pf(a);
        for(int b = 2; b <= 100; ++b) {
            vector<Pair> new_pf;
            for(auto& p : pf) 
                new_pf.pb({p.first, p.second*b});
            bool duplicate = false;
            if(find(found_pfs.begin(), found_pfs.end(), new_pf) == found_pfs.end())
                found_pfs.pb(new_pf);
        }
    }
    cout << found_pfs.size() << endl;
    return 0;
}