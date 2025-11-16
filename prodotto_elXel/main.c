#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Hello, World!\n");
    return 0;
}

/*Scrivere la funzione C che riceve in ingresso due matrici A e B di valori float entrambe con N righe ed M
colonne, ed opera nel modo seguente:
• Alloca e calcola la matrice X (di valori float) con N righe ed M colonne i cui elementi sono ottenuti come
prodotto tra A e B. Il prodotto è eseguito elemento per elemento invece che riga per colonna;
• Restituisce tra i parametri formali la trasposta della matrice X.*/

int prodByElement (float *a, float *b, int n, int m, float **x) {
    if (n<=0) {
        return -1;
    }
    if (m<=0) {
        return -2;
    }

    *x = (float*) malloc (n * m * sizeof (float));
    if (*x==NULL) {
        return -3;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            (*x)[j*n+i] = a[i*m+j]*b[i*m+j];
        }
    }
    return 0;
}