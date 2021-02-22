#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int matrix[80][80];
int dist[80][80];
bool processed[80][80];
int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool oob(int r, int c) {
    return r < 0 || r >= 80 || c < 0 || c >= 80;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("p083_matrix.txt", "r", stdin);
    for(int i = 0; i < 80; i++) {
        string line; cin >> line;
        size_t pos;
        for(int j = 0; j < 79; j++) {
            int num; pos = line.find(","); 
            num = stoi(line.substr(0, pos));
            matrix[i][j] = num; line.erase(0, pos+1);
            dist[i][j] = INT_MAX;
        }
        matrix[i][79] = stoi(line);
        dist[i][79] = INT_MAX;
    }
    dist[0][0] = matrix[0][0];
    priority_queue<tuple<int, int, int>> q;
    q.push(tuple<int, int, int>(0, 0, 0));
    while(!q.empty()) {
        int r = get<1>(q.top());
        int c = get<2>(q.top());
        q.pop();
        if(processed[r][c]) continue;
        processed[r][c] = true;
        for(int i = 0; i < 4; i++) {
            if(oob(r+dirs[i][0], c+dirs[i][1])) continue;
            int new_r = r+dirs[i][0];
            int new_c = c+dirs[i][1];
            int w = matrix[new_r][new_c];
            if(dist[r][c]+w < dist[new_r][new_c]) {
                dist[new_r][new_c] = dist[r][c]+w;
                q.push(tuple<int, int, int>(-dist[new_r][new_c], new_r, new_c));
            }
        }
    }
    cout << dist[79][79] << "\n";
    return 0;
}