#include <stdio.h>
#include <stdlib.h>

int buscaLinear(int n, int* vet, int elem){
    for (int i = 0; i < n; i++){
        if (elem == vet[i]) return i;
    }
    return -1;
}

int buscaBinaria(int n, int* vet, int elem){
    int inicio = 0;
    int final = n - 1;
    int meio;
    while (inicio <= final){
        meio = (inicio + final)/2;
        if (elem == vet[meio]) return meio;
        else if (elem < vet[meio]) final = meio - 1;
        else if (elem > vet[meio]) inicio = meio + 1;
    }
    return -1;
} 