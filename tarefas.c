#include <stdio.h>
#include <string.h>
#include "tarefas.h"

ERROS criar(Tarefa tarefas[], int *pos){
    if(*pos>=TOTAL){
        return MAX_TAREFA;
    }
    printf("Entre com a prioridade: \n");
    scanf("%d",&tarefas[*pos].prioridade);

    clearBuffer();
    printf("Entre com a categoria: \n");
    fgets(tarefas[*pos].categoria, 100, stdin);


    printf("Entre com a descricao: \n");
    fgets(tarefas[*pos].descricao, 300, stdin);

    *pos = *pos + 1;

    return OK;
}

ERROS deletar(Tarefa tarefas[], int *pos) {
    //IF EXISTE TAREFA
    if(*pos==0){
        return SEM_TAREFAS;
    }
    int pos_deletar;

    printf("Entre com a posicao da tarefa a ser deletada: \n");
    scanf("%d",&pos_deletar);

    pos_deletar--; //garantir posicao certa no array

    //IF TAREFA ESCOLHIDA EXISTE
    if(pos_deletar >= *pos || pos_deletar<=0){
        return NAO_ENCONTRADO;
    }
    for(int i = pos_deletar; i < *pos;i++){
        tarefas[i].prioridade = tarefas[i+1].prioridade;
        strcpy(tarefas[i].categoria, tarefas[i+1].categoria);
        strcpy(tarefas[i].descricao, tarefas[i+1].descricao);
    }

    *pos = *pos - 1;

    return OK;
}

ERROS listar(Tarefa tarefas[], int *pos) {
    if(*pos==0){
        return SEM_TAREFAS;
    }
    for (int i = 0; i < *pos; i++) {
        printf("Pos: %d\t", i+1);
        printf("Prioridade: %d\t", tarefas[i].prioridade);
        printf("Categoria: %s\t", tarefas[i].categoria);
        printf("Descricao: %s\n", tarefas[i].descricao);
    }
    return OK;
    return OK;
}

ERROS salvar(Tarefa tarefas[], int *pos) {
    printf("Funcao de salvar tarefas \n");
    return OK;
}

ERROS carregar(Tarefa tarefas[], int *pos) {
    printf("Funcao de carregar tarefas \n");
    return OK;
}

void clearBuffer(){
    int c;
    while((c = getchar()) != '\n' && c!= EOF) { }
}