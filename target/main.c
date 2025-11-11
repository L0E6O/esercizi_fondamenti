#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Hello, World!\n");
    return 0;
}

/*Scrivere la funzione C che riceve in ingresso un array di interi A di dimensione N, un intero target, ed un
numero di ripetizioni M>0 e restituisce tra i parametri formali un array di interi V ottenuto nel modo seguente:
i valori di A diversi da target sono copiati in V; per ogni valore in A uguale a target è copiata in V una
sequenza di M valori uguali a target. La funzione deve anche restituire tra i parametri formali il numero di valori
(size) copiati in V.
(Esempio: A={5,1,3,1,1}, target=1, M=2 -> V={5,1,1,3,1,1,1,1}, size = 8).*/

int target(int *a, int n, int target, int m, int **v, int *size) {
    if (n==0) {
        return -1;
    } else if (m<=0) {
        return -2;
    }
    int countEqual = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == target) {
            countEqual++;
        }
    }
    *size = (countEqual*m)+(n-countEqual);
    *v = (int*) malloc(((*size)*sizeof(int)));

    if (*v == NULL) {
        return -3;
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == target) {
            for (int k = 0; k < m; k++) {
                (*v)[j++] = a[i];
            }
        } else {
            (*v)[j++] = a[i];
        }
    }
    return 0;
}