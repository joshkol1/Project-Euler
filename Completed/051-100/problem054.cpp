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

typedef pair<int, char> Card;
typedef vector<Card> Hand;

Card get_card(std::string card) {
    int value;
    char suit;
    switch(card[0]) {
        case 'T':
            value = 9;
            break;
        case 'J':
            value = 10;
            break;
        case 'Q':
            value = 11;
            break;
        case 'K':
            value = 12;
            break;
        case 'A':
            value = 13;
            break;
        default:
            value = card[0] - '1';
    }
    suit = card[1];
    return {value, suit};
}

bool compare_hands(Hand& h1, Hand& h2) {
    sort(h1.begin(), h1.end());
    sort(h2.begin(), h2.end());
    auto royal_flush = [&](Hand& h) {
        auto suit = h[0].second;
        for(auto c : h) {
            if(c.second != suit)
                return false;
        }
        for(int i = 0; i < 5; ++i) {
            if(h[i].first != 9+i)
                return false;
        }
        return true;
    };
    auto r1 = royal_flush(h1);
    auto r2 = royal_flush(h2);
    if(r1 && !r2)
        return false;
    if(!r1 && r2)
        return true;
    auto straight_flush = [&](Hand& h) {
        for(size_t i = 0; i < 4; ++i) {
            if(h[i].first != h[i+1].first-1)
                return 0;
            if(h[i].second != h[i+1].second)
                return 0;
        }
        return h[4].first;
    };
    auto sf1 = straight_flush(h1);
    auto sf2 = straight_flush(h2);
    if(sf1 < sf2)
        return true;
    if(sf1 > sf2)
        return false;
    auto four_kind = [&](Hand& h) {
        size_t start = (h[0].first == h[1].first) ? 0 : 1;
        for(size_t i = start; i < start+3; ++i) {
            if(h[i].first != h[i+1].first)
                return 0;
        }
        auto singleton = (start == 0) ? h[4].first : h[0].first;
        return 14*h[start].first+singleton;
    };
    auto four1 = four_kind(h1);
    auto four2 = four_kind(h2);
    if(four1 < four2)
        return true;
    if(four1 > four2)
        return false;
    auto full_house = [&](Hand& h) {
        if(h[0] != h[1] || h[3] != h[4])
            return 0;
        if(h[2] != h[1] && h[2] != h[3])
            return 0;
        auto trip = (h[1] == h[2]) ? h[0].first : h[4].first;
        auto doub = (h[1] == h[2]) ? h[4].first : h[0].first;
        return trip*14+doub;
    };
    auto fh1 = full_house(h1);
    auto fh2 = full_house(h2);
    if(fh1 < fh2)
        return true;
    if(fh1 > fh2)
        return false;
    auto flush = [&](Hand& h) {
        for(size_t i = 0; i < 4; ++i) {
            if(h[i].second != h[i+1].second)
                return false;
        }
        return true;
    };
    auto fl1 = flush(h1);
    auto fl2 = flush(h2);
    if(!fl1 && fl2)
        return true;
    if(fl1 && !fl2)
        return false;
    if(fl1 && fl2) {
        for(size_t i = 5; i-- > 0; ) {
            if(h1[i].first < h2[i].first)
                return true;
            if(h1[i].first > h2[i].first)
                return false;
        }
    }
    auto straight = [&](Hand& h) {
        for(size_t i = 0; i < 4; ++i) {
            if(h[i].first != h[i+1].first-1)
                return 0;
        }
        return h[0].first;
    };
    auto st1 = straight(h1);
    auto st2 = straight(h2);
    if(st1 < st2)
        return true;
    if(st1 > st2)
        return false;
    auto three_kind = [&](Hand& h) {
        if(h[0].first == h[1].first && h[1].first == h[2].first)
            return (h[0].first)*196+(h[4].first)*14+h[3].first;
        if(h[1].first == h[2].first && h[2].first == h[3].first)
            return (h[1].first)*196+(h[4].first)*14+h[0].first;
        if(h[2].first == h[3].first && h[3].first == h[4].first)
            return (h[2].first)*196+(h[1].first)*14+h[0].first;
        return 0;
    };
    auto tk1 = three_kind(h1);
    auto tk2 = three_kind(h2);
    if(tk1 < tk2)
        return true;
    if(tk1 > tk2)
        return false;
    auto two_pairs = [&](Hand& h) {
        if(h[0].first == h[1].first && h[2].first == h[3].first)
            return 196*(h[2].first)+14*(h[0].first)+h[4].first;
        if(h[0].first == h[1].first && h[3].first == h[4].first)
            return 196*(h[3].first)+14*(h[0].first)+h[2].first;
        if(h[1].first == h[2].first && h[3].first == h[4].first)
            return 196*(h[3].first)+14*(h[1].first)+h[0].first;
        return 0;
    };
    auto tp1 = two_pairs(h1);
    auto tp2 = two_pairs(h2);
    if(tp1 < tp2)
        return true;
    if(tp1 > tp2)
        return false;
    auto one_pair = [&](Hand& h) {
        for(size_t i = 0; i < 5; ++i) {
            for(size_t j = i+1; j < 5; ++j) {
                if(h[i].first == h[j].first)
                    return h[i].first;
            }
        }
        return 0;
    };
    auto op1 = one_pair(h1);
    auto op2 = one_pair(h2);
    if(op1 < op2)
        return true;
    if(op1 > op2)
        return false;
    for(size_t i = 5; i-- > 0; ) {
        if(h1[i].first < h2[i].first)
            return true;
        if(h1[i].first > h2[i].first)
            return false;
    }
    return false;
}

int main() {
    (void)!freopen("../../problem_inputs/p054_hands.txt", "r", stdin);
    int answer = 0;
    for(size_t i = 0; i < 1000; ++i) {
        std::string card;
        Hand h1;
        Hand h2;
        for(size_t j = 0; j < 5; ++j) {
            cin >> card;
            h1.push_back(get_card(card));
        }
        for(size_t j = 0; j < 5; ++j) {
            cin >> card;
            h2.push_back(get_card(card));
        }
        answer += (!compare_hands(h1, h2));
    }
    cout << answer << endl;
    return 0;
}