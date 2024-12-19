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
    vetor<vetor<char>> entrada;
    vetor<vetor<char>> saida;

    explicit Sudoku();

    void adicionaSudoku(const vetor<char>& entrada, const vetor<char>& saida);

    vetor<char> *buscaSudoku(const vetor<char>& entrada);
};



#endif //SUDOKU_HPP
