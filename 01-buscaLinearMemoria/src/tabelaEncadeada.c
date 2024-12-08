#include <stdio.h>
#include <stdlib.h>
#include "tabelaEncadeada.h"
#include "tipoFilme.h"

struct rotTabEnc {
    tDado dado;   
    struct rotTabEnc *prox;
};

static int qOperacoes = 0;

void CriaTabelaEnc(tTabelaEnc **tabela){
    *tabela = NULL;
}

void DestroiTabelaEnc(tTabelaEnc * tabela){
    tTabelaEnc * temp;
    while(tabela != NULL){
        temp = tabela;
        tabela = tabela->prox;

        LiberaFilme(&temp->dado);
        free(temp);
    }
}

int ComprimentoEnc(tTabelaEnc * tabela){
    int c = 0;
    
    while(tabela != NULL){
        c++;
        tabela = tabela->prox;
    }

    return c;
}

tDado * RemoveElementoEnc(tTabelaEnc ** tabela, int id){
    tTabelaEnc *anterior = NULL, *atual = *tabela, *removido = NULL;
    while(atual != NULL){
        if (atual->dado.id == id){
            //elemento encontrado
            removido = atual;
            break;
        }
        anterior = atual;
        atual = atual->prox;
    }

    if (removido != NULL){
        if (anterior != NULL){
            anterior->prox = removido->prox;
        }else{
            //primeiro removido
            (*tabela)->prox = removido->prox;
        }
        tDado *retorno = malloc(sizeof(tDado));
        if (!retorno){
            puts("Erro ao alocar elemento para o retorno.");
            exit(1);
        }
        *retorno = removido->dado;
        free(removido);
        return retorno;
    }

    return NULL;
}

int EstaVaziaEnc(tTabelaEnc * tabela){
    return tabela == NULL;
}

void AcrescentaElementoEnc(tTabelaEnc **tabela, const tDado *elemento){
    tTabelaEnc *novo = malloc(sizeof(tTabelaEnc));
    if (!novo){
        puts("Erro ao alocar novo elemento.");
        exit(1);
    }
    novo->dado = *elemento;
    novo->prox = *tabela;
    *tabela = novo;
}

tDado * BuscaSequencialEnc(tTabelaEnc *tabela, int id){
    qOperacoes = 0;
    while(tabela != NULL){
        qOperacoes++;
        if (tabela->dado.id == id){
            return &tabela->dado;
        }
        tabela = tabela->prox;
    }

    return NULL;
}

tDado * BuscaDedilhadaEnc(tTabelaEnc *tab, int id){ 
    static tTabelaEnc *ultimoNo = NULL;
    if (ultimoNo == NULL){
        ultimoNo = tab;
    }

    qOperacoes = 0;
    while(ultimoNo != NULL){
        if (ultimoNo->dado.id == id){
            return &ultimoNo->dado;
        }
        ultimoNo = ultimoNo->prox;
    }

    return NULL;
}

int QuantOperacoesEnc(){
    return qOperacoes;
}

tDado *buscaTransposicaoEnc(tTabelaEnc **tabela, int chave) {
    qOperacoes = 0;
    tTabelaEnc *ant = NULL, *ant2 = NULL, *atual = *tabela;

    while (atual != NULL) {
        ++qOperacoes;

        if (atual->dado.id == chave)
            break;

        ant2 = ant;
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
        return NULL;

    if (ant == NULL)
        return &atual->dado;

    if (ant2 == NULL) {
        ant->prox = atual->prox;
        atual->prox = ant;
        *tabela = atual;
    } else {
        ant->prox = atual->prox;
        ant2->prox = atual;
        atual->prox = ant;
    }

    return &atual->dado;
}

tDado *buscaMovInicioEnc(tTabelaEnc **tabela, int chave) {
    qOperacoes = 0;
    tTabelaEnc *atual = *tabela, *ant = NULL;

    while (atual != NULL) {
        ++qOperacoes;

        if (atual->dado.id == chave)
            break;

        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
        return NULL;

    if (ant == NULL)
        return &atual->dado;

    ant->prox = atual->prox;
    atual->prox = *tabela;
    *tabela = atual;

    return &atual->dado;
}