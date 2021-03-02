#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_VAL = 1000000;
int ch[MAX_VAL+1];
bool seen[MAX_VAL+1];
bool isPrime[MAX_VAL+1];
set<int> n_chain;
int best_chain_len;
int best_chain_low;

/* 
    Initialize the Sieve of Eratosthenes for numbers up to MAX_VAL
    isPrime[i] is true when i is prime, false otherwise.
*/
void init_sieve() {
    memset(isPrime, true, sizeof isPrime);
    isPrime[1] = false;
    for(int i = 2; i <= MAX_VAL; i++) {
        if(isPrime[i]) {
            for(int j = 2*i; j <= MAX_VAL; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

/*
    Fast computation of sum of divisors. If n = p1^e1*p2^e2*...*pn^en,
    then s_divisors(n) = (1+p1+...+p1^e1)(1+p2+...+p2^e2)...(1+pn+...+pn^en)
*/
int s_divisors(int n) {
    if(n == 1 || isPrime[n]) return 1;
    int ans = 1; int init_n = n;
    for(int i = 2; i*i <= n; i++) {
        int prime_sum = 1;
        while(n%i == 0) {
            n /= i;
            prime_sum = i*prime_sum+1;
        }
        ans *= prime_sum;
        if(isPrime[n]) {
            ans *= (n+1);
            break;
        }
    }
    return ans - init_n;
}

int main() {
    init_sieve();
    for(int i = 1; i <= MAX_VAL; i++) {
        set<int> gen; //  Set of generated numbers
        vector<int> seq; // Sequence of generated numbers
        int cur_n = i;
        while(gen.count(cur_n) == 0 && !seen[cur_n] && cur_n <= MAX_VAL) {
            gen.insert(cur_n);
            seq.push_back(cur_n);
            cur_n = s_divisors(cur_n);
        }
        /*
            If we hit a bad value (seen or too big) then mark all #'s 
            in sequence as seen, since they lead to bad chain
        */
        if(cur_n > MAX_VAL || seen[cur_n]) {
            for(int g : gen) seen[g] = true;
            continue;
        }
        int count = 1;
        int smallest = cur_n;
        for(int j = seq.size()-1; j >= 0 && seq.at(j) != cur_n; j--) {
            count++;
            seen[seq.at(j)] = true;
            smallest = min(smallest, seq.at(j));
        }
        if(count > best_chain_len) {
            best_chain_len = count;
            best_chain_low = smallest;
        }
    }
    cout << best_chain_low << "\n";
    return 0;
}