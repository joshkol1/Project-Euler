#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

int next_val[64];
bool visited[64];
ll ways[65];

/*
    ways[i]: # ways to color cycle of length i with 
    black/white such that no two blacks are consecutive
*/
void init_ways() {
    ways[1] = 1;
    ways[2] = 3;
    for(int i = 3; i <= 64; i++) {
        ways[i] = ways[i-1]+ways[i-2];
    }
}

/*
    Get the successor of n after applying transformation
*/
void compute_next(int n) {
    int result = 0;
    result += (n&31)<<1;
    int a = (n&32)>>5;
    int b = (n&16)>>4;
    int c = (n&8)>>3;
    result += a^(b&c);
    next_val[n] = result;
}

/*
    Return the size of the cycle that n is in
*/
int cycle_length(int n) {
    int cycle_size = 1;
    int start = next_val[n];
    while(start != n) {
        visited[start] = true;
        start = next_val[start];
        cycle_size++;
    }
    return cycle_size;
}

int main() {
    init_ways();
    ll ans = 1;
    for(int i = 0; i <= 63; i++) {
        compute_next(i);
    }
    for(int i = 0; i < 64; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        ans *= ways[cycle_length(i)];
    }
    cout << ans << "\n";
    return 0;
}