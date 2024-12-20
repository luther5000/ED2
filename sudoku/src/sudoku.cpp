//
// Created by lutero on 15/12/24.
//

#include "sudoku.hpp"

#include <binary_search.hpp>

Sudoku::Sudoku() = default;

void Sudoku::adicionaSudoku(const sudoku_t& sudoku) {
    //printf("dentrou de sudoku\n");
    this->s.insere(sudoku);

    //printf("saindo de sudoku\n");
}

vetor<char> *Sudoku::buscaSudoku(const vetor<char>& entrada) {
    long indice = busca_binaria(this->s, entrada);

    printf("%ld\n", indice);
    if (indice == -1) {
        return nullptr;
    }

    return &s[indice].saida;
}
