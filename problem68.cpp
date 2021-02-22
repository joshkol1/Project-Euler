#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> nums;
string best_string;
int order[5][3] = {{0,5,6}, {1,6,7}, {2,7,8}, {3,8,9}, {4,9,5}};

bool check() {
    int sum = nums.at(0)+nums.at(5)+nums.at(6);
    for(int i = 1; i < 5; i++) {
        int new_sum = 0;
        for(int j = 0; j < 3; j++) {
            new_sum += nums.at(order[i][j]);
        }
        if(new_sum != sum) return false;
    }
    return true;
}

string build_string() {
    string ans = "";
    int lowest_outer = 0;
    for(int i = 1; i < 5; i++) {
        if(nums.at(order[i][0]) < nums.at(order[lowest_outer][0])) {
            lowest_outer = i;
        }
    }
    for(int i = lowest_outer; i < 5; i++) {
        for(int j = 0; j < 3; j++) {
            ans += to_string(nums.at(order[i][j]));
        }
    }
    for(int i = 0; i < lowest_outer; i++) {
        for(int j = 0; j < 3; j++) {
            ans += to_string(nums.at(order[i][j]));
        }
    }
    return ans;
}

int main() {
    for(int i = 1; i <= 10; i++) {
        nums.push_back(i);
    }
    do {
        if(check()) {
            string new_string = build_string();
            if(new_string.length() == 16) {
                best_string = max(best_string, new_string);
            }
        }
    } while(next_permutation(nums.begin(), nums.end()));
    cout << best_string << "\n";
    return 0;
}