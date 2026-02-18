#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void read_input(int*, int*);

int main() {
    int a, b, p, q, res;
    read_input(&a, &b);
    assert(b != 0);
    p = a / b;
    q = a % b;
    printf("p = %d, q = %d\n", p, q);
    return 0;
}

void read_input(int *pa, int *pb){
    int nitems;
    printf("input a and b: ");
    nitems = scanf("%d%d", pa, pb);

    if ((nitems != 2) || (*pb == 0)) {
        printf("Wrong input\n");
	abort();
    }
}
