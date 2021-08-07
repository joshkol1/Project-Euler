#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 200;
int min_moves[MAX+1];
vector<int> found;
set<int> found_set;
int max_depth;

int bin_moves(int n) {
    int count = 0;
    int digs = -1;
    int cp = n;
    while(cp > 0) {
        count += (cp&1); cp >>= 1; digs++;
    }
    return (count-1)+digs;
}

void search(int n, int depth) {
    if(depth >= min_moves[n]) return;

    int moves_left = min_moves[n]-depth;
    int max_v = *found_set.rbegin();
    if(max_v<<moves_left < n) return;
    
    int bag_size = found.size();
    for(int i = 0; i < bag_size; i++) {
        for(int j = i; j < bag_size; j++) {
            int s = found[i]+found[j];
            if(s == n) {
                min_moves[n] = min(min_moves[n], depth+1);
                return;
            }
            if(found_set.count(s) > 0) continue;
            if(s < *found_set.rbegin()) continue;
            found.push_back(s);
            found_set.insert(s);
            search(n, depth+1);
            found.pop_back();
            found_set.erase(s);
        }
    }
}

int main() {
    found_set.insert(1); found.push_back(1);
    for(int i = 2; i <= MAX; i++) {
        max_depth = bin_moves(i);
        min_moves[i] = max_depth;
        search(i, 0);
    }
    int ans = 0;
    for(int i = 2; i <= MAX; i++) {
        ans += min_moves[i];
    }
    cout << ans << "\n";
    return 0;
}