//
// Created by lutero on 15/12/24.
//

#include "customTypes.hpp"
#include "vetor.hpp"
#include <string>
#include <sstream>

using namespace std;

#ifndef SUDOKU_HPP
#define SUDOKU_HPP


class Sudoku {
private:

    ullong geraChave(const vetor<int>& nums);

public:
    vetor<sudoku_t> s;

    explicit Sudoku();

    void adicionaSudoku(const sudoku_t& sudoku);

    vetor<char> *buscaSudoku(const vetor<char>& entrada);
};



#endif //SUDOKU_HPP
