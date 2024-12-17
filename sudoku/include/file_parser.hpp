//
// Created by lutero on 15/12/24.
//

#include "customTypes.hpp"
#include "sudoku.hpp"
#include <fstream>

using namespace std;

#ifndef FILE_PARSER_HPP
#define FILE_PARSER_HPP

Sudoku* parse_file(string endereco);

file_line_t* parse_line(string linha);

vetor<string>* split(const string& s, char a);

#endif //FILE_PARSER_HPP
