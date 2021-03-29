#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

string seq = "UDDDUdddDDUDDddDdDddDDUDDdUUDd";
int L = seq.length();

ll apply_seq(ll n) {
    for(int i = 0; i < L; i++) {
        if(seq[i] == 'D') {
            n *= 3;
        }
        else if(seq[i] == 'd') {
            if((3*n)%2 == 0) return -1;
            n = (3*n+1)/2;
        }
        else {
            if((3*n)%4 != 2) return -1;
            n = (3*n-2)/4;
        }
    }
    return n;
}

int main() {
    reverse(seq.begin(), seq.end());
    for(ll i = 1; i <= 1E10L; i++) {
        ll generated_n = apply_seq(i);
        if(generated_n >= 1E15L) {
            cout << generated_n << "\n";
            break;
        }
    }
    return 0;
}