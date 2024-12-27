#include "file_parser.hpp"

Sudoku *parse_file(const string& endereco, ulong tam) {
    FILE *file = fopen(endereco.c_str(), "r");

    if (!file)
        perror("Erro ao abrir arquivo\n");

    auto *sudoku = new Sudoku(tam);
    char linha[MAX_LINHA + 2];
    fgets(linha, sizeof(linha), file);
    uint i = 0;
    clock_t inicio, fim;

    inicio = clock();
    while (fgets(linha, sizeof(linha), file)) {
        linha[strcspn(linha, "\n")] = '\0';

        auto info = parse_line(linha);
        
        sudoku->adicionaSudoku(info, i);

        ++i;
    }
    
    fim = clock();
    printf("Tempo para leitura do arquivo: %lf\n", ((double)(fim - inicio) / CLOCKS_PER_SEC));

    return sudoku;
}

sudoku_t parse_line(char* linha) {
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