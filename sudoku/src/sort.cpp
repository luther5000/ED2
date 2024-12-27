#include "sort.hpp"


void quick_sort(vetor<sudoku_t>& v, vetor<ulong>& indice, const long inicio, const long fim) {
    ulong q = 0;
    if (inicio < fim) {
        q = partition(v, indice, inicio, fim);
        quick_sort(v, indice, q + 1, fim);
        quick_sort(v, indice, inicio, q - 1);
    }
}

ulong partition(vetor<sudoku_t>& v, vetor<ulong>& indice, long inicio, long fim) {    
    vetor<char> pivo = v[indice[fim]].entrada;
    ulong i = inicio;

    for(ulong j = inicio; j <= fim - 1; ++j){
        
        if (compara2(v[indice[j]].entrada, pivo) == -1){
            indice.swap(i, j);
            
            ++i;
        }
    }
    indice.swap(i, fim);
    return i;
}

int compara2(const vetor<char> &vet, const vetor<char>& entrada) {
    for (ulong i = 0; i < vet.size(); ++i) {
        if (vet[i] > entrada[i])
            return 1;

        if (vet[i] < entrada[i])
            return -1;
    }
    return 0;
}
