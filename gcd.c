#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int iabs(int x) { return (x < 0) ? -x : x; }
// Euclidan division: a = qb + r, 0 <= r < |b|
// C-style "%" operation: a == (a / b) * b + (a % b)
// We need proper euclidan division here

int e_mod(int x, int y) {
    int r;
    assert(y != 0);
    r = x % y; 
    if (r < 0) r += iabs(y);
    return r;
}

int gcd(int x, int y) {
    int q = e_mod(x, y);
    if (q == 0)
	return y;
    return(gcd(y, q));
}

int read_input(int *px, int *py) {
    int nitems;
    nitems = scanf("%d%d", px, py);
    if ((nitems != 2) || (*py == 0)) {
        printf("Wrong input\n");
	abort();
    }
    return 0;
}
int main() {
    int x, y, g;
    read_input(&x, &y);
    g = gcd(x, y);
    printf("gcd(x,y) = %d\n", g);
    return 0;
}
