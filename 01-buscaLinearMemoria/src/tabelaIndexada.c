#include <stdio.h>
#include <stdlib.h>
#include "tabelaIndexada.h"
#include "tipoFilme.h"

struct rotTabIdx {
    tDados *elementos;   /* Ponteiro para o array que contem os elementos */
    int    nElementos;   /* Numero de elementos */
    int    tamanhoArray;
};

static int qOperacoes = 0;

tTabelaIdx * CriaTabelaIdx(void){
    tTabelaIdx *tabela;

        /* Aloca espaco para a estrutura que armazena a tabela */
    tabela = malloc(sizeof(struct rotTabIdx));
    if (!tabela){
        puts("Erro ao alocar tabela.");
        exit(1);
    }

    tabela->elementos = calloc(1, sizeof(tDados)); //aloca elementos
    if (!tabela->elementos){
        puts("Erro ao alocar elementos.");
        exit(1);
    }

    tabela->tamanhoArray = 1;
    tabela->nElementos = 0;

    return tabela;
}

void DestroiTabelaIdx(tTabelaIdx * tabela){
    for(int i = 0; i < tabela->nElementos; i++){
        LiberaFilme(&tabela->elementos[i]);
    }
    free(tabela->elementos);
    free(tabela);
}

int ComprimentoIdx(tTabelaIdx * tabela){
    return tabela->nElementos; 
}

tDados ObtemElementoIdx(tTabelaIdx * tabela, int indice){
    if (indice < 0 || indice >= tabela->nElementos){
        puts("Indice inexistente para obtencao.");
        exit(1);
    }

    return tabela->elementos[indice];
}

tDados RemoveElementoIdx(tTabelaIdx * tabela, int indice){
    tDados itemRemovido;

    if (indice < 0 || indice >= tabela->nElementos){
        puts("Indice inexistente para remocao.");
        exit(1);
    }

    itemRemovido = tabela->elementos[indice];
    for (int i = indice; i < tabela->nElementos - 1; i++)
        tabela->elementos[i] = tabela->elementos[i + 1];

    tabela->nElementos--; 

    return itemRemovido;
}

int EstaVaziaIdx(tTabelaIdx * tabela){
    return tabela->nElementos == 0;
}

void AcrescentaElementoIdx(tTabelaIdx * tabela, const tDados *elemento){
    tDados *novoArray; 

    
    /*
    for(int i = 0; i < tabela->nElementos; i++){
        if (tabela->elementos[i].id == elemento->id){
            return; //ja existe
        }
    }
    */
    

    if (tabela->nElementos >= tabela->tamanhoArray) { //array completo
        tabela->tamanhoArray *= 2;

        novoArray = realloc(tabela->elementos,
                            tabela->tamanhoArray*sizeof(tDados));

        if (!novoArray){
            puts("Erro ao realocar tabela.");
            exit(1);
        }

        tabela->elementos = novoArray;
    }

    tabela->elementos[tabela->nElementos] = *elemento;

    ++tabela->nElementos;
}

int BuscaSequencial(tTabelaIdx *tab, int chave){
    qOperacoes = 0;
    for(int i = 0; i < tab->nElementos; i++){
        qOperacoes++;
        if (chave == tab->elementos[i].id){
            return i;
        }
    }
    return -1;
}

int BuscaDedilhada(tTabelaIdx *tab, int chave){
    static int ultimoIndice = 0;

    if (chave < tab->elementos[ultimoIndice].id){
        ultimoIndice = 0;
    }

    qOperacoes = 0;
    for(int i = ultimoIndice; i < tab->nElementos; i++){
        qOperacoes++;
        if (chave == tab->elementos[i].id){
            ultimoIndice = i;
            return i;
        }
        if (chave < tab->elementos[i].id){
            ultimoIndice = i;
            break;
        }
    }
    
    return -1;
}

int QuantOperacoes(){
    return qOperacoes;
}

int buscaTransposicao(tTabelaIdx *tabela, int chave) {
    qOperacoes = 0;
    tDados aux;

    int i = 0;
    for (; i < tabela->nElementos; ++i) {
        ++qOperacoes;
        if (tabela->elementos[i].id == chave) {
            if (i > 0)
                aux = tabela->elementos[i-1];
            break;
        }
    }

    // Percorreu toda a tabela e não encontrou
    if (i == tabela->nElementos)
        return -1;

    if (i == 0)
        return 0;

    // Alteração do local onde o objeto está
    tabela->elementos[i-1] = tabela->elementos[i];
    tabela->elementos[i] = aux;

    // Retorna o novo local do objeto pós alteração
    return i-1;
}

int buscaMovInicio(tTabelaIdx *tabela, int chave) {
    qOperacoes = 0;
    tDados aux, *aux2;

    int i = 0;
    for (; i < tabela->nElementos; ++i) {
        ++qOperacoes;
        if (tabela->elementos[i].id == chave) {
            if (i > 0) {
                aux = tabela->elementos[i];
                aux2 = &tabela->elementos[i-1];
            }
            break;
        }
    }

    // Percorreu toda a tabela e não encontrou
    if (i == tabela->nElementos)
        return -1;

    if (i > 0) {
        // Faz o shift de todos os elementos antes de i
        for (; i > 0; --i) {
            ++qOperacoes;
            tabela->elementos[i] = *aux2;
            --aux2;
        }

        // Poe o elemento que estava em i na posicao 0
        tabela->elementos[0] = aux;
    }

    return 0;
}
