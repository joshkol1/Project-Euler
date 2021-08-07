#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

/*
    We need four functions:
        1. for each k >= 0, # ways from 0 to 9 without touching 9 before end
        2. for each k >= 0, # ways from 9 to 0 without touching 0 before end
        3. for each k >= 0, # paths length k ending at 0, without touching 0 or 9 before
        4. for each k >= 0, # paths length k starting at 9
    Notice that functions 1 and 2 count the same thing.

    There are two types of paths:
        1. Go to 0 (without touching 9), go from 0 to 9, and go from 9 to wherever
        2. Go to 9 (without touching 0), go from 9 to 0, and go from 0 to whevever
*/

size_t n_digits;
ll** bottom_top;
ll** end_zero;
ll** end_nine;
ll** start_nine;

void compute_counts() {
    bottom_top[0][0] = 1;
    for(size_t i = 1; i < n_digits+1; ++i) {
        for(size_t j = 0; j < 10; ++j) {
            if(j == 0) {
                bottom_top[i][j] = bottom_top[i-1][j+1];
            } else if(j == 8 || j == 9) {
                bottom_top[i][j] = bottom_top[i-1][j-1];
            } else {
                bottom_top[i][j] = bottom_top[i-1][j-1] + bottom_top[i-1][j+1];
            }
        }
    }
    for(size_t i = 1; i < 10; ++i)
        end_zero[0][i] = 1;
    for(size_t i = 1; i < n_digits+1; ++i) {
        for(size_t j = 0; j < 9; ++j) {
            if(j == 0 || j == 1) {
                end_zero[i][j] = end_zero[i-1][j+1];
            } else if(j == 8) {
                end_zero[i][j] = end_zero[i-1][j-1];
            } else {
                end_zero[i][j] = end_zero[i-1][j-1] + end_zero[i-1][j+1];
            }
        }
    }
    for(size_t i = 1; i < 10; ++i)
        end_nine[0][i] = 1;
    for(size_t i = 1; i < n_digits+1; ++i) {
        for(size_t j = 1; j < 10; ++j) {
            if(j == 1)
                end_nine[i][j] = end_nine[i-1][j+1];
            else if(j == 9 || j == 8)
                end_nine[i][j] = end_nine[i-1][j-1];
            else
                end_nine[i][j] = end_nine[i-1][j+1] + end_nine[i-1][j-1];
        }
    }
    start_nine[0][9] = 1;
    for(size_t i = 1; i < n_digits+1; ++i) {
        for(size_t j = 0; j < 10; ++j) {
            if(j == 0) {
                start_nine[i][j] = start_nine[i-1][j+1];
            } else if(j == 9) {
                start_nine[i][j] = start_nine[i-1][j-1];
            } else {
                start_nine[i][j] = start_nine[i-1][j-1] + start_nine[i-1][j+1];
            }
        }
    }
}

int main() { 
    cin >> n_digits;
    ll answer = 0;
    while(n_digits > 0) {
        bottom_top = new ll*[n_digits+1];
        end_zero = new ll*[n_digits+1];
        start_nine = new ll*[n_digits+1];
        end_nine = new ll*[n_digits+1];
        for(size_t i = 0; i < n_digits+1; ++i) {
            bottom_top[i] = new ll[10]();
            end_zero[i] = new ll[10]();
            start_nine[i] = new ll[10]();
            end_nine[i] = new ll[10]();
        }
        
        compute_counts();

        vector<ll> forward_paths;
        for(size_t i = 0; i < n_digits+1; ++i) {
            ll sum = accumulate(start_nine[i], start_nine[i]+10, 0L);
            forward_paths.pb(sum);
        }
        for(size_t i = 0; i < n_digits; ++i) {
            for(size_t j = 9; i+j < n_digits; j += 2) {
                ll pand_paths = bottom_top[j][9];
                size_t k = n_digits-1-i-j;
                answer += (end_zero[i][0] + end_nine[i][9])*pand_paths*forward_paths[k];
            }
        }
        for(size_t i = 0; i < n_digits+1; ++i) {
            delete[] bottom_top[i];
            delete[] end_zero[i];
            delete[] start_nine[i];
        }
        delete[] bottom_top;
        delete[] end_zero;
        delete[] start_nine;
        --n_digits;
    }
    cout << answer << "\n";
    return 0;
}