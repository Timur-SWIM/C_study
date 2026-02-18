#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int e_gcd(int a, int b, int *x, int *y) { 
    int x0 = 1, y0 = 0;
    int x1 = 0, y1 = 1;
    
    while (b != 0) {
        int q = a / b;
        int r = a % b;
        
        int x2 = x0 - q * x1;
        int y2 = y0 - q * y1;

        a = b;
        b = r;
        x0 = x1;
        y0 = y1;
        x1 = x2;
        y1 = y2;
    }
    *x = x0;
    *y = y0;
    return a;
}

int main() {
    int a, b, c, x, y;
    int res;
    res = scanf("%d %d %d", &a, &b, &c);
    assert(res == 3);
     
