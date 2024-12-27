#include "binary_search.hpp"

long busca_binaria(const vetor<sudoku_t>& s, const vetor<ulong>& indice, const vetor<char>& entrada) {
    long inicio = 0, meio = 0, fim = indice.size() - 1;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        switch (compara(s[indice[meio]].entrada, entrada)) {
            case 0:
                return meio;

            case -1:
                inicio = meio + 1;
                break;

            case 1:
                fim = meio -1;
                break;
        
            default:
                break;
        }   
    }

    return -1;
}

int compara(const vetor<char> &vet, const vetor<char>& entrada) {
    for (ulong i = 0; i < vet.size(); ++i) {
        if (vet[i] > entrada[i]) {
            return 1;
        }

        if (vet[i] < entrada[i]) {
            return -1;
        }
    }
    return 0;
}
