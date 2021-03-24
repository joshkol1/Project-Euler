#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int SIDES = 12;
const int NUM_DICE = 20;
const int TOP = 10;
const int TOP_SUM = 70;

int counts[SIDES+1];
int cumul_total;

ll fact[NUM_DICE+1];
ll ways_answer;

void init_fact() {
    fact[0] = 1;
    ll p = 1;
    for(ll i = 1; i <= NUM_DICE; i++) {
        p *= i;
        fact[i] = p;
    }
}

bool check() {
    int dice = 0;
    int d_sum = 0;
    for(int i = SIDES; i >= 1; i--) {
        if(dice+counts[i] > TOP) {
            d_sum += (TOP-dice)*i;
            break;
        }
        d_sum += counts[i]*i;
        dice += counts[i];
    }
    return d_sum == TOP_SUM;
}

void search(int depth) {
    if(depth == SIDES) {
        counts[SIDES] = NUM_DICE-cumul_total;
        if(check()) {
            ll ways_add = fact[NUM_DICE];
            for(int i = SIDES; i >= 1; i--) {
                ways_add /= fact[counts[i]];
            }
            ways_answer += ways_add;
        }
        return;
    }
    for(int i = 0; i <= NUM_DICE-cumul_total; i++) {
        counts[depth] = i;
        cumul_total += i;
        search(depth+1);
        cumul_total -= i;
    }
}

int main() {
    init_fact();
    search(1);
    cout << ways_answer << "\n";
    return 0;
}