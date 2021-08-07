#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int MAX = 200000;
int v2[MAX+1];
int v5[MAX+1];

void compute_v2() {
    for(int i = 2; i <= MAX; i++) {
        int i_copy = i;
        while(i_copy > 0) {
            v2[i] += i_copy/2; i_copy /= 2;
        }
    }
}

void compute_v5() {
    for(int i = 5; i <= MAX; i++) {
        int i_copy = i;
        while(i_copy > 0) {
            v5[i] += i_copy/5; i_copy /= 5;
        }
    }
}

int main() {
    compute_v2();
    compute_v5();
    ll ans = 0;
    for(int a = 0; a <= MAX/3; a++) {
        for(int b = a; a+2*b <= MAX; b++) {
            if(v2[MAX]-v2[a]-v2[b]-v2[MAX-a-b] < 12) continue;
            if(v5[MAX]-v5[a]-v5[b]-v5[MAX-a-b] < 12) continue;
            if(a == b || b == MAX-b-a) ans += 3;
            else ans += 6;
        }
    }
    cout << ans << "\n";
    return 0;
}