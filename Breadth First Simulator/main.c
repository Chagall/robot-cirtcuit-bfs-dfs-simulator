#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

int main(int argc, char* argv[]){

    // Inicializa��o do Grafo
    GRAFO* g = (GRAFO*)malloc(1*sizeof(GRAFO));
    // Inicializa-se o grafo com 24 v�rtices, pois o
    // grid percorrido pelo robo � uma matriz de 4 x 6
    // somando com 24 posi��es no total
    inicializarGrafo(g,24);

    // Imprime o Rob� na Posi��o Inicial
    imprimirMapaPercurso(0,0);
    getchar();
    system("cls");

    // Realiza a Busca em Largura
    buscaEmLargura(g,0);

    // Libera��o do espa�o de mem�ria alocado
    destruirGrafo(g);

    return 0;
}
