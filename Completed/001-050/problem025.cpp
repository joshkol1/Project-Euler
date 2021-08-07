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

int main() {
    vector<int> a = {1};
    vector<int> b = {1};
    int index = 2;
    while(b.size() < 1000) {
        while(a.size() < b.size())
            a.pb(0);
        auto new_f = vector<int>(b.size());
        transform(b.begin(), b.end(), a.begin(), new_f.begin(), plus<int>());
        for(size_t i = 0; i < new_f.size()-1; ++i) {
            if(new_f[i] >= 10) {
                new_f[i+1] += (new_f[i]/10);
                new_f[i] %= 10;
            }
        }
        if(new_f[new_f.size()-1] >= 10) {
            new_f.push_back(new_f[new_f.size()-1]/10);
            new_f[new_f.size()-2] %= 10;
        }
        a = b;
        b = new_f;
        ++index;
    }
    cout << index << endl;
    return 0;
}