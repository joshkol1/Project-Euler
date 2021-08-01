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
    int sq_sum = 0;
    int sum_sq = 0;
    for(int i = 1; i <= 100; ++i) {
        sq_sum += i*i;
        sum_sq += i;
    }
    sum_sq *= sum_sq;
    cout << abs(sq_sum-sum_sq) << endl;
    return 0;
}