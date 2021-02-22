#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

/*
    Building the Markov chain is annoying. Instead, simulate over a large
    number of rolls and find the 3 most common squares we land on.
*/

const int ROLLS = 1E6;
vector<int> chance;
vector<int> comm_chest;
int freq[40];
int curr_sq;
bool in_jail;
int curr_doubles;
random_device device;
mt19937 generator(device());
uniform_int_distribution<int> distribution(1, 4);

void init_game() {
    for(int i = 1; i <= 16; i++) {
        chance.pb(i); comm_chest.pb(i);
    }
    random_shuffle(chance.begin(), chance.end());
    random_shuffle(comm_chest.begin(), comm_chest.end());
}

/*
    Helper for simulating outcome of roll from current square.
*/
void roll() {
    in_jail = false;
    int r1 = distribution(generator);
    int r2 = distribution(generator);
    if(r1 == r2) curr_doubles++;
    if(curr_doubles >= 3) {
        curr_sq = 10;
        curr_doubles = 0;
        return;
    }
    curr_sq = (curr_sq+r1+r2)%40;
    int draw;
    switch(curr_sq) {
        case 30: curr_sq = 10; in_jail = true; break;
        case 2:
        case 17:
        case 33:
            draw = comm_chest.at(0);
            comm_chest.erase(comm_chest.begin());
            comm_chest.push_back(draw);
            if(draw == 1) {
                curr_sq = 0;
            }
            if(draw == 2) {
                curr_sq = 10; in_jail = true;
            }
            break;
        case 7:
            draw = chance.at(0);
            chance.erase(chance.begin());
            chance.push_back(draw);
            switch(draw) {
                case 1: curr_sq = 0; break;
                case 2: curr_sq = 10; in_jail = true; break;
                case 3: curr_sq = 11; break;
                case 4: curr_sq = 24; break;
                case 5: curr_sq = 39; break;
                case 6: curr_sq = 5; break;
                case 7:
                case 8: curr_sq = 15; break;
                case 9: curr_sq = 12; break;
                case 10: curr_sq = 4; break;
            }
            break;
        case 22:
            draw = chance.at(0);
            chance.erase(chance.begin());
            chance.push_back(draw);
            switch(draw) {
                case 1: curr_sq = 0; break;
                case 2: curr_sq = 10; in_jail = true; break;
                case 3: curr_sq = 11; break;
                case 4: curr_sq = 24; break;
                case 5: curr_sq = 39; break;
                case 6: curr_sq = 5; break;
                case 7:
                case 8: curr_sq = 25; break;
                case 9: curr_sq = 28; break;
                case 10: curr_sq = 19; break;
            }
            break;
        case 36:
            draw = chance.at(0);
            chance.erase(chance.begin());
            chance.push_back(draw);
            switch(draw) {
                case 1: curr_sq = 0; break;
                case 2: curr_sq = 10; in_jail = true; break;
                case 3: curr_sq = 11; break;
                case 4: curr_sq = 24; break;
                case 5: curr_sq = 39; break;
                case 6: curr_sq = 5; break;
                case 7:
                case 8: curr_sq = 5; break;
                case 9: curr_sq = 12; break;
                case 10: 
                    curr_sq = 33;
                    draw = comm_chest.at(0);
                    comm_chest.erase(comm_chest.begin());
                    comm_chest.push_back(draw);
                    if(draw == 1) {
                        curr_sq = 0;
                    }
                    if(draw == 2) {
                        curr_sq = 10; in_jail = true;
                    }
                    break;
            }
            break;
    }
    if(!in_jail && r1 == r2) roll();
    else curr_doubles = 0;
}

int main() {
    init_game();
    for(int i = 0; i < ROLLS; i++) {
        roll();
        freq[curr_sq]++;
    }
    vector<pair<int, int>> result;
    for(int i = 0; i < 40; i++) result.pb({freq[i], i});
    sort(result.begin(), result.end());
    cout << setfill('0') << setw(2);
    for(int i = 39; i >= 37; i--) cout << result.at(i).second;
    cout << "\n";
    return 0;
}