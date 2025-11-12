#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
    printf("Hello, World!\n");
    return 0;
}

bool prod_A_B(float a[], uint16_t b[], int n, int **c, int *counter) {
    if (n == 0)
        return false;
    *c = (int*)malloc(sizeof(int)*n);
    if (*c == NULL)
        return false;
    *counter = 0;
    for (int i = 0; i < n; i++) {
        if (b[i]>1)
            return false;
        if (b[i] != 0)
            (*counter)++;
        (*c)[i] = a[i]*b[i];
    }
    return true;
}