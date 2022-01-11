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

char fib_string_digit(std::string A, std::string B, ll index) {
    ll a_len = A.length();
    ll b_len = B.length();
    std::vector<ll> lengths{a_len, b_len};
    while(*lengths.rbegin() < index) {
        lengths.push_back(lengths[lengths.size()-1]+lengths[lengths.size()-2]);
    }
    size_t in_index = lengths.size()-1;
    while(in_index > 1) {
        ll first_length = lengths[in_index-2];
        if(index > first_length) {
            index -= first_length;
            --in_index;
        }
        else {
            in_index -= 2;
        }
    }
    return (in_index == 0) ? A[index-1] : B[index-1];
}

int main() {
    std::string answer = "";
    std::string A = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
    std::string B = "8214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196";
    ll seven_pow = 1;
    for(ll n = 0; n <= 17; ++n) {
        answer += fib_string_digit(A, B, (127+19*n)*seven_pow);
        seven_pow *= 7;
    }
    std::reverse(answer.begin(), answer.end());
    std::cout << answer << std::endl;
    return 0;
}