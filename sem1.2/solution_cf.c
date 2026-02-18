#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long long gcd(unsigned long long x,
                       unsigned long long y) {
    unsigned long long q = 1, r = 0;
    if (y > x) {
        printf("r=%llu\n", r);
        return(gcd(y, x));}
    assert(y > 0);
    while(q != 0) {
        q = x % y;
        r = x / y;
        x = y;
        y = q;
	printf("r=%llu\n", r);
    }
    return x;
}

int main() {
    unsigned long long a = 0, b = 0, g;
    int res;
    
    res = scanf("%llu %llu", &a, &b);
    assert(res == 2);
    g = gcd(a, b);
    return 0;
} 
