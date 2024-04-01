#include <stdio.h>
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
    printf("Funcao de deletar tarefa \n");
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