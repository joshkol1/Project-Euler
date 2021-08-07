#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

int ways[61];
vector<int> endings;

void init_ways() {
    for(int i = 1; i <= 20; i++) {
        ways[i]++; ways[2*i]++; ways[3*i]++;
        endings.pb(2*i);
    }
    ways[25]++; ways[50]++;
    endings.pb(50);
}

int main() {
    init_ways();
    for(int e : endings) {
        cout << e << " ";
    }
    cout << "\n";
    int total_ways = 0;
    for(int s = 2; s < 100; s++) {
        for(int e : endings) {
            if(e == s) total_ways+=2;
            for(int i = 1; i <= 60; i++) {
                if(i+e == s) {
                    total_ways += 2*ways[i];
                }
            }
            for(int i = 1; i <= 60; i++) {
                for(int j = 1; j <= 60; j++) {
                    if(i+j+e == s) {
                        if(i == j) {
                            total_ways += ways[i];
                        }
                        total_ways += ways[i]*ways[j];
                    }
                }
            }
        }
    }
    cout << total_ways/2 << "\n";
    return 0;
}