#ifndef CONTROLE_H_INCLUDE
#define CONTROLE_H_INCLUDE

#include <stdio.h>
#include <stdlib.h>

typedef struct est{ //estrutura da lista duplamente encadeada
    int cont; //contador
    void* end; //o endereço
    struct est* prox; //ponteiro pro proximo
    struct est* ant; //ponteiro pro anterior
}est;



void* malloc2 (int tam); //prepara o bloco de lixo para ser isolado
est *atualizar(void *end, int i); //função que irá servir como a execução, onde irá procurar o endereço na lista para localizar e fazer as modificações, seja em mandar para exclusão ou adicionar +1 endereço (execução)
void attrib2(void* a, void* b); //codigo onde irá fazer as separações das chamadas dos parametros, mandando deixar seguir ou adicionar (menu)
void remocao(est* a, void* end); //responsavel por excluir na lista lixo o bloco que não tem + ligação
void dump(); //imprimir pilha

#endif //CONTROLE_H_INCLUDE