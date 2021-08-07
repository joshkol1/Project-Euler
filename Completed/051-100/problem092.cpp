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

vector<int> end_value;

int main() {
    end_value = vector<int>(1E7);
    int ans = 0;
    for(int n = 1; n < 1E7; ++n) {
        int n_copy = n;
        while(n_copy != 1 && n_copy != 89) {
            int sq_sum = 0;
            while(n_copy != 0) {
                sq_sum += (n_copy%10)*(n_copy%10);
                n_copy /= 10;
            }
            n_copy = sq_sum;
            if(end_value[n_copy]) {
                n_copy = end_value[n_copy];
                break;
            }
        }
        end_value[n] = n_copy;
        ans += (n_copy == 89);
    }
    cout << ans << endl;
    return 0;
}