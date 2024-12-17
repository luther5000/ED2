//
// Created by lutero on 14/12/24.
//
#include <string>
#include <vetor.hpp>

using namespace std;

#ifndef CUSTOMTYPES_HPP
#define CUSTOMTYPES_HPP

typedef unsigned short usint;
typedef unsigned int uint;
typedef unsigned long long ullong;
typedef unsigned long ulong;

typedef struct sudoku_info {
    ullong chave;
    ulong indice;
} sudoku_info_t;

typedef struct {
    string entrada;
    string saida;
    vetor<int>* nums;
} file_line_t;

#endif //CUSTOMTYPES_HPP
