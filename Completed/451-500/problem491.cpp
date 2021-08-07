#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

int dig_count[10];
int cumul_digits;
int cumul_sum;
ll total_ways;

void search(int depth) {
    if(depth >= 10) {
        if(cumul_digits != 10) return;
        int other = 90-cumul_sum;
        int diff = cumul_sum-other;
        while(diff < 0) diff += 11;
        if(diff%11 == 0) {
            ll ways = 3628800L*3628800L;
            for(int i = 0; i < 10; i++) {
                if(dig_count[i] == 2 || dig_count[i] == 0) {
                    ways /= 2;
                }
            }
            total_ways += ways;
        }
        return;
    }
    for(int i = 0; i <= 2; i++) {
        if(cumul_digits+i <= 10) {
            dig_count[depth] = i;
            cumul_sum += depth*i;
            cumul_digits += i;
            search(depth+1);
            cumul_digits -= i;
            cumul_sum -= depth*i;
            dig_count[depth] = 0;
        }
    }
}

int main() {
    search(0);
    cout << total_ways/10*9 << "\n";
    return 0;
}