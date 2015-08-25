#include <stdio.h>
#include <stdlib.h>

#define TAM_PILHA 100

struct pilha
{
	int elemPilha[TAM_PILHA];
	int topoPilha;
};

typedef struct pilha PILHA;

void criarpilha(PILHA *p);
void esvaziarpilha(PILHA *p);
int estacheia(PILHA *p);
int estavazia(PILHA *p);
void push(PILHA *p, int elem, int *erro);
void pop(PILHA *p, int *elem, int *erro);
void topo(PILHA *p, int *elem, int *erro);
void imprimirelementos(PILHA p);
int pilhasiguais(PILHA p1, PILHA p2);
