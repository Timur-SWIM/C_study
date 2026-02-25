#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long long gcd(unsigned long long x,
		       unsigned long long y) {
    unsigned long long q = 1;
    if (y > x)
        return(gcd(y, x));
    assert(y > 0);
    while (q != 0) {
        q = x % y;
        x = y;
        y = q;
	printf("x=%llu, y=%llu\n", x, y); 
    } 
    return x;
}

int main() {
    unsigned long long x = 0, y = 0, g;
    int res;
    
    res = scanf("%llu %llu", &x, &y);
    assert(res == 2);
    g = gcd(x, y);
    printf("%llu\n", g);
    return 0;
}
