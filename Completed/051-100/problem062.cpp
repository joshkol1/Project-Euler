#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
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

vector<string> get_cubes(size_t n_digits) {
    vector<string> ans;
    for(ll i = 1; ; ++i) {
        auto num = to_string(i*i*i);
        if(num.length() > n_digits)
            break;
        if(num.length() == n_digits)
            ans.pb(num);
    }
    return ans;
}

int main() {
    bool found = false;
    for(size_t n_digits = 1; !found ; ++n_digits) {
        auto nums = get_cubes(n_digits);
        map<string, vector<string>> perms;
        for(auto n : nums) {
            auto n_copy(n);
            sort(n_copy.begin(), n_copy.end());
            if(perms.find(n_copy) == perms.end())
                perms.insert({n_copy, vector<string>()});
            perms[n_copy].push_back(n);
        }
        for(auto& p : perms) {
            if(p.second.size() >= 5) {
                cout << p.second[0] << endl;
                found = true;
                break;
            }
        }
    }
    return 0;
}