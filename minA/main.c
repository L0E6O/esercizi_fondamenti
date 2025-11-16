#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Hello, World!\n");
    return 0;
}

bool minA(int n, int m, int a[n][m], float **v) {
    if (n <= 0 || m <= 0) {
        return false;
    }

    int min = a[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] < min) {
                min = a[i][j];
            }
        }
    }

    if (min == 0) {
        return false;
    }

    (*v) = (float*) malloc(n * m * sizeof(float));

    if ((*v) == NULL) {
        return false;
    }

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            (*v)[j*n+i] = (float)a[i][j]/min;
        }
    }

    return true;
}