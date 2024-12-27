#include "customTypes.hpp"
#include "vetor.hpp"
#include <string>
#include <sstream>

using namespace std;

#ifndef SUDOKU_HPP
#define SUDOKU_HPP


class Sudoku {
public:
    vetor<sudoku_t> s;
    vetor<ulong> info;

    explicit Sudoku(ulong tam);

    void adicionaSudoku(const sudoku_t& sudoku, const ulong indice);

    vetor<char> *buscaSudoku(const vetor<char>& entrada);

    static bool compara(const vetor<char>& a, const vetor<char>& b);
};



#endif //SUDOKU_HPP
