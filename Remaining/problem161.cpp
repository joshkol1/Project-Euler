#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<set>
#include<array>
#include<assert.h>
#include<string>
#include<math.h>
#include<climits>
#include<utility>

typedef long long ll;
typedef long double ld;

std::unordered_map<std::string, ll> tiling_ways;
int height, width;

std::vector<std::string> next_positions(std::string& position, int row, int col) {

}

ll find_ways(std::string& position, int row, int col) {
    ll answer = 0;
}

int main() {
    int width, height;
    std::cin >> width >> height;
    std::string starting_position(width*height, 'o');
    
    return 0;
}