#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

int guess[] = {20, 31, 38, 39, 40, 42, 45};
vector<int> incs;
string set_string;
set<int> sums;
int min_sum = 2000;

bool check() {
    /*
        Ensure if |B| > |C|, then S(B) > S(C)
    */
    int pref_sum = guess[0];
    int suf_sum = 0;
    for(int i = 1; i < 7; i++) {
        pref_sum += guess[i];
        suf_sum += guess[7-i];
        if(pref_sum < suf_sum) return false;
    }
    /*
        Check that subset sums are distinct
    */
    sums.clear();
    for(int i = 1; i < 1<<7; i++) {
        int subset_sum = 0;
        for(int j = 0; j < 7; j++) {
            if(i&(1<<j)) subset_sum += guess[j];
        }
        if(sums.count(subset_sum) > 0) return false;
        sums.insert(subset_sum);
    }
    return true;
}

void search(int depth) {
    if(depth >= 7) {
        if(check()) {
            int tot = 0;
            for(int i = 0; i < 7; i++) {
                tot += guess[i];
            }
            if(tot < min_sum) {
                min_sum = tot;
                string new_str = "";
                for(int i = 0; i < 7; i++) {
                    new_str += to_string(guess[i]);
                }
                set_string = new_str;
            }
        }
        return;
    }
    for(int inc : incs) {
        guess[depth] += inc;
        search(depth+1);
        guess[depth] -= inc;
    }
}

int main() {
    for(int i = -5; i <= 5; i++) incs.pb(i);
    search(0);
    cout << set_string << "\n";
    return 0;
}