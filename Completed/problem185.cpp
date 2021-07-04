#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

vector<string> clues;
const int clue_length = 16;
vector<int> correct_digits;
vector<int> set_number;
bool solution_found = false;

/*
    Woul setting set_number[ind] to digit cause a contradiction?
*/
bool set_contradiction(size_t ind, int digit, bool** candidate) {
    bool conflict = set_number[ind] != -1 && set_number[ind] != digit;
    bool not_candidate = !candidate[ind][digit];
    return conflict || not_candidate;
}

/*
    Process clue # index
*/
void process_clue(size_t index, bool** candidate) {
    if(solution_found)
        return;
    if(index >= clues.size()) {
        for(size_t i = 0; i < clue_length; ++i) {
            if(set_number[i] != -1) 
                cout << set_number[i];
            else {
                for(size_t j = 0; j < 10; ++j) {
                    if(candidate[i][j]) {
                        cout << j;
                        break;
                    }
                }
            }
        }
        cout << "\n";
        solution_found = true;
        return;
    }
    // Choose which indices are correct
    if(correct_digits[index] == 0) {
        for(size_t i = 0; i < clue_length; ++i) {
            int digit = clues[index][i] - '0';
            // Contradiction, every single digit should be wrong
            if(set_number[i] == digit)
                return;
        }
        vector<int> modified_indices;
        vector<int> modified_digits;
        for(size_t i = 0; i < clue_length; ++i) {
            int digit = clues[index][i] - '0';
            if(candidate[i][digit]) {
                modified_indices.pb(i);
                modified_digits.pb(digit);
                candidate[i][digit] = false;
            }
        }
        process_clue(index+1, candidate);
        for(size_t i = 0; i < modified_indices.size(); ++i) {
            int ind = modified_indices[i];
            int dig = modified_digits[i];
            candidate[ind][dig] = true;
        }
    } else if(correct_digits[index] == 1) {
        // Which digit is correct? Set index i to same as clue
        for(size_t i = 0; i < clue_length; ++i) {
            // Check that selecting digit as correct leads to no
            // contradictions
            bool okay = true;
            vector<int> modified_indices;
            vector<int> modified_digits;
            for(size_t j = 0; j < clue_length; ++j) {
                int digit = clues[index][j] - '0';
                if(j == i) {
                    if(set_contradiction(j, digit, candidate)) {
                        okay = false;
                        break;
                    }
                } else {
                    if(set_number[j] == digit) {
                        okay = false;
                        break;
                    }
                    if(candidate[j][digit]) {
                        modified_indices.pb(j);
                        modified_digits.pb(digit);
                    }
                }
            }
            if(!okay)
                continue;
            auto prev_i = set_number[i];
            set_number[i] = clues[index][i] - '0';
            for(size_t j = 0; j < modified_indices.size(); ++j) {
                int ind = modified_indices[j];
                int dig = modified_digits[j];
                candidate[ind][dig] = false;
            }
            process_clue(index+1, candidate);
            for(size_t j = 0; j < modified_indices.size(); ++j) {
                int ind = modified_indices[j];
                int dig = modified_digits[j];
                candidate[ind][dig] = true;
            }
            set_number[i] = prev_i;
        }
    } else if(correct_digits[index] == 2) {
        // Set indices i and j to same as clue
        for(size_t i = 0; i < clue_length; ++i) {
            for(size_t j = i+1; j < clue_length; ++j) {
                // Check for contradictions
                bool okay = true;
                vector<int> modified_indices;
                vector<int> modified_digits;
                for(size_t k = 0; k < clue_length; ++k) {
                    int digit = clues[index][k] - '0';
                    if(k == i || k == j) {
                        if(set_contradiction(k, digit, candidate)) {
                            okay = false;
                            break;
                        }
                    } else {
                        if(set_number[k] == digit) {
                            okay = false;
                            break;
                        }
                        if(candidate[k][digit]) {
                            modified_indices.pb(k);
                            modified_digits.pb(digit);
                        }
                    }
                }
                if(!okay)
                    continue;
                auto prev_i = set_number[i];
                set_number[i] = clues[index][i] - '0';
                auto prev_j = set_number[j];
                set_number[j] = clues[index][j] - '0';
                for(size_t k = 0; k < modified_indices.size(); ++k) {
                    int ind = modified_indices[k];
                    int dig = modified_digits[k];
                    candidate[ind][dig] = false;
                }
                process_clue(index+1, candidate);
                for(size_t k = 0; k < modified_indices.size(); ++k) {
                    int ind = modified_indices[k];
                    int dig = modified_digits[k];
                    candidate[ind][dig] = true;
                }
                set_number[i] = prev_i;
                set_number[j] = prev_j;
            }
        }
    } else {
        for(size_t i = 0; i < clue_length; ++i) {
            for(size_t j = i+1; j < clue_length; ++j) {
                for(size_t k = j+1; k < clue_length; ++k) {
                    // Check for contradictions
                    bool okay = true;
                    vector<int> modified_indices;
                    vector<int> modified_digits;
                    for(size_t l = 0; l < clue_length; ++l) {
                        int digit = clues[index][l] - '0';
                        if(l == i || l == j || l == k) {
                            if(set_contradiction(l, digit, candidate)) {
                                okay = false;
                                break;
                            }
                        } else {
                            if(set_number[l] == digit) {
                                okay = false;
                                break;
                            }
                            if(candidate[l][digit]) {
                                modified_indices.pb(l);
                                modified_digits.pb(digit);
                            }
                        }
                    }
                    if(!okay)
                        continue;
                    auto prev_i = set_number[i];
                    set_number[i] = clues[index][i] - '0';
                    auto prev_j = set_number[j];
                    set_number[j] = clues[index][j] - '0';
                    auto prev_k = set_number[k];
                    set_number[k] = clues[index][k] - '0';
                    for(size_t l = 0; l < modified_indices.size(); ++l) {
                        int ind = modified_indices[l];
                        int dig = modified_digits[l];
                        candidate[ind][dig] = false;
                    }
                    process_clue(index+1, candidate);
                    for(size_t l = 0; l < modified_indices.size(); ++l) {
                        int ind = modified_indices[l];
                        int dig = modified_digits[l];
                        candidate[ind][dig] = true;
                    }
                    set_number[i] = prev_i;
                    set_number[j] = prev_j;
                    set_number[k] = prev_k;
                }
            }
        }
    }
}

int main() {
    freopen("../problem_inputs/p185_clues.txt", "r", stdin);
    string clue;
    while(cin >> clue) {
        clues.pb(clue);
        int n_correct; cin >> n_correct;
        correct_digits.pb(n_correct);
    }
    auto candidate = new bool*[clue_length];
    for(size_t i = 0; i < clue_length; ++i)
        candidate[i] = new bool[10];
    for(size_t i = 0; i < clue_length; ++i) {
        for(size_t j = 0; j < 10; ++j) {
            candidate[i][j] = true;
        }
    }
    for(size_t i = 0; i < clue_length; ++i)
        set_number.pb(-1);
    process_clue(0, candidate);
    for(int i = 0; i < clue_length; ++i)
        delete[] candidate[i];
    delete[] candidate;
    return 0;
}