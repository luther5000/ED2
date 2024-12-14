//
// Created by lutero on 14/12/24.
//
#include "vetor.hpp"


vetor::vetor() {
    vet = nullptr;
    tamAtual = 0;
    tamMax = 0;
}

void vetor::insere(sudoku_t& sudoku) {
    if (tamMax == 0) {
        vet = (sudoku_t*) malloc(sizeof(sudoku_t));
        tamMax = 1;
    }

    if (tamAtual == tamMax) {
        tamMax *= 2;

        vet = (sudoku_t*) realloc(vet, tamMax*sizeof(sudoku_t));
    }

    vet[tamAtual] = sudoku;

    ++tamAtual;
}

void vetor::print() {
    for (int i = 0; i < tamAtual; ++i) {
        printf("%d: %s\n", i, vet[i].s.c_str());
    }
}
