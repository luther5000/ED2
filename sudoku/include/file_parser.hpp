//
// Created by lutero on 15/12/24.
//

#include "vetor.hpp"
#include "sudoku.hpp"
#include <fstream>
#include <memory>
#include <iostream>

using namespace std;

#ifndef FILE_PARSER_HPP
#define FILE_PARSER_HPP

Sudoku* parse_file(const string& endereco);

file_line_t parse_line(const string& linha);

#endif //FILE_PARSER_HPP
