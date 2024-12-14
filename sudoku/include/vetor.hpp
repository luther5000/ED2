//
// Created by lutero on 14/12/24.
//
#include "customTypes.hpp"
#include <malloc.h>

#ifndef VETOR_HPP
#define VETOR_HPP

class vetor{
    sudoku_t *vet;
    int tamAtual;
    int tamMax;

    explicit vetor();

    void insere(sudoku_t& sudoku);

    void print();

};




#endif //VETOR_HPP
