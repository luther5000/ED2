#include "sudoku.hpp"

#include <binary_search.hpp>

Sudoku::Sudoku(ulong tam) {
    s.redimensionar(tam);
    info.redimensionar(tam);
}

void Sudoku::adicionaSudoku(const sudoku_t& sudoku, const ulong info) {
    this->s.insere(sudoku);
    this->info.insere(info);
}

vetor<char> *Sudoku::buscaSudoku(const vetor<char>& entrada) {
    long indice = busca_binaria(this->s, this->info, entrada);

    if (indice == -1) {
        return nullptr;
    }

    return &s[info[indice]].saida;

}

bool Sudoku::compara(const vetor<char>& a, const vetor<char>& b) {
    for (ulong i = 0; i < a.size(); ++i) {
        if (a[i] != b[i])
            return false;
    }
    return true;
}
