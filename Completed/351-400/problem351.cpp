#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<array>
#include<assert.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int N = 1E8;
int spf[N+1];

void get_spf() {
    for(int i = 1; i < N; ++i) {
        if(i%2 == 0) {
            spf[i] = 2;
        }
        else {
            spf[i] = i;
        }
    }
    for(int i = 3; i*i <= N; i += 2) {
        if(spf[i] == i) {
            for(int j = i*i; j <= N; j += 2*i) {
                if(spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

int totient(int n) {
    int answer = n;
    while(n != 1) {
        auto p = spf[n];
        answer = answer/p*(p-1);
        while(n%p == 0) {
            n /= p;
        }
    }
    return answer;
}

int main() {
    get_spf();
    ll answer = 0;
    for(int d = 2; d <= N/2; ++d) {
        auto t = totient(d);
        answer += t*(N/d-1);
    }
    answer = 6*answer+6*(N-1);
    std::cout << answer << std::endl;
    return 0;
}