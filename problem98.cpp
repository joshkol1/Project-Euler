#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string whole_file;
map<string, vector<string>> word_bags;
map<char, int> digit_mapping;
int best_square;

bool anagram(string s1, string s2) {
    if(s1.length() != s2.length()) return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    for(uint i = 0; i < s1.length(); i++) {
        if(s1[i] != s2[i]) return false;
    }
    return true;
}

bool valid(string w, int sq) {
    digit_mapping.clear();
    set<int> used;
    for(int i = w.length()-1; i >= 0; i--) {
        if(i == 0 && sq == 0) return false;
        int digit = sq%10;
        char c = w[i];
        if(digit_mapping.count(c)) {
            if(digit != digit_mapping[c]) {
                return false;
            }
        }
        else {
            if(used.count(digit) > 0) return false;
            used.insert(digit);
            digit_mapping[c] = digit;
        }
        sq /= 10;
    }
    return true;
}

int construct(string w2) {
    if(digit_mapping[w2[0]] == 0) return -1;
    int ans = 0;
    for(uint i = 0; i < w2.length(); i++) {
        ans = 10*ans+digit_mapping[w2[i]];
    }
    return ans;
}

bool is_square(int n) {
    double rt = sqrt(n);
    return abs(rt-round(rt)) < 1e-8;
}

void process(string w1, string w2) {
    int len = w1.length();
    int min_square = 1;
    for(int i = 0; i < len-1; i++) min_square *= 10;
    int max_square = 10*min_square-1;
    int low = ceil(sqrt(min_square));
    int high = sqrt(max_square);
    for(int i = low; i <= high; i++) {
        int square = i*i;
        if(valid(w1, square)) {
            int sq2 = construct(w2);
            if(is_square(sq2)) {
                cout << "Words: (" << w1 << ", " << w2 << "), ";
                cout << "Numbers: (" << square << ", " << sq2 << ")\n";
                best_square = max(best_square, max(square, sq2));
            }
        }
    }
}

int main() {
    freopen("p098_words.txt", "r", stdin);
    cin >> whole_file;
    stringstream s_stream(whole_file);
    while(s_stream.good()) {
        string word; getline(s_stream, word, ',');
        word = word.substr(1, word.length()-2);
        bool found = false;
        for(auto const& wb : word_bags) {
            if(anagram(wb.first, word)) {
                found = true;
                word_bags[wb.first].push_back(word);
                break;
            }
        }
        if(!found) {
            vector<string> new_wb;
            new_wb.push_back(word);
            word_bags.insert({word, new_wb});
        }
    }
    for(auto const& wb : word_bags) {
        vector<string> bag = word_bags[wb.first];
        int n_words = bag.size();
        if(n_words <= 1) continue;
        for(int i = 0; i < n_words; i++) {
            for(int j = i+1; j < n_words; j++) {
                string w1 = bag.at(i);
                string w2 = bag.at(j);
                process(w1, w2);
            }
        }
    }
    cout << "Largest square: " << best_square << "\n";
    return 0;
}