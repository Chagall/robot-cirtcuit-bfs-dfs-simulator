#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"
#include "PilhaSequencialEstatica.h"
#define BRANCO 1
#define CINZA  2
#define PRETO  3

void inicializarGrafo(GRAFO* g, int numVer){

    int i, j;   // Vari�veis auxiliares

    g->numVer = numVer;         // Armazena o n�mero de v�rtices
    g->numAres = 0;             // Inicialmente n�o existem arestas
    g->cidadesVisitadas = 0;    // Nenhuma cidade foi visitada

    g->cidade = (int*)calloc(numVer,sizeof(int));       // Aloca vetor de cidades e inicializa com 0
    g->objetivo = (int*)calloc(numVer,sizeof(int));     // Aloca vetor de objetivos e inicializa com 0
    g->cor = (int*)calloc(numVer,sizeof(int));          // Aloca vetor de cores e inicializa com 0
    g->predecessor = (int*)calloc(numVer,sizeof(int));  // Aloca vetor de predecessores e inicializa com 0

    // Aloca o espa�o para a matriz de adjac�ncias
    g->adj = (int**)malloc((g->numVer)*sizeof(int*));
    for(i=0;i<(g->numVer);i++){
        g->adj[i] = (int*)malloc((g->numVer)*sizeof(int));
    }

    // Inicializa todas as posi��es da matriz de adjac�ncias com 0
    for(i=0;i<(g->numVer);i++){
        for(j=0;j<(g->numVer);j++){
            g->adj[i][j] = 0;
        }
    }

    // E insere todas as arestas existentes
    inserirAresta(g,0,6);
    inserirAresta(g,2,3);
    inserirAresta(g,2,8);
    inserirAresta(g,3,4);
    inserirAresta(g,3,9);
    inserirAresta(g,4,5);
    inserirAresta(g,4,10);
    inserirAresta(g,5,11);
    inserirAresta(g,6,7);
    inserirAresta(g,6,12);
    inserirAresta(g,7,8);
    inserirAresta(g,8,9);
    inserirAresta(g,8,14);
    inserirAresta(g,9,10);
    inserirAresta(g,9,15);
    inserirAresta(g,10,11);
    inserirAresta(g,10,16);
    inserirAresta(g,11,17);
    inserirAresta(g,12,18);
    inserirAresta(g,14,15);
    inserirAresta(g,14,20);
    inserirAresta(g,15,16);
    inserirAresta(g,15,21);
    inserirAresta(g,16,17);
    inserirAresta(g,16,22);
    inserirAresta(g,17,23);
    inserirAresta(g,20,21);
    inserirAresta(g,21,22);
    inserirAresta(g,22,23);

    // Insere quem s�o as cidades e o objetivo
    inserirCidadesObjetivo(g);
}

void inserirAresta(GRAFO* g, int i, int j){
    g->numAres = g->numAres + 2;
    g->adj[i][j] = 1;
    g->adj[j][i] = 1;
}

void destruirGrafo(GRAFO *g){

    int i;
    free(g->cidade);
    free(g->objetivo);
    free(g->cor);
    free(g->predecessor);

    for(i=0;i<(g->numVer);i++){
        free(g->adj[i]);
    }
    free(g->adj);
}

void inserirCidadesObjetivo(GRAFO* g){

    g->cidade[5] = 1;   // Cidade D
    g->cidade[18] = 1;  // Cidade A
    g->cidade[20] = 1;  // Cidade B
    g->cidade[23] = 1;  // Cidade C
    g->objetivo[2] = 1; // Objetivo

}

void buscaEmLargura(GRAFO* g, int ver){

    PILHA p;        // Pilha auxiliar para a busca
    int erro = 0;
    int retirado = 0;   // V�rtice retirado da Pilha
    int i = 0;

    // Inicializa o Vetor de Cores e de Predecessores
    for(i=0;i<(g->numVer);i++){
        g->cor[i] = BRANCO;
        g->predecessor[i] = -1;
    }

    g->cor[ver] = CINZA;    // Pinta o v�rtice visitado de cinza

    criarpilha(&p);     // Inicializa a Pilha
    push(&p,ver,&erro); // Empilha o vertice inicial na pilha

    // Enquanto a pilha n�o estiver vazia
    while(estavazia(&p) == 0){
        pop(&p,&retirado,&erro); // Retira o elemento do topo da pilha

        // Procura os v�rtices adjacentes a ele
        for(i=0;i<(g->numVer);i++){
            if(g->adj[retirado][i] == 1){   // Se o v�rtice "retirado" � adjacente a "i"
                if(g->cor[i] == BRANCO){    // Verifica se "i" n�o foi visitado ainda
                    // Se n�o foi, visita o v�rtice
                    pintaGrafo(i);
                    getchar();
                    system("cls");
                    // P�nta ele de cinza
                    g->cor[i] = CINZA;
                    // E o v�rtice "retirado" passa a ser o predecessor de "i"
                    g->predecessor[i] = retirado;
                    // Empilha o v�rtice "i"
                    push(&p,i,&erro);
                }
            }
        }

        // Depois de percorrer todos os  adjacentes ao
        // v�rtice "retirado", pinta ele de preto
        g->cor[retirado] = PRETO;
    }

    // Por fim, se move at� o objetivo final
    pintaGrafo(2);
    getchar();
    system("cls");

}
