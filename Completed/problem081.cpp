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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("../problem_inputs/p081_matrix.txt", "r", stdin);
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
    for(int i = 0; i < 80; ++i) {
        for(int j = 0; j < 80; ++j) {
            if(i == 0 && j == 0) {
                dist[i][j] = matrix[0][0];
                continue;
            }
            if(i == 0)
                dist[i][j] = dist[i][j-1]+matrix[i][j];
            else if(j == 0)
                dist[i][j] = dist[i-1][j]+matrix[i][j];
            else
                dist[i][j] = min(dist[i][j-1], dist[i-1][j])+matrix[i][j];
        }
    }
    cout << dist[79][79] << "\n";
    return 0;
}