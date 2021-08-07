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
    for(int a = 1; a < 1000; ++a) {
        for(int b = a+1; a+b < 1000; ++b) {
            for(int c = b+1; c < 1000; ++c) {
                if(a+b+c == 1000 && a*a+b*b==c*c) {
                    cout << a*b*c << endl;
                }
            }
        }
    }
    return 0;
}