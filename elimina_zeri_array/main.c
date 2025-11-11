#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Hello, World!\n");
    return 0;
}

/*Scrivere la funzione C che riceve in ingresso un array di interi A e la sua dimensione N, ed opera nel modo
seguente:


Conta il numero M di valori di A diversi da zero;
Rimuove da A gli elementi con valore zero e rialloca l’array A con dimensione uguale al numero dei soli
elementi diversi da 0. L’array A così riallocato deve essere visibile dalla funzione chiamante
(suggerimento: copiare prima i valori di A diversi da zero in un vettore di appoggio V);
 Restituisce la nuova dimensione di A come valore di ritorno.
(Esempio: A={1,2,0,0,3,4,0,5}, N=8 -> A={1,2,3,4,5}, M=5) .*/

int elimina_zeri_array(int n, int **A) {
    if (n==0)
        return -1;

    int m = 0;

    for (int i=0; i<n; i++) {
        if (*A[i]!=0)
            m++;
    }

    if (m==0) {
        return -2;
    }

    int *B = (int*) malloc(sizeof(int) * m);
    if (B==NULL)
        return -2;

    int j = 0;
    for (int i = 0; i < n; i++) {
        if ((*A)[i] != 0) {
            B[j] = *A[i];
            j++;
        }
    }
    free(*A);
    *A = B;
    return m;
}