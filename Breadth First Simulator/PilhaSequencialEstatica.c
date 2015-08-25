#include <stdio.h>
#include <stdlib.h>
#include "PilhaSequencialEstatica.h"

void criarpilha(PILHA *p)
{
	p->topoPilha = -1;

	return;
}

void esvaziarpilha(PILHA *p)
{
	p->topoPilha = -1;

	return;
}

int estacheia(PILHA *p)
{
	if(p->topoPilha == 99)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int estavazia(PILHA *p)
{
	if(p->topoPilha == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(PILHA *p, int elem, int *erro)
{
	if(estacheia(p) == 0)
	{
		p->topoPilha++;
		p->elemPilha[p->topoPilha] = elem;
		*erro = 0;
	}
	else
	{
		*erro = 1;
	}

	return;
}

void pop(PILHA *p, int *elem, int *erro)
{
	if(estavazia(p) == 0)
	{
		*elem = p->elemPilha[p->topoPilha];
		p->topoPilha--;
		*erro = 0;
	}
	else
	{
		*erro = 1;
	}
}

void topo(PILHA *p, int *elem, int *erro)
{
	if(estavazia(p) == 0)
	{
		*elem = p->elemPilha[p->topoPilha];
		*erro = 0;
	}
	else
	{
		*erro = 1;
	}

	return;
}

void imprimirelementos(PILHA p)
{
	int i;
	int x;
    int erro;

    printf("Pilha:\n");

    while(estavazia(&p) != 1)
    {
        pop(&p,&x,&erro);
        printf("%d\n", x);
    }

    printf("\n");

	return;
}

int pilhasiguais(PILHA p1, PILHA p2)
{
	int i;
	int x1, x2;
	int erro1, erro2;
	int iguais = 1;

    topo(&p1,&x1,&erro1);
    topo(&p2,&x2,&erro2);

	if(x1 == x2)
	{
	    while(estavazia(&p1) != 1)
        {
            pop(&p1,&x1,&erro1);
            pop(&p2,&x2,&erro2);

            if((x1 != x2) || (erro1 != erro2))
            {
                iguais = 0;
                break;
            }
        }
	}
	else
	{
		iguais = 0;
		return iguais;
	}

	return iguais;
}
