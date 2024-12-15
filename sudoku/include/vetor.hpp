//
// Created by lutero on 14/12/24.
//
#include "customTypes.hpp"

#ifndef VETOR_HPP
#define VETOR_HPP

template<typename T>
class vetor{

    T* vet;
    uint tamAtual;
    uint tamMax;

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

    uint size() const {
        return tamAtual;
    }

    void delete_vetor() {
        delete[] vet;
    }

    void print() {
        for (uint i = 0; i < tamAtual; ++i) {
            printf("%d: %s\n", i, vet[i].s.c_str());
        }
    }

};

#endif //VETOR_HPP
