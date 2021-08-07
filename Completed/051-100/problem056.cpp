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

vector<int> multiply(vector<int>& n1, vector<int>& n2) {
    vector<int> ans(n1.size()+n2.size()-1);
    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());
    for(size_t index = 0; index < n1.size()+n2.size()-1; ++index) {
        int prod = 0;
        for(size_t n1_index = 0; n1_index < min(index+1, n1.size()); ++n1_index) {
            if(index-n1_index >= n2.size())
                continue;
            auto n2_index = index-n1_index;
            prod += n1[n1_index]*n2[n2_index];
        }
        ans[index] = prod;
    }
    for(size_t index = 0; index < ans.size()-1; ++index) {
        if(ans[index] >= 10) {
            ans[index+1] += ans[index]/10;
            ans[index] %= 10;
        }
    }
    while(ans[ans.size()-1] >= 10) {
        ans.pb(ans[ans.size()-1]/10);
        ans[ans.size()-2] %= 10;
    }
    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int ans = 0;
    for(int a = 1; a < 100; ++a) {
        for(int b = 1; b < 100; ++b) {
            vector<int> a_vec = {a/10, a%10};
            vector<int> prod = {1};
            for(int e = 0; e < b; ++e)
                prod = multiply(a_vec, prod);
            ans = max(ans, accumulate(prod.begin(), prod.end(), 0));
        }
    }
    cout << ans << endl;
    return 0;
}