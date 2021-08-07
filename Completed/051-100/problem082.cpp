#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<array>
#include<assert.h>
#include<string>
#include<math.h>
#include<climits>
#include<utility>
#include<functional>
#include<numeric>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back

int matrix[80][80];
int dist[80][80];
bool processed[80][80];
int dirs[3][2] = {{1, 0}, {-1, 0}, {0, 1}};

bool oob(int r, int c) {
    return r < 0 || r >= 80 || c < 0 || c >= 80;
}

int main() {
    (void)!freopen("../../problem_inputs/p082_matrix.txt", "r", stdin);
    for(int i = 0; i < 80; i++) {
        string line; cin >> line;
        size_t pos;
        for(int j = 0; j < 79; j++) {
            int num; pos = line.find(","); 
            num = stoi(line.substr(0, pos));
            matrix[i][j] = num; line.erase(0, pos+1);
        }
        matrix[i][79] = stoi(line);
    }
    int ans = INT_MAX;
    for(int i = 0; i < 80; ++i) {
        for(int j = 0; j < 80; ++j) {
            for(int k = 0; k < 80; ++k) {
                dist[j][k] = INT_MAX;
                processed[j][k] = false;
            }
        }
        dist[i][0] = matrix[i][0];
        priority_queue<tuple<int, int, int>> q;
        q.push({0, i, 0});
        while(!q.empty()) {
            auto r = get<1>(q.top());
            auto c = get<2>(q.top());
            q.pop();
            if(processed[r][c]) 
                continue;
            processed[r][c] = true;
            for(int i = 0; i < 4; i++) {
                if(oob(r+dirs[i][0], c+dirs[i][1])) 
                    continue;
                auto new_r = r+dirs[i][0];
                auto new_c = c+dirs[i][1];
                auto w = matrix[new_r][new_c];
                if(dist[r][c]+w < dist[new_r][new_c]) {
                    dist[new_r][new_c] = dist[r][c]+w;
                    q.push({-dist[new_r][new_c], new_r, new_c});
                }
            }
        }
        for(int j = 0; j < 80; ++j)
            ans = min(ans, dist[j][79]);
    }
    cout << ans << endl;
    return 0;
}