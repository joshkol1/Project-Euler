#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const string moves = "PPPPNNPPPNPPNPN";
ll DENOM = 500;
bool prime[501];
bool moves_prime[15];
int mismatches;
int forced;
ll outcomes;
int curr_square;

ll gcd(ll n1, ll n2) {
    if(n1 == 0) return n2;
    return gcd(n2%n1, n1);
}

bool isPrime(ll n) {
    for(int i = 2; i*i <= n; i++) {
        if(n%i == 0) return false;
    }
    return true;
}

void init() {
    prime[1] = false;
    for(int i = 2; i <= 500; i++) {
        prime[i] = isPrime(i);
    }
    for(int i = 0; i < 15; i++) {
        moves_prime[i] = (moves[i] == 'P');
    }
    for(int i = 0; i < 15; i++) DENOM *= 6;
}

void search(int depth) {
    if(depth >= 15) {
        outcomes += 1<<(15+forced-mismatches);
        return;
    }
    /*
        square and croak don't match
    */
    if(prime[curr_square]^moves_prime[depth]) {
        mismatches++;
    }
    if(curr_square == 1) {
        forced++;
        curr_square++;
        search(depth+1);
        curr_square--;
        forced--;
    }
    else if(curr_square == 500) {
        forced++;
        curr_square--;
        search(depth+1);
        curr_square++;
        forced--;
    }
    else {
        curr_square--;
        search(depth+1);
        curr_square++;
        curr_square++;
        search(depth+1);
        curr_square--;
    }
    if(prime[curr_square]^moves_prime[depth]) {
        mismatches--;
    }
}

int main() {
    init();
    for(int i = 1; i <= 500; i++) {
        curr_square = i;
        search(0);
    }
    ll frac_gcd = gcd(DENOM, outcomes);
    cout << outcomes/frac_gcd << "/" << DENOM/frac_gcd << "\n";
    return 0;
}