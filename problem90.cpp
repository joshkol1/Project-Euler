#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const double eps = 1e-9;

set<int> d1;
set<int> d2;
int sols;
set<int> curr_squares;

bool square(int n) {
    double d = sqrt(n);
    return abs(round(d)-d) < eps;
}

void process() {
    curr_squares.clear();
    for(int i : d1) {
        for(int j : d2) {
            int v1 = 10*i+j; int v2 = 10*j+i;
            if(square(v1) && v1 > 0) curr_squares.insert(v1);
            if(square(v2) && v2 > 0) curr_squares.insert(v2);
        }
    }
    if(curr_squares.size() == 9) sols++;
}

bool gen_dice(int s1, int s2) {
    d1.clear(); d2.clear();
    for(int i = 0; i < 10; i++) {
        if(s1&(1<<i)) d1.insert(i);
        if(s2&(1<<i)) d2.insert(i);
    }
    if(d1.size() != 6 || d2.size() != 6) return false;
    if(d1.count(6) > 0) d1.insert(9);
    if(d1.count(9) > 0) d1.insert(6);
    if(d2.count(6) > 0) d2.insert(9);
    if(d2.count(9) > 0) d2.insert(6);
    return true;
}

int main() {
    for(int i = 0; i < 1<<10; i++) {
        for(int j = i; j < 1<<10; j++) {
            if(gen_dice(i, j)) process();
        }
    }
    cout << sols << "\n";
    return 0;
}