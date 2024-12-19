//
// Created by lutero on 15/12/24.
//

#include "sudoku.hpp"

#include <binary_search.hpp>

Sudoku::Sudoku() = default;

void Sudoku::adicionaSudoku(const vetor<char>& entrada, const vetor<char>& saida) {
    //printf("dentrou de sudoku\n");
    this->entrada.insere(entrada);
    this->saida.insere(saida);
    //printf("saindo de sudoku\n");
}

vetor<char> *Sudoku::buscaSudoku(const vetor<char>& entrada) {
    long indice = busca_binaria(this->entrada, entrada);

    if (indice == -1) {
        return nullptr;
    }

    return &saida[indice];
}
