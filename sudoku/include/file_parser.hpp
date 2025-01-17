//
// Created by lutero on 15/12/24.
//

#include "vetor.hpp"
#include "sudoku.hpp"
#include <fstream>
#include <memory>
#include <iostream>
#include <string.h>

#define MAX_LINHA 163

using namespace std;

#ifndef FILE_PARSER_HPP
#define FILE_PARSER_HPP

Sudoku* parse_file(const string& endereco, ulong tam);

sudoku_t parse_line(char *linha);

#endif //FILE_PARSER_HPP
