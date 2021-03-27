#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back

const ll MOD = 50515093;
vector<ll> t_vals;

void gen_lines() {
    ll s = 290797;
    for(int i = 0; i < 20000; i++) {
        s = (s*s)%MOD;
        t_vals.pb(s%500);
    }
}

bool within(ld p_x, ld p_y, ld e1_x, ld e1_y, ld e2_x, ld e2_y) {
    if(e1_x > e2_x) swap(e1_x, e2_x);
    if(e1_y > e2_y) swap(e1_y, e2_y);
    return e1_x < p_x && p_x < e2_x && e1_y < p_y && p_y < e2_y;
}

bool intersects(int i, int j) {
    ll prod1 = (t_vals[i+3]-t_vals[i+1])*(t_vals[j+2]-t_vals[j]);
    ll prod2 = (t_vals[j+3]-t_vals[j+1])*(t_vals[i+2]-t_vals[i]);
    if(prod1 == prod2) return false;
    ld inter_x;
    ld inter_y;
    if(t_vals[i] == t_vals[i+2]) {
        ld m = (t_vals[j+3]-t_vals[j+1]+0.0)/(t_vals[j+2]-t_vals[j]);
        ld b = t_vals[j+1]-m*t_vals[j];
        inter_x = t_vals[i];
        inter_y = inter_x*m+b;
        if(!within(inter_x, inter_y, t_vals[i], t_vals[i+1], t_vals[i+2], t_vals[i+3])) return false;
        if(!within(inter_x, inter_y, t_vals[j], t_vals[j+1], t_vals[j+2], t_vals[j+3])) return false;
        return true;
    }
    else if(t_vals[j] == t_vals[j+2]) {
        ld m = (t_vals[i+3]-t_vals[i+1]+0.0)/(t_vals[i+2]-t_vals[i]);
        ld b = t_vals[i+1]-m*t_vals[i];
        inter_x = t_vals[j];
        inter_y = inter_x*m+b;
        if(!within(inter_x, inter_y, t_vals[i], t_vals[i+1], t_vals[i+2], t_vals[i+3])) return false;
        if(!within(inter_x, inter_y, t_vals[j], t_vals[j+1], t_vals[j+2], t_vals[j+3])) return false;
        return true;
    }
    else {
        ld m1 = (t_vals[i+3]-t_vals[i+1]+0.0)/(t_vals[i+2]-t_vals[i]);
        ld m2 = (t_vals[j+3]-t_vals[j+1]+0.0)/(t_vals[j+2]-t_vals[j]);
        ld b1 = t_vals[i+1]-m1*t_vals[i];
        ld b2 = t_vals[j+1]-m2*t_vals[j];
        inter_x = (b2-b1)/(m1-m2);
        inter_y = m1*inter_x+b1;
    }
    if(!within(inter_x, inter_y, t_vals[i], t_vals[i+1], t_vals[i+2], t_vals[i+3])) return false;
    if(!within(inter_x, inter_y, t_vals[j], t_vals[j+1], t_vals[j+2], t_vals[j+3])) return false;
    //cout << inter_x << " " << inter_y << '\n';
    return true;
}

int main() {
    gen_lines();
    ll ans = 0;
    for(int i = 0; i < 20000; i += 4) {
        for(int j = i+4; j < 20000; j += 4) {
            ans += intersects(i, j);
        }
    }
    cout << ans << "\n";
    return 0;
}