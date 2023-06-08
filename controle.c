#include"controle.h"
#include <stdio.h>
#include <stdlib.h>

est *lixo = NULL;

void* malloc2 (int tam){
    est* bloco = (est*)malloc(sizeof(est)); //auxiliar
    bloco->end = malloc(tam); //local para guardar endereços
    bloco->cont = 1; //contador deixado em todos os malloc2 como 1

    if(lixo == NULL){ //se n tiver a lista
        bloco->prox = NULL;
        bloco->ant = NULL;
    }else{ //caso tenha
        bloco->prox = lixo; //proximo bloco recebe a lista
        bloco->ant = NULL; //o anterior é excluido
        lixo->ant = bloco; //o bloco do meio é ligado ao bloco lixo/lista
    }
    lixo = bloco; //atribui o bloco a lista
    return lixo->end; //retorna o endereço da lista

}

est *atualizar(void *ender, int i){ //endereço e um inteiro para atualizar
    est* ax = lixo; //uma auxiliar recebe a lista lixo
    while (ax != NULL && ax->end != ender){
        ax = ax->prox; //procura
    }
    if(ax != NULL && ax->end == ender){ //encontrou o endereço
        ax->cont = ax->cont + i; //faz a modificação no contador
        if(ax->cont == 0){ //se chegar a 0, elimina
          remocao(lixo, ender); //manda a lista e o endereço
        }  
    }
}

void attrib2(void* a, void* b){ // recebe os parametros
    if(a != NULL){ // o "v" terá sua ligação retirada (simulando a atribuição)
        atualizar(a, -1);
        if(b != NULL){ //aqui o "w" irá receber a ligação do v, tendo agora 2 ponteiros apontando pra ele
            atualizar(b, 1);
        }
    }
    a = b;
}

void remocao(est* a, void* ender){
    est* ax = a; //estrutura auxiliar (est)
    while(ax != NULL && ax->end != ender){
        ax = ax->prox; //procura
    }
    if (ax != NULL){
        if(ax->ant == NULL && ax->prox == NULL){ //exclui um bloco sem nenhuma ligação
            free(ax->end);
            free(ax);
            return NULL;
        }else if(ax->ant == NULL && ax->prox != NULL){ //exclui o bloco sem ligação com o anterior
            ax->prox->ant = NULL; //excluiu a ligação do bloco seguinte com o atual/anterior
            a = ax->prox; //define o 2° como o 1°
            free(ax->end);
            free(ax);
        }else if(ax->ant != NULL && ax->prox == NULL){ //exclui o bloco sem ligação com o proximo
            ax->ant->prox = NULL; //exclui a ligação do bloco anterior com o atual
            free(ax->end);
            free(ax);
        }else{ //bloco no meio
            ax->ant->prox = ax->prox; //fez o bloco anterior apontar pro proximo bloco, após excluir o bloco do meio
            ax->prox->ant = ax->ant; //processo ao contrario do de cima (proximo aponta pro anterior)
            free(ax->end);
            free(ax);
        }
    }
    return a;
}

void dump(){ //imprimir a pilha (mostrar como está ela)
    est* aux = lixo; //abre a lista
    while(aux != NULL){ //printar apenas os valores que não forem nulos
        printf("Endereco: %p\n", aux->end);
        printf("Contador: %d\n", aux->cont);
        aux = aux->prox;
    }
}