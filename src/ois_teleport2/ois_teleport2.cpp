/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>

using namespace std;

// input data
int T, i;
int xa, ya, xb, yb, xc, yc, r;

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &T));
    for(i=0; i<T; i++) {
        assert(7 == scanf("%d %d %d %d %d %d %d",
                    &xa, &ya, &xb, &yb, &xc, &yc, &r));

        // insert your code here
		
		double Xa = xa, Xb = xb, Xc = xc, Ya = ya, Yb = yb, Yc = yc, R = r;
		double result = 0;
		double AB = sqrt((Xa - Xb) * (Xa - Xb) + (Ya - Yb) * (Ya - Yb));
		double AC = sqrt((Xa - Xc) * (Xa - Xc) + (Ya - Yc) * (Ya - Yc));
		AC = max(0.0, AC - R);
		double BC = sqrt((Xb - Xc) * (Xb - Xc) + (Yb - Yc) * (Yb - Yc));
		BC = max(0.0, BC - R);
		
		result = (double)min(AB, AC + BC);
		
        // print result (round down and print six decimals)
        // DO NOT EDIT!
        result = floor(result * 1000000) / 1000000;
        printf("%.6f\n", result);
    }
    return 0;
}