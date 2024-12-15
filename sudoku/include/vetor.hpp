//
// Created by lutero on 14/12/24.
//
#include <stdexcept>

#include "customTypes.hpp"

#ifndef VETOR_HPP
#define VETOR_HPP

template<typename T>
class vetor{

    T* vet;
    ulong tamAtual;
    ulong tamMax;

    void redimensionar() {
        tamMax *= 2;
        T* novo = new T[tamMax];

        for (uint i = 0; i < tamAtual; ++i)
            novo[i] = vet[i];

        delete[] vet;
        vet = novo;
    }

public:
    explicit vetor() {
        vet = nullptr;
        tamAtual = 0;
        tamMax = 0;
    }

    void insere(const T& sudoku) {
        if (tamMax == 0) {
            vet = new T[1];
            tamMax = 1;
        }

        if (tamAtual == tamMax) {
            redimensionar();
        }

        vet[tamAtual] = sudoku;

        ++tamAtual;
    }

    void swap(ulong i, ulong j) {
        if (i == j || i > tamAtual || j > tamAtual)
            return;

        T aux = vet[j];
        vet[j] = vet[i];
        vet[i] = aux;
    }

    ulong size() const {
        return tamAtual;
    }

    void delete_vetor() {
        delete[] vet;
    }

    void print() {
        for (uint i = 0; i < tamAtual; ++i) {
            printf("%d: %lld\n", i, vet[i].chave);
        }
    }

    T& operator[](ulong index) {
        if (index > tamAtual) {
            throw out_of_range("Índice fora dos limites do vetor.");
        }

        return vet[index];
    }

};

#endif //VETOR_HPP
