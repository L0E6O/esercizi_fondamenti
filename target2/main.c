#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Hello, World!\n");
    return 0;
}

/*Scrivere la funzione C che riceve in ingresso un array A di valori interi, di dimensione N, ed un valore target,
ed opera nel modo seguente:
• Ridispone gli elementi di A in modo che prima ci siano gli elementi minori o uguali a target e poi
quelli maggiori;
• Alloca un array V e copia gli elementi di A minori o uguali a target in V;
• Ritorna l’array V tra i parametri formali.*/

#define TRUE 1
#define FALSE 0

int target_division(int a[], int n,int **v, int target) {

    if (n <= 0) {
        return -1;
    }

    int minTail = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= target) {
            int tmp = a[i];
            for (int j = i; j > minTail; j--) {
                a[j] = a[j-1];
            }
            a[minTail] = tmp;
            minTail++;
        }
    }
    (*v) = (int*) malloc((minTail)*sizeof(int));

    if ((*v) == NULL) {
        return -2;
    }

    for (int i = 0; i <= minTail; i++) {
        (*v)[i] = a[i];
    }
    return 0;
}