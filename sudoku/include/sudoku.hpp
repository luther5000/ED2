//
// Created by lutero on 15/12/24.
//

#include "vetor.hpp"
#include "customTypes.hpp"
#include <string>

using namespace std;

#ifndef SUDOKU_HPP
#define SUDOKU_HPP

typedef struct {
    string entrada;
    string saida;
} sudoku_t;


class Sudoku {
private:
    ullong geraChave(string s);

    ulong hash(ullong chave);

public:
    vetor<sudoku_info_t> *sudoku_infos;
    vetor<sudoku_t> *s;

    explicit Sudoku();

    void adicionaSudoku(string s);

    string buscaSudoku(string s);
};



#endif //SUDOKU_HPP
