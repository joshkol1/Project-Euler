#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
#define pb push_back

ll n_rectangles(int g_w, int g_h) {
    ll ans = 0;
    // add grid-aligned rectangles
    ans += (g_w+1)*g_w/2*(g_h+1)*g_h/2;
    // Diagonal rectangles
    for(int w = 1; w <= 2*g_w; ++w) {
        for(int h = 1; w+h <= 2*min(g_w, g_h); ++h) {
            int min_a = w;
            int max_a = 2*g_w-h;
            int min_b = 0;
            int max_b = 2*g_h-w-h;
            if(min_a > max_a || min_b > max_b)
                continue;
            int even_a;
            int even_b;
            if((max_a-min_a)%2 == 0) {
                if(min_a%2 == 0)
                    even_a = (max_a-min_a)/2+1;
                else
                    even_a = (max_a-min_a)/2;
            } 
            else 
                even_a = (max_a-min_a)/2;
            if(max_b%2 == 0)
                even_b = max_b/2+1;
            else
                even_b = (max_b+1)/2;
            ans += even_a*even_b + (max_a-min_a+1-even_a)*(max_b-min_b+1-even_b);
        }
    }
    return ans;
}

int main() {
    ll ans = 0;
    int w, h;
    cin >> w >> h;
    for(int i = 1; i <= w; ++i) {
        for(int j = 1; j <= h; ++j) {
            ans += n_rectangles(i, j);
        }
    }
    cout << ans << "\n";
    return 0;
}