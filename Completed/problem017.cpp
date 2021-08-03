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
    vector<int> ones = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3};
    vector<int> teens = {0, 6, 6, 8, 8, 7, 7, 9, 8, 8};
    vector<int> tens = {0, 3, 6, 6, 5, 5, 5, 7, 6, 6};
    int ans = 11;
    for(int n = 1; n < 1000; ++n) {
        int count = 0;
        if(n%100 <= 10)
            count += ones[n%100];
        else if(11 <= n%100 && n%100 <= 19)
            count += teens[n%10];
        else
            count += tens[(n/10)%10]+ones[n%10];
        if(n >= 100) {
            count += ones[n/100] + 7;
            if(n%100 != 0)
                count += 3;
        }
        ans += count;
    }
    cout << ans << endl;
    return 0;
}