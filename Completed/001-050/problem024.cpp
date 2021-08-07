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
    vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int p_count = 0;
    do {
        ++p_count;
        if(p_count == 1000000) {
            for(auto d : digits)
                cout << d;
            cout << endl;
            break;
        }
    } while(next_permutation(digits.begin(), digits.end()));
    return 0;
}