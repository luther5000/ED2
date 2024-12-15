#include <vector>

#include "vetor.hpp"
#include "sort.hpp"
#include "binary_search.hpp"


int main(){
    vetor<sudoku_info_t> vet;
    for (ulong i = 0; i < 10; ++i){
            sudoku_info_t s = {i, i};
            vet.insere(s);
        }
    vet.print();
    printf("\n");
    quick_sort(vet, 0, 9);
    vet.print();

    long n = busca_binaria(vet, 7);

    if (n == -1)
        printf("Não foi encontrado");
    else
        printf("%lld", vet[n].chave);
}
