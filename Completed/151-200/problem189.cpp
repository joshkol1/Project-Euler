#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

/*
    Index i: how many ways to color triangle with
    2*i+1 cells in bottom row, with given color string?
*/
vector<map<string, ll>> colorings;

/*
    Given top row s1 and bottom row s2, do the 
    colorings conflict?
*/
bool conflicts(string s1, string s2) {
    int l1= s1.length();
    for(int i = 0; i < l1; i += 2) {
        if(s1[i] == s2[i+1]) return true;
    }
    return false;
}

void compute_colorings(int f_length, string b_row) {
    int row_n = (f_length-1)/2;
    if(row_n == 0) {
        colorings[0][b_row] = 1;
        return;
    }
    colorings[row_n][b_row] = 0;
    for(auto const& p : colorings[row_n-1]) {
        if(conflicts(p.first, b_row)) continue;
        colorings[row_n][b_row] += p.second;
    }
}

void gen_strings(int max_rows) {
    queue<string> rows;
    rows.push("r");
    rows.push("g");
    rows.push("b");
    while(!rows.empty()) {
        string row = rows.front(); rows.pop();
        int len = row.length();
        if(len <= 2*max_rows-1) {
            compute_colorings(len, row);
            if(len < 2*max_rows-1) {
                if(row[len-1] != 'r') {
                    rows.push(row + "rb");
                    rows.push(row + "rg");
                }
                if(row[len-1] != 'g') {
                    rows.push(row + "gb");
                    rows.push(row + "gr");
                }
                if(row[len-1] != 'b') {
                    rows.push(row + "bg");
                    rows.push(row + "br");
                }
            }
        }
    }
}

int main() {
    for(int i = 0; i < 8; i++) {
        map<string, ll> new_map;
        colorings.pb(new_map);
    }
    gen_strings(8);
    ll ans = 0;
    for(auto const& p : colorings[7]) ans += p.second;
    cout << ans << "\n";
    return 0;
}