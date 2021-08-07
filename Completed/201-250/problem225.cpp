#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

using triplet = tuple<int, int, int>;
set<triplet> found;

int main() {
    int good_found = 0;
    for(int mod = 27; ; mod += 2) {
        found.clear();
        int first, second, third;
        first = second = third = 1;
        bool good = true;
        while(!found.count(triplet{first, second, third})) {
            found.insert(triplet{first, second, third});
            int next = (first+second+third)%mod;
            if(next == 0) {
                good = false;
                break;
            }
            first = second;
            second = third;
            third = next;
        }
        if(good) {
            ++good_found;
            if(good_found == 124) {
                cout << mod << "\n";
                break;
            }
        }
    }
    return 0;
}