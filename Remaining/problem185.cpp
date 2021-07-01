#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

vector<string> clues;
vector<int> n_correct;
set<char>* candidates;
char* state;
int n_clues;
int clue_len;
int n_set;

void search(int depth) {
    if(depth == 2) {
        for(int i = 0; i < clue_len; i++) {
            cout << ((state[i]) ? state[i] : '_');
        }
        cout << "\n";
    }
    if(n_set == clue_len) {
        for(int c = depth; c < n_clues; c++) {
            int c_correct = 0;
            for(int i = 0; i < clue_len; i++) {
                c_correct += (state[i] == clues[c][i]);
            }
            if(c_correct != n_correct[c]) return;
        }
        for(int i = 0; i < clue_len; i++) {
            cout << state[i];
        }
        cout << "\n"; return;
    }
    string clue = clues[depth];
    if(n_correct[depth] == 0) {
        for(int a = 0; a < clue_len; a++) {
            if(state[a] == clue[a]) return;
        }
        vector<bool> modified;
        for(int a = 0; a < clue_len; a++) {
            modified.pb(candidates[a].count(clue[a]) > 0);
            candidates[a].erase(clue[a]);
        }
        search(depth+1);
        for(int a = 0; a < clue_len; a++) {
            if(modified[a]) candidates[a].insert(clue[a]);
        }
    }
    if(n_correct[depth] == 1) {
        // i: index of correct char in clue
        for(int i = 0; i < clue_len; i++) {
            if(candidates[i].count(clue[i]) == 0) continue;
            bool valid = true;
            for(int a = 0; a < clue_len; a++) {
                if(a == i && state[a] != 0 && state[a] != clue[a]) {
                    valid = false; break;
                }
                if(a != i && state[a] != 0 && state[a] == clue[a]) {
                    valid = false; break;
                }
            }
            if(!valid) continue;
            bool state_modified = (state[i] == 0); 
            n_set += state_modified;
            vector<bool> modified;
            state[i] = clue[i];
            for(int a = 0; a < clue_len; a++) {
                if(a == i) {
                    modified.pb(false); continue;
                }
                modified.pb(candidates[a].count(clue[a]) > 0);
                candidates[a].erase(clue[a]);
            }
            search(depth+1);
            if(state_modified) state[i] = 0;
            for(int a = 0; a < clue_len; a++) {
                if(modified[a]) candidates[a].insert(clue[a]);
            }
            n_set -= state_modified;
        }
    }
    if(n_correct[depth] == 2) {
        for(int i = 0; i < clue_len; i++) {
            for(int j = i+1; j < clue_len; j++) {
                if(candidates[i].count(clue[i]) == 0) continue;
                if(candidates[j].count(clue[j]) == 0) continue;
                bool valid = true;
                for(int a = 0; a < clue_len; a++) {
                    if(a == i && state[a] != 0 && state[a] != clue[a]) {
                        valid = false; break;
                    }
                    if(a == j && state[a] != 0 && state[a] != clue[a]) {
                        valid = false; break;
                    }
                    if(a != i && a != j && state[a] != 0 && state[a] == clue[a]) {
                        valid = false; break;
                    }
                }
                if(!valid) continue;
                bool first_modified = (state[i] == 0);
                bool second_modified = (state[j] == 0);
                n_set += (first_modified+second_modified);
                vector<bool> modified;
                state[i] = clue[i]; state[j] = clue[j];
                for(int a = 0; a < clue_len; a++) {
                    if(a == i || a == j) {
                        modified.pb(false); continue;
                    }
                    modified.pb(candidates[a].count(clue[a]) > 0);
                    candidates[a].erase(clue[a]);
                }
                search(depth+1);
                if(first_modified) state[i] = 0;
                if(second_modified) state[j] = 0;
                for(int a = 0; a < clue_len; a++) {
                    if(modified[a]) candidates[a].insert(clue[a]);
                }
                n_set -= (first_modified+second_modified);
            }
        }
    }
    if(n_correct[depth] == 3) {
        for(int i = 0; i < clue_len; i++) {
            for(int j = i+1; j < clue_len; j++) {
                for(int k = j+1; k < clue_len; k++) {
                    if(candidates[i].count(clue[i]) == 0) continue;
                    if(candidates[j].count(clue[j]) == 0) continue;
                    if(candidates[k].count(clue[k]) == 0) continue;
                    bool valid = true;
                    for(int a = 0; a < clue_len; a++) {
                        if(a == i && state[a] != 0 && state[a] != clue[a]) {
                            valid = false; break;
                        }
                        if(a == j && state[a] != 0 && state[a] != clue[a]) {
                            valid = false; break;
                        }
                        if(a == k && state[a] != 0 && state[a] != clue[a]) {
                            valid = false; break;
                        }
                        if(a != i && a != j && a != k && state[a] != 0 && state[a] == clue[a]) {
                            valid = false; break;
                        }
                    }
                    if(!valid) continue;
                    bool first_modified = (state[i] == 0);
                    bool second_modified = (state[j] == 0);
                    bool third_modified = (state[k] == 0);
                    n_set += (first_modified+second_modified+third_modified);
                    vector<bool> modified;
                    state[i] = clue[i]; state[j] = clue[j]; state[k] = clue[k];
                    for(int a = 0; a < clue_len; a++) {
                        if(a == i || a == j || a == k) {
                            modified.pb(false); continue;
                        }
                        modified.pb(candidates[a].count(clue[a]) > 0);
                        candidates[a].erase(clue[a]);
                    }
                    search(depth+1);
                    if(first_modified) state[i] = 0;
                    if(second_modified) state[j] = 0;
                    if(third_modified) state[k] = 0;
                    for(int a = 0; a < clue_len; a++) {
                        if(modified[a]) candidates[a].insert(clue[a]);
                    }
                    n_set -= (first_modified+second_modified+third_modified);
                }
            }
        }
    }
}

int main() {
    freopen("../problem_inputs/p185_clues.txt", "r", stdin);
    string line;
    while(cin >> line) {
        clues.pb(line);
        int n; cin >> n; n_correct.pb(n);
    }
    n_clues = clues.size();
    clue_len = clues[0].length();
    state = new char[clue_len];
    candidates = new set<char>[clue_len];
    for(int i = 0; i < clue_len; i++) {
        for(char c = '0'; c <= '9'; c++) {
            candidates[i].insert(c);
        }
    }
    search(0);
    return 0;
}