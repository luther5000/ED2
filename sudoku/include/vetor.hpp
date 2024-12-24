//
// Created by lutero on 14/12/24.
//
#include <stdexcept>

using namespace std;

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

    void redimensionar(ulong tam) {
        T* aux = new T[tam];

        for (ulong i = 0; i < tamAtual && i < tam; ++i) {
            aux[i] = vet[i];
        }

        vet = aux;
        tamAtual = tamAtual < tam ? tamAtual : tam;
        tamMax = tam;
    }

    vetor(ulong tam) {
        vet = new T[tam];
        tamAtual = 0;
        tamMax = 0;
    }

    vetor(const vetor& outro) {
        vet = new T[outro.tamMax];
        tamMax = outro.tamMax;
        tamAtual = outro.tamAtual;

        for (ulong i = 0; i < outro.tamAtual; ++i)
            vet[i] = outro.vet[i];
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

    ~vetor() {
        delete[] vet;
    }

    void delete_vetor() {
        delete[] vet;
    }

    void print() {
        for (uint i = 0; i < tamAtual; ++i) {
            printf("%d: %lld\n", i, vet[i].chave);
        }
    }

    vetor& operator=(const vetor& other) {
        if (this != &other) {
            delete[] vet;

            vet = new T[other.tamAtual];
            tamMax = other.tamMax;
            tamAtual = other.tamAtual;

            for (ulong i = 0; i < other.tamAtual; ++i) {
                vet[i] = other.vet[i];
            }
        }
        return *this;
    }

    T& operator[](ulong index) {
        if (index > tamAtual) {
            throw out_of_range("Índice fora dos limites do vetor.");
        }

        return vet[index];
    }

    const T& operator[](ulong index) const{
        if (index > tamAtual) {
            throw out_of_range("Índice fora dos limites do vetor.");
        }

        return vet[index];
    }

    T* operator->() {
        return vet;
    }

    const T* operator->() const {
        return vet;
    }

};

#endif //VETOR_HPP
