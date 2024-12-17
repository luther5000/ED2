//
// Created by lutero on 15/12/24.
//

#include "vetor.hpp"
#include "customTypes.hpp"
#include <string>
#include <sstream>

using namespace std;

#ifndef SUDOKU_HPP
#define SUDOKU_HPP

typedef struct {
    string entrada;
    string saida;
} sudoku_t;


class Sudoku {
private:

    ullong geraChave(const vetor<int>& nums);

public:
    vetor<sudoku_info_t> *sudoku_infos;
    vetor<sudoku_t> *s;

    explicit Sudoku();

    void adicionaSudoku(const file_line_t& info);

    string* buscaSudoku(const file_line_t& info);
};



#endif //SUDOKU_HPP
