#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

int main(int argc, char* argv[]){

    // Inicialização do Grafo
    GRAFO* g = (GRAFO*)malloc(1*sizeof(GRAFO));
    // Inicializa-se o grafo com 24 vértices, pois o
    // grid percorrido pelo robo é uma matriz de 4 x 6
    // somando com 24 posições no total
    inicializarGrafo(g,24);

    // Imprime o Robô na Posição Inicial
    imprimirMapaPercurso(0,0);
    getchar();
    system("cls");

    // Realiza a Busca em Largura
    buscaEmLargura(g,0);

    // Liberação do espaço de memória alocado
    destruirGrafo(g);

    return 0;
}
