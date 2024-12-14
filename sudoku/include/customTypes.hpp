//
// Created by lutero on 14/12/24.
//
#include <string>

using namespace std;

#ifndef CUSTOMTYPES_HPP
#define CUSTOMTYPES_HPP

typedef unsigned short usint;

typedef struct sudoku {
    string s;
    usint soma;
    usint somaLinha;
    usint somaColuna;
} sudoku_t;

#endif //CUSTOMTYPES_HPP
