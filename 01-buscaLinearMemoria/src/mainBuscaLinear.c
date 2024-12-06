#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tabelaIndexada.h"
#include "tabelaEncadeada.h"

#define MAX_LINHA 5000

void RemoveQuebraLinha(char *str){
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
}

int CarregaArquivo(const char *arq, tTabelaIdx *tabIdx, tTabelaEnc **tabEnc){
    FILE *fp;
    char linha[MAX_LINHA+1], *id, *titulo, *avaliacao, *votos, *virg, *aspas;
    int cont;
    tFilme filme;

    fp = fopen(arq, "r");
    if (!fp){
        puts("Erro ao abrir arquivo.");
        exit(1);
    }

    cont = 0;
    while(1){
        fgets(linha, MAX_LINHA+1, fp);
        if (feof(fp)){
            break;
        }
        RemoveQuebraLinha(linha);
        virg = strchr(linha, ',');
        if (virg){
            virg[-1] = '\0';
            id = linha+1;
            
            titulo = virg + 2;
            aspas = strchr(titulo, '\"');
            *aspas = '\0';
            filme.id = atoi(id);
            filme.titulo = malloc(sizeof(char) * strlen(titulo) + 1);
            if (!filme.titulo){
                printf("Erro ao alocar titulo do filme #%d\n", cont);
            }
            strcpy(filme.titulo, titulo);
            
            avaliacao = aspas + 3;
            aspas = strchr(avaliacao, '\"');
            *aspas = '\0';
            filme.avaliacaoMedia = strtod(avaliacao, NULL);

            votos = aspas + 3;
            aspas = strchr(votos, '\"');
            *aspas = '\0';
            filme.qVotos = strtod(votos, NULL);

            cont++;
            //printf("Filme: %s [%s] (id=%s, votos=%s)\n", titulo, avaliacao, id, votos);
            AcrescentaElementoIdx(tabIdx, &filme);
            AcrescentaElementoEnc(tabEnc, &filme);
        }
    }

    fclose(fp);
    return cont;
}


int main(void){
    tTabelaIdx *tabIdx;
    tTabelaEnc *tabEnc;
    int q, mat;
    clock_t inicio, fim;
    double tempoDeCpu;

    tabIdx = CriaTabelaIdx();
    CriaTabelaEnc(&tabEnc);
    inicio = clock();
    q = CarregaArquivo("TMDB_movie_dataset_v11.csv", tabIdx, &tabEnc);
    fim = clock();
    tempoDeCpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    printf("%d filmes carregados.\n", q);
    printf("Tamanho tabela indexada: %d\n", ComprimentoIdx(tabIdx));
    printf("Tamanho tabela encadeada: %d\n", ComprimentoEnc(tabEnc));
    printf("Tempo de CPU: %lf\n", tempoDeCpu);


   while(1){
        printf("\nID: ");
        scanf("%d", &mat);

        inicio = clock();
        int ind = BuscaSequencial(tabIdx, mat);
        fim = clock();
        tempoDeCpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
        printf("Operacoes busca sequencial: %d\n", QuantOperacoes());
        printf("Tempo de CPU: %lf\n", tempoDeCpu);
        if (ind < 0){
            puts("filme nao encontrado");
        }else{
            tFilme filme = ObtemElementoIdx(tabIdx, ind);
            ImprimeFilme(&filme);
        }

        inicio = clock();
        tFilme * filme = BuscaSequencialEnc(tabEnc, mat);
        fim = clock();
        tempoDeCpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
        printf("Operacoes busca encadeada: %d\n", QuantOperacoesEnc());
        printf("Tempo de CPU: %lf\n", tempoDeCpu);
        if (!filme){
            puts("filme nao encontrado");
        }else{
            ImprimeFilme(filme);
        }
   }

    //DestroiTabelaEnc(tabEnc);
    DestroiTabelaIdx(tabIdx);
    return 0;
}