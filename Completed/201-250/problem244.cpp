#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<array>
#include<assert.h>
#include<string>
#include<math.h>
#include<climits>
#include<utility>

typedef long long ll;
typedef long double ld;

std::map<char, std::string> board_neighbors(std::string board_string) {
    size_t w_index = -1;
    std::map<char, std::string> neighbors;
    for(size_t i = 0; i < board_string.length(); ++i) {
        if(board_string[i] == 'w') {
            w_index = i;
            break;
        }
    }
    if(w_index >= 4) {
        std::string neighbor(board_string);
        std::swap(neighbor[w_index], neighbor[w_index-4]);
        neighbors.emplace('D', neighbor);
    }
    if(w_index < 12) {
        std::string neighbor(board_string);
        std::swap(neighbor[w_index], neighbor[w_index+4]);
        neighbors.emplace('U', neighbor);
    }
    if(w_index%4 != 0) {
        std::string neighbor(board_string);
        std::swap(neighbor[w_index], neighbor[w_index-1]);
        neighbors.emplace('R', neighbor);
    }
    if(w_index%4 != 3) {
        std::string neighbor(board_string);
        std::swap(neighbor[w_index], neighbor[w_index+1]);
        neighbors.emplace('L', neighbor);
    }
    return neighbors;
}

std::map<std::string, int> get_distances() {
    std::string initial_state = "wrbbrrbbrrbbrrbb";
    std::map<std::string, int> distances;
    distances[initial_state] = 0;
    std::queue<std::pair<std::string, int>> visit_queue;
    visit_queue.emplace(initial_state, 0);
    while(visit_queue.size()) {
        auto node = visit_queue.front();
        std::string board_string = node.first;
        int dist = node.second;
        visit_queue.pop();
        auto next_boards = board_neighbors(board_string);
        for(auto& board : next_boards) {
            if(!distances.count(board.second)) {
                distances[board.second] = dist+1;
                visit_queue.emplace(board.second, dist+1);
            }
        }
    }
    return distances;
}

std::vector<std::string> get_paths() {
    std::vector<std::string> paths;
    auto distances = get_distances();
    auto dest_distance = distances["wbrbbrbrrbrbbrbr"];

    std::queue<std::string> board_queue;
    std::queue<std::string> path_strings;
    std::queue<int> dist_queue;
    board_queue.push("wbrbbrbrrbrbbrbr");
    path_strings.push("");
    dist_queue.push(dest_distance);

    while(path_strings.size()) {
        auto board = board_queue.front();
        auto path = path_strings.front();
        auto dist = dist_queue.front();
        board_queue.pop();
        path_strings.pop();
        dist_queue.pop();
        if(dist == 0) {
            std::reverse(path.begin(), path.end());
            paths.push_back(path);
            continue;
        }
        auto next_boards = board_neighbors(board);
        for(auto& board : next_boards) {
            if(distances[board.second] >= dist) {
                continue;
            }
            board_queue.push(board.second);
            dist_queue.push(dist-1);
            auto dir = board.first;
            switch(dir) {
                case 'U':
                    path_strings.push(path+'D');
                    break;
                case 'D':
                    path_strings.push(path+'U');
                    break;
                case 'L':
                    path_strings.push(path+'R');
                    break;
                case 'R':
                    path_strings.push(path+'L');
                    break;
            }
        }
    } 
    return paths;
}

ll checksum(std::string& path) {
    ll answer = 0;
    ll MOD = 100000007;
    for(size_t i = 0; i < path.length(); ++i) {
        int char_ascii = path[i];
        answer = (answer*243+char_ascii)%MOD;
    }
    return answer;
}

int main() {
    auto path_strings = get_paths();
    ll answer = 0;
    for(auto& ps : path_strings) {
        answer += checksum(ps);
    }
    std::cout << answer << std::endl;
    return 0;
}