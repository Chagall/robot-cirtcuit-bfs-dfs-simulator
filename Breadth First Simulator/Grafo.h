#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

struct grafo{
    int numVer;             // Numero de vertices do grafo
    int numAres;            // Numero de arestas do grafo
    int cidadesVisitadas;   // Numero de cidades que já foram visitadas (0-4)
    int *cidade;            // vetor de 0 a (numVer-1) para marcar quais vertices são cidades
    int *objetivo;          // vetor de 0 a (numVer-1) para marcar qual vertice é objetivo
    int *cor;               // Vetor de cores
    int *predecessor;       // Vetor de predecessores de cada vértice
    int **adj;              // matriz de adjacências

};
typedef struct grafo GRAFO;

void inicializarGrafo(GRAFO* g, int numVer);
void inserirAresta(GRAFO* g, int i, int j);
void destruirGrafo(GRAFO *g);
void inserirCidadesObjetivo(GRAFO* g);
void imprimirMapaPercurso(int posX, int posY);
void pintaGrafo(int n);
void buscaEmLargura(GRAFO* g, int ver);

#endif // GRAFO_H_INCLUDED
