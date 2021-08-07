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

int gcd(int a, int b) {
    return (a == 0) ? b : gcd(b%a, a);
}

int main() {
    int prod_num = 1;
    int prod_den = 1;
    for(int num = 11; num <= 99; ++num) {
        if(num%10 == 0)
            continue;
        for(int den = num+1; den <= 99; ++den) {
            if(den%10 == 0)
                continue;
            if((num%10 == den%10) && num*(den/10) == den*(num/10)) {
                prod_num *= num;
                prod_den *= den;
                break;
            }
            if((den/10 == num/10) && num*(den%10) == den*(num%10)) {
                prod_num *= num;
                prod_den *= den;
                break;
            }
            if((den%10 == num/10) && num*(den/10) == den*(num%10)) {
                prod_num *= num;
                prod_den *= den;
                break;
            }
            if((den/10 == num%10) && num*(den%10) == den*(num/10)) {
                prod_num *= num;
                prod_den *= den;
                break;
            }
        }
    }
    cout << prod_den/gcd(prod_num, prod_den) << endl;
    return 0;
}