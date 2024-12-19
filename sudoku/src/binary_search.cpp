//
// Created by lutero on 15/12/24.
//

#include "binary_search.hpp"

long busca_binaria(const vetor<vetor<char>>& vet, const vetor<char>& entrada) {
    long inicio = 0, meio = 0, fim = vet.size() - 1;

    while (inicio < fim) {
        meio = (inicio + fim) / 2;

        switch (compara(vet[meio], entrada)) {
            case 1:
                fim = meio -1;
                break;

            case 0:
                return meio;

            case -1:
                inicio = meio + 1;
                break;
        }
    }

    return -1;
}

int compara(const vetor<char> &vet, const vetor<char>& entrada) {
    for (ulong i = 0; i < vet.size(); ++i) {
        if (vet[i] > entrada[i])
            return 1;

        if (vet[i] < entrada[i])
            return -1;
    }
    return 0;
}
