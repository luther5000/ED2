//
// Created by lutero on 15/12/24.
//

#include "sudoku.hpp"

#include <binary_search.hpp>

Sudoku::Sudoku(ulong tam) {
    s.redimensionar(tam);
    info.redimensionar(tam);
}

void Sudoku::adicionaSudoku(const sudoku_t& sudoku, const sudoku_info_t& info) {
    this->s.insere(sudoku);
    this->info.insere(info);
}

vetor<char> *Sudoku::buscaSudoku(const vetor<char>& entrada) {
    ullong chave = geraChave(entrada);
    long indice = busca_binaria(this->info, chave);

    if (indice == -1) {
        return nullptr;
    }

    long i = indice - 1;
    while (indice < info.size() && info[indice].chave == chave) {
        if (compara(s[info[indice].indice].entrada, entrada))
            return &s[this->info[indice].indice].saida;

        ++indice;
    }

    while (i > 0 && info[indice].chave == chave) {
        if (compara(s[info[i].indice].entrada, entrada))
            return &s[info[i].indice].saida;
    }

    return nullptr;
}

ullong Sudoku::geraChave(const vetor<char> &entrada) {
    ullong chave = 0;

    for (ulong i = 0; i < entrada.size(); ++i) {
        chave += chave * 31 + (entrada[i] - '0');
    }

    return chave;
}

bool Sudoku::compara(const vetor<char>& a, const vetor<char>& b) {
    for (ulong i = 0; i < a.size(); ++i) {
        if (a[i] != b[i])
            return false;
    }
    return true;
}
