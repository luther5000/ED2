//
// Created by lutero on 15/12/24.
//

#include "sudoku.hpp"

#include <binary_search.hpp>

Sudoku::Sudoku() {
    sudoku_infos = new vetor<sudoku_info_t>;
    s = new vetor<sudoku_t>;
}

void Sudoku::adicionaSudoku(const file_line_t& info) {
    const ullong chave = geraChave(*info.nums);
    s->insere({info.entrada, info.saida});
    sudoku_infos->insere({chave, s->size() - 1});
}

string* Sudoku::buscaSudoku(const file_line_t& info) {
    ullong chave = geraChave(*info.nums);

    long indice = busca_binaria(*sudoku_infos, chave);

    long j = indice;

    if (indice == -1) {
        return nullptr;
    }

    while (indice < sudoku_infos->size() && sudoku_infos[indice]->chave == chave){
        if (s[sudoku_infos[indice]->indice]->entrada == info.entrada)
            return &s[sudoku_infos[indice]->indice]->saida;

        ++indice;
    }

    while (j > 0 && sudoku_infos[j]->chave == chave){
        if (s[sudoku_infos[j]->indice]->entrada == info.entrada)
            return &s[sudoku_infos[j]->indice]->saida;

        --j;
    }

    return nullptr;

}

ullong Sudoku::geraChave(const vetor<int>& nums) {
    ullong chave = 0;

    for (int i = 0; i < nums.size(); ++i)
        chave = chave * 31 + nums[i];

    return chave;
}
