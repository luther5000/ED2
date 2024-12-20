#include <string>
#include <ios>
#include <iostream>
#include <sort.hpp>

#include "file_parser.hpp"

int main(){
    Sudoku *sudokus = parse_file("sudoku.csv");
    quick_sort(sudokus->s, 0, sudokus->s.size() - 1);

    while (true) {
        string entrada;

        printf("Qual o sudoku que você deseja buscar?\n");
        getline(cin, entrada);

        if (entrada.empty())
            return 0;

        vetor<char> *saida = sudokus->buscaSudoku(parse_line(entrada).entrada);

        if (saida == nullptr)
            printf("\nSudoku não encontrado!\n"
                   "-------------------------------------------------\n");
        else {
            printf("\nSolução para o sudoku informado:\n");
            for (ulong i = 0; i < saida->size(); ++i)
                cout << (*saida)[i];

            printf("\n-------------------------------------------------\n");
            saida->delete_vetor();
        }
    }
}
//195