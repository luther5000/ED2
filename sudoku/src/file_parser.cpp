//
// Created by lutero on 15/12/24.
//

#include "file_parser.hpp"

Sudoku *parse_file(const string& endereco) {
    ifstream file;
    file.open(endereco, ios::in);

    if (!file.is_open())
        perror("Erro ao abrir arquivo\n");

    auto *sudoku = new Sudoku;
    string linha;
    getline(file, linha);
    ulong i = 0;

    while (getline(file, linha)) {

        printf("%ld\n", i);
        auto info = parse_line(linha);
        //printf("%c %c\n", info.entrada[1], info.saida[1]);

        for (ulong j = 0; j < info.entrada.size(); ++j)
            cout << info.entrada[j];
        cout << endl;

        sudoku->adicionaSudoku(info);
        //printf("passsou\n");

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