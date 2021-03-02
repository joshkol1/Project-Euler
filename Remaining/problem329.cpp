#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 500;
vector<int> moves;
bool prime[MAX+1];
int curr_square;
int weight_pow = 0;
string croaks = "PPPPNNPPPNPPNPN";
long double tree_prob = 0.002;
long double total_prob;

void init_sieve() {
    memset(prime, true, sizeof prime);
    prime[1] = false;
    for(int i = 2; i <= MAX; i++) {
        if(prime[i]) {
            for(int j = 2*i; j <= MAX; j += i) {
                prime[j] = false;
            }
        }
    }
}

void search(int depth) {
    if(croaks[depth] == 'P') {
        if(prime[curr_square]) {
            tree_prob *= 2.0/3;
        }
        else {
            tree_prob *= 1.0/3;
        }
    }
    else {
        if(prime[curr_square]) {
            tree_prob *= 1.0/3;
        }
        else {
            tree_prob *= 2.0/3;
        }
    }
    if(depth >= 15) {
        total_prob += tree_prob;
        return;
    }
    if(curr_square == 1) {

    }   
    else if(curr_square == MAX) {

    }
    else {

    }  
}

int main() {
    init_sieve();
    for(int i = 1; i <= MAX; i++) {
        curr_square = i;
        search(0);
    }
    return 0;
}