//
// Created by lutero on 15/12/24.
//

#include "binary_search.hpp"

long busca_binaria(const vetor<sudoku_t>& vet, const vetor<char>& entrada) {
    long inicio = 0, meio = 0, fim = vet.size() - 1;

    while (inicio < fim) {
        meio = (inicio + fim) / 2;
        printf("%ld %ld %ld\n", meio, inicio, fim);

        switch (compara(vet[meio].entrada, entrada)) {
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
    printf("vet: ");
    print_vetor(vet);
    printf("entrada: ");
    print_vetor(entrada);
    for (ulong i = 0; i < vet.size(); ++i) {
        if (vet[i] > entrada[i]) {
            printf("retornou 1\n");
            return 1;
        }

        if (vet[i] < entrada[i]) {
            printf("retornou -1\n");
            return -1;
        }
    }
    printf("retornou 0\n");
    return 0;
}

void print_vetor(const vetor<char>& vet) {
    for (ulong i = 0; i < vet.size(); ++i) {
        cout << vet[i];
    }
    cout << endl;
}
