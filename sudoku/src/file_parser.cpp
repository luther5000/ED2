//
// Created by lutero on 15/12/24.
//

#include "file_parser.hpp"

Sudoku *parse_file(const string& endereco, ulong tam) {
    ifstream file;
    file.open(endereco, ios::in);

    if (!file.is_open())
        perror("Erro ao abrir arquivo\n");

    auto *sudoku = new Sudoku(tam);
    string linha;
    getline(file, linha);
    uint i = 0;

    while (getline(file, linha)) {

        printf("%d\n", i);
        auto info = parse_line(linha);

        sudoku->adicionaSudoku(info, {i, Sudoku::geraChave(info.entrada)});

        ++i;
    }

    return sudoku;
}

sudoku_t parse_line(const string& linha) {
    vetor<char> entrada;
    vetor<char> saida;

    int i = 0;
    while (i < 81) {
        entrada.insere(linha[i]);
        ++i;
    }
    ++i;
    while (i < 163) {
        saida.insere(linha[i]);
        ++i;
    }

    sudoku_t f;
    f.entrada = entrada;
    f.saida = saida;

    return f;
}