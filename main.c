#include <stdio.h>
#include <stdlib.h>
#include "controle.h" //chamada do cabeçalho

int main()
{
    int *v = (int*)malloc2(sizeof(int)); // malloc2 (&a)
    *v = 10;
    printf("1° dump\n");
    dump(); //chega o 1° parametro, onde irá mostrar o contador 1
    int *w = (int*)malloc2(sizeof(int));
    *w = 20;
    printf("2° dump\n");
    dump (); // chega o segundo, onde irá mostrar o parametro 1 como cont = 1 e o segundo a mesma coisa

    attrib2(v,w); 
    printf("3° dump\n");
    dump(); // nesse daqui, a lista ele deixa de apontar pro v e passa a apontar pro w, onde o w começa a ter cont = 2 e o v fica com cont = 0, nisso na lista criada para excluir o lixo, elimina o v
    attrib2(w, NULL); //1 - 0
    printf("4° dump\n");
    dump(); // aqui a gente retira +1 contador do w, porem ela não é excluida pq ainda tem um endereço apontando pra ela

    return 0;
}
