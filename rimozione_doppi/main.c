#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    return 0;
}

/*Scrivere la funzione C che riceve in ingresso un array di interi A di dimensione N, ed opera nel modo
seguente:
•
sostituisce le sequenze di valori uguali adiacenti in A con la prima occorrenza del valore,
compattando i valori rimanenti verso sinistra, e completando l'array a destra con un numero di zeri
pari al numero di elementi rimossi.
La funzione deve anche restituire tra i parametri formali il numero dei valori rimossi M.*/

int doubles_removal(int *a, int n, int* m) {
    if (n == 0) {
        return -1;
    }
    (*m) = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i-1]) {
            (*m)++;
            for (int j = i; j < n-1; j++) {
                a[j] = a[j+1];
            }
            a[n-(*m)] = 0;
            i--;
        }
    }
    return 0;
}