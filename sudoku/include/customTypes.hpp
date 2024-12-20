//
// Created by lutero on 14/12/24.
//
#include <string>
#include "vetor.hpp"
using namespace std;

#ifndef CUSTOMTYPES_HPP
#define CUSTOMTYPES_HPP

typedef unsigned short usint;
typedef unsigned int uint;
typedef unsigned long long ullong;
typedef unsigned long ulong;

typedef struct {
    vetor<char> entrada;
    vetor<char> saida;
} sudoku_t;


#endif //CUSTOMTYPES_HPP
