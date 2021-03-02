#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll clues[22];
int n_correct[22];
int current_state[22];
set<int> set_digits;
bool sol_found;
ll solution;

void search(int depth) {
    if(sol_found) return;
    if(depth >= 22) {
        sol_found = true;
        for(int i = 0; i < 22; i++) {
            solution = 10*solution + current_state[i];
        }
        return;
    }
    ll curr_clue = clues[depth];
    if(n_correct[depth] == 0) {
        for(int i = 15; i >= 0; i--) {
            if(curr_clue%10 == current_state[i]) {
                return;
            }
            curr_clue /= 10;
        }
    }
    else if(n_correct[depth] == 1) {
        for(int i = 0; i < 15; i++) {
            
        }
    }
    else if(n_correct[depth] == 2) {

    }
    else {

    }
}

int main() {
    for(int i = 0; i < 22; i++) {
        current_state[i] = -1;
    }
    freopen("p185_clues.txt", "r", stdin);
    for(int i = 0; i < 22; i++) {
        ll clue; int n_c; cin >> clue >> n_c;
    }
    search(0);
    cout << solution << "\n";
    return 0;
}