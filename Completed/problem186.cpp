#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int MAX = 1E8;
const ll MOD = 1E6;
int size[MOD];
int parent[MOD];
ll lag_gen[2*MAX+1];
int calls;

void DSU_init() {
    for(int i = 0; i < MOD; i++) {
        size[i] = 1;
        parent[i] = i;
    }
}

int find(int v) {
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

void un(int v1, int v2) {
    int a = find(v1);
    int b = find(v2);
    if(a == b) return;
    if(a < b) swap(a,b);
    size[a] += size[b];
    parent[b] = a;
}

void call(ll n) {
    ll v1, v2;
    n = 2*n-1;
    if(n <= 55) {
        v1 = (100003-200003*n+300007*n*n*n)%MOD;
    }
    else {
        v1 = (lag_gen[n-24]+lag_gen[n-55])%MOD;
    }
    lag_gen[n] = v1;
    n++;
    if(n <= 55) {
        v2 = (100003-200003*n+300007*n*n*n)%MOD;
    }
    else {
        v2 = (lag_gen[n-24]+lag_gen[n-55])%MOD;
    }
    lag_gen[n] = v2;
    if(v1 == v2) return;
    un(v1, v2);
    calls++;
}

int main() {
    DSU_init();
    for(int i = 1; i <= MAX; i++) {
        call(i);
        if(size[find(524287)] >= 990000) {
            cout << calls << "\n";
            break;
        }
    }
    return 0;
}