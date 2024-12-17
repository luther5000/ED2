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
    string linha = "";
    while (getline(file, linha)) {
        file_line_t* info = parse_line(linha);

        if (info == nullptr)
            perror("Erro na leitura do arquivo\n");

        sudoku->adicionaSudoku(*info);
        delete info;
    }

    return sudoku;
}

file_line_t *parse_line(string linha) {
    vetor<string> *sudokus = split(linha, ',');
    istringstream stream((*sudokus)[0]);
    auto *nums = new vetor<int>;

    string palavra;
    while (stream >> palavra) {
        nums->insere(stoi(palavra));
    }

    delete sudokus;

    return new file_line_t{(*sudokus)[0], (*sudokus)[1], nums};
}

vetor<string> *split(const string &s, const char a) {
    auto *vet = new vetor<string>;

    ulong i = 0, j = 0;

    while (i < s.size()) {
        if (s[i] == a) {
            vet->insere(s.substr(j, i));
            j = i + 1;
        }

        ++i;
    }

    return vet;
}


