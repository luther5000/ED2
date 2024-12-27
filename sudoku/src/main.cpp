#include <string>
#include <ios>
#include <iostream>
#include <sort.hpp>

#include "file_parser.hpp"

int main(){
    clock_t inicio, fim;
    Sudoku *sudokus = parse_file("sudoku.csv", 9000000);

    inicio = clock();
    quick_sort(sudokus->s, sudokus->info, 0, sudokus->s.size() - 1);
    fim = clock();

    printf("Tempo sort: %lf\n", ((double)(fim - inicio) / CLOCKS_PER_SEC));

    while (true) {
        char *entrada = new char[81];

        printf("Qual o sudoku que você deseja buscar?\n"
                "Digite 's' para sair.\n");
        scanf("%s", entrada);

        if (entrada[0] == 's')
            return 0;

        inicio = clock();
        vetor<char> *saida = sudokus->buscaSudoku(parse_line(entrada).entrada);
        fim = clock();

        if (saida == nullptr)
            printf("\nSudoku não encontrado!\n");

        else {
            printf("\nSolução para o sudoku informado:\n");
            for (ulong i = 0; i < saida->size(); ++i)
                cout << (*saida)[i];

            printf("\n");
        }

        printf("\nTempo de busca: %lf\n"
                "-------------------------------------------------\n", 
                ((double)(fim - inicio) / CLOCKS_PER_SEC));
    }
}
