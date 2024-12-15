#include <vector>

#include "vetor.hpp"
#include "sort.hpp"


int main(){
    vetor<sudoku_info_t> vet;
    for (ulong i = 10; i > 0; --i){
            sudoku_info_t s = {i, i};
            vet.insere(s);
        }
    vet.print();
    printf("\n");
    quick_sort(vet, 0, 9);
    vet.print();

}
