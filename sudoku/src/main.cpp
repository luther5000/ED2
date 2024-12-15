#include "vetor.hpp"


int main(){
    vetor_impl<sudoku_t> vet;
    for (int i = 0; i < 10; ++i){
        sudoku_t s = {std::to_string(i), 0, 0, 0};
        vet.insere(s);
        }
    vet.print();
}
