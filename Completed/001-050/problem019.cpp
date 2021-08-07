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

bool leap_year(int y) {
    if(y%4 != 0)
        return false;
    if(y%400 == 0)
        return true;
    if(y%100 == 0)
        return false;
    return true;
}

int main() {
    int ans = 0;
    vector<int> days = 
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day = 1;
    int month = 1;
    int year = 1901;
    int weekday = 1;
    for(int d = 0; year <= 2000; ++d) {
        weekday = (++weekday)%7;
        ++day;
        if(month == 2 && day > days[month]) {
            if(day > days[month]+1 || !leap_year(year)) {
                day = 1;
                ++month;
            }
        } else {
            if(day > days[month]) {
                day = 1;
                ++month;
            }
        }
        if(month > 12) {
            month = 1;
            day = 1;
            ++year;
        }
        ans += (day == 1 && weekday == 6);
    }
    cout << ans << endl;
    return 0;
}