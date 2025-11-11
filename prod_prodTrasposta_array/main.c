#include <stdio.h>
#include <stdlib.h>

int main(void) {
printf("Hello, World!\n");
return 0;
}

int matrix_managemeant(float *a, int n, int m, float *x, int l, float **c) {
   if (m==l) {
       *c = (float*) malloc(n*sizeof(float));
       if (*c==NULL) {
           return 1;
       }
       for (int i=0; i<n; i++) {
           for (int j=0; j<m; j++) {
               (*c)[i] = 0;
               for (int k=0; k<m; k++) {
                   (*c)[i] += a[i*m+k]*x[k];
               }
           }
       }
   }
   else if (n==l) {
       *c = (float*) malloc(m*sizeof(float));
       if (*c==NULL) {
           return 1;
       }
       for (int i = 0; i < m; i++) {
           (*c)[i] = 0;
           for (int k = 0; k < n; k++) {
               (*c)[i] += a[k * m + i] * x[k];
           }
       }
   }
   else {
       *c = (float*) malloc(n*m*sizeof(float));
       if (*c==NULL) {
           return 1;
       }
       for (int i=0; i<n; i++) {
           for (int j=0; j<m; j++) {
               (*c)[i*m+j] = a[i*m+j];
           }
       }
   }
}