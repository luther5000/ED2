//
// Created by lutero on 15/12/24.
//

#include "sudoku.hpp"

#include <binary_search.hpp>

Sudoku::Sudoku() = default;

void Sudoku::adicionaSudoku(const sudoku_t& sudoku) {
    this->s.insere(sudoku);
}

vetor<char> *Sudoku::buscaSudoku(const vetor<char>& entrada) {
    long indice = busca_binaria(this->s, entrada);

    if (indice == -1) {
        return nullptr;
    }

    return &s[indice].saida;
}
