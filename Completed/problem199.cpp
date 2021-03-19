#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back

ld total_area;
ld init_radius = 2*sqrt(3.0L)-3;

/*
    Descartes' theorem:

    Suppose we have 3 kissing circles with radius r1, r2, r3.
    Now, say circle with radius r4 touches all 3 of them. Let
    k1, k2, k3, k4 = 1/r1, 1/r2, 1/r3, 1/r4
    Then, k4 = (k1+k2+k3)+-2*sqrt(k1*k2+k2*k3+k1*k3)
    Use plus sign if k4 circumscribes the other three, minus 
    sign otherwise.

    Source: https://en.wikipedia.org/wiki/Descartes%27_theorem
*/  

/*
    Given three kissing circles, generate their children
*/
void generate_inside(ld c1, ld c2, ld c3, int depth) {
    ld cv1 = 1/c1; ld cv2 = 1/c2; ld cv3 = 1/c3;
    ld new_cv = cv1+cv2+cv3+2*sqrt(cv1*cv2+cv2*cv3+cv1*cv3);
    ld new_radius = 1/new_cv;
    total_area += new_radius*new_radius;
    if(depth < 9) {
        generate_inside(c1, c2, new_radius, depth+1);
        generate_inside(c1, c3, new_radius, depth+1);
        generate_inside(c2, c3, new_radius, depth+1);
    }
}

/*
    Given two kissing circles (on border), generate their children
*/
void generate_border(ld c1, ld c2, int depth) {
    ld cv1 = 1/c1; ld cv2 = 1/c2;
    ld new_cv = cv1+cv2-1+2*sqrt(cv1*cv2-cv1-cv2);
    ld new_radius = 1/new_cv;
    total_area += new_radius*new_radius;
    if(depth < 9) {
        generate_inside(c1, c2, new_radius, depth+1);
        generate_border(c1, new_radius, depth+1);
        generate_border(c2, new_radius, depth+1);
    }
}

int main() {
    total_area += 3*init_radius*init_radius;
    generate_inside(init_radius, init_radius, init_radius, 0);
    for(int i = 0; i < 3; i++) {
        generate_border(init_radius, init_radius, 0);
    }
    cout << setprecision(10) << 1-total_area << "\n";
    return 0;
}