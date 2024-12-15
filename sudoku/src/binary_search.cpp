//
// Created by lutero on 15/12/24.
//

#include "binary_search.hpp"

long busca_binaria(const vetor<sudoku_info_t> &vet, const ulong chave) {
    long inicio = 0, meio = 0, fim = vet.size() - 1;

    while (inicio < fim) {
        meio = (fim + inicio) / 2;


        if (vet[meio].chave == chave)
            return meio;

        if (chave > vet[meio].chave)
            inicio = meio + 1;
        else
            fim = meio -1;
    }

    return -1;
}
