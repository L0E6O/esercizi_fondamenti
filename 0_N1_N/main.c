#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Hello, World!\n");
    return 0;
}

int content_check(int n, int *v, int n1, int **a) {
    if (n<2) {
        return -1;
    }
    if (n1<1 || n1>n) {
        return -2;
    }
    int aSize = n-(n-n1);
    *a = (int*) malloc(aSize*sizeof(int));
    if (*a == NULL) {
        return -3;
    }
    for (int i = n1; i < n; i++) {
        for (int j = 0; j < n1; j++) {
            *a[i] = (v[i] == v[j]) ? true : false;
        }
    }
}