//
// Created by lutero on 15/12/24.
//

#include "vetor.hpp"
#include "customTypes.hpp"
#include <iostream>

#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP

long busca_binaria(const vetor<sudoku_t>& vet, const vetor<char>& entrada);

int compara(const vetor<char> &vet, const vetor<char>& entrada);

void print_vetor(const vetor<char>& vet);

#endif //BINARY_SEARCH_HPP
