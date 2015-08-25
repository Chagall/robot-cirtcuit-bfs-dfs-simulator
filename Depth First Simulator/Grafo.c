#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"
#define BRANCO 1
#define CINZA  2
#define PRETO  3

void inicializarGrafo(GRAFO* g, int numVer){

    int i, j;   // Variáveis auxiliares

    g->numVer = numVer;         // Armazena o número de vértices
    g->numAres = 0;             // Inicialmente não existem arestas
    g->cidadesVisitadas = 0;    // Nenhuma cidade foi visitada

    g->cidade = (int*)calloc(numVer,sizeof(int));       // Aloca vetor de cidades e inicializa com 0
    g->objetivo = (int*)calloc(numVer,sizeof(int));     // Aloca vetor de objetivos e inicializa com 0
    g->cor = (int*)calloc(numVer,sizeof(int));          // Aloca vetor de cores e inicializa com 0
    g->predecessor = (int*)calloc(numVer,sizeof(int));  // Aloca vetor de predecessores e inicializa com 0

    // Aloca o espaço para a matriz de adjacências
    g->adj = (int**)malloc((g->numVer)*sizeof(int*));
    for(i=0;i<(g->numVer);i++){
        g->adj[i] = (int*)malloc((g->numVer)*sizeof(int));
    }

    // Inicializa todas as posições da matriz de adjacências com 0
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

    // Insere quem são as cidades e o objetivo
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

void visitar(GRAFO* g, int ver){

    int i = 0;

    // Se a posição visitada for uma cidade
    if(g->cidade[ver] == 1){
        g->cidadesVisitadas++;  // Armazena quantas cidades já foram visitadas
        if(g->cidadesVisitadas == 4){   // Se todas cidades já foram visitadas
            // Traça o percurso até o Objetivo
            pintaGrafo(12);
            getchar();
            system("cls");
            pintaGrafo(6);
            getchar();
            system("cls");
            pintaGrafo(7);
            getchar();
            system("cls");
            pintaGrafo(8);
            getchar();
            system("cls");
            pintaGrafo(2);
            getchar();
            system("cls");
            return;
        }
    }

    g->cor[ver] = CINZA;

    // Procura quem são os vértices adjacentes a "ver"
    for(i=0;i<(g->numVer);i++){
        if(g->adj[ver][i] == 1){ // Se os vértices "ver" e "i" são adjacentes
            if(g->cor[i] == BRANCO){ // E o vértice "i" não foi visitado
                // Visita o vértice "i"
                pintaGrafo(i);
                getchar();
                system("cls");
                // O vértice "ver" passa a ser o predecessor de "i"
                g->predecessor[i] = ver;
                // Chama a função de visita recursivamente passando o vértice "i"
                visitar(g,i);
            }
        }
    }

    g->cor[ver] = PRETO;

}

void buscaEmProfundidade(GRAFO* g){

    int i = 0;

    // Inicializa o Vetor de Cores e de Predecessores
    for(i=0;i<(g->numVer);i++){
        g->cor[i] = BRANCO;
        g->predecessor[i] = -1;
    }

     // Para todos os vértices existentes
     for(i=0;i<(g->numVer);i++){
        if(g->cor[i] == BRANCO){ // Se o vértice "i" não foi visitado
            // Visite o vértice "i"
            visitar(g,i);
        }
     }
}


