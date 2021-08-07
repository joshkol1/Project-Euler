#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int MAX = 1E6;
int drs[MAX];
int mdrs[MAX];

void init_drs() {
    for(int i = 2; i < MAX; i++) {
        if(i < 10) {
            drs[i] = i; continue;
        }
        int i_copy = i;
        int d_sum = 0;
        while(i_copy >= 10) {
            while(i_copy > 0) {
                d_sum += (i_copy%10);
                i_copy /= 10;
            }
            i_copy = d_sum;
            d_sum = 0;
        }
        drs[i] = i_copy;
    }
}

void compute(int num) {
    bool prime = true;
    mdrs[num] = drs[num];
    for(int i = 2; i*i <= num; i++) {
        if(num%i != 0) continue;
        prime = false;
        mdrs[num] = max(mdrs[num], drs[i]+mdrs[num/i]);
        mdrs[num] = max(mdrs[num], drs[num/i]+mdrs[i]);
    }
    if(prime) {
        mdrs[num] = drs[num];
    }
}

int main() {
    init_drs();
    ll mdrs_total = 0;
    for(int i = 2; i < MAX; i++) {
        compute(i); mdrs_total += mdrs[i];
    }
    cout << mdrs_total << "\n";
    return 0;
}