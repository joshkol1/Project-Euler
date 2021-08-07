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

bool contains(string pass, string login) {
    size_t login_index = 0;
    for(size_t i = 0; i < pass.length(); ++i) {
        if(login_index >= login.length()) 
            return true;
        if(pass[i] == login[login_index])
            ++login_index;
    }
    return login_index >= login.length();
}

int main() {
    (void)!freopen("../problem_inputs/p079_keylog.txt", "r", stdin);
    vector<string> logins;
    string login;
    while(cin >> login)
        logins.pb(login);
    for(int pass = 1000; ; ++pass) {
        auto pass_string = to_string(pass);
        bool good = true;
        for(auto s : logins) {
            if(!contains(pass_string, s)) {
                good = false;
                break;
            }
        }
        if(good) {
            cout << pass << endl;
            break;
        }
    }
    return 0;
}