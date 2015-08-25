#include <stdio.h>

void imprimirMapaPercurso(int posX, int posY){

	int i, j = 0;
    printf("\t\t\tBUSCA EM LARGURA\n\n");
    printf("\tO = Obstaculo\n");
    printf("\tG = Objetivo\n");
    printf("\tA,B,C,D = Cidades\n");
    printf("\tR = Robo\n\n");
    printf("\tPressione a tecla Enter para avancar ao proximo passo.\n\n\n");

    for(i=0;i<4;i++){
        printf("\t\t\t");
        for(j=0;j<=6;j++){

            if(i==posX && j==posY){
                printf("|R");
            }
            else if(i==0 && j==1){
                printf("|O");
            }
            else if(i==2 && j==1){
                printf("|O");
            }
            else if(i==2 && j==3){
                printf("|O");
            }
            else if(i==3 && j==1){
                printf("|O");
            }
            else if(i==0 && j==2){
                printf("|G");
            }
            else if(i==3 && j==0){
                printf("|A");
            }
            else if(i==3 && j==2){
                printf("|B");
            }
            else if(i==0 && j==5){
                printf("|D");
            }
            else if(i==3 && j==5){
                printf("|C");
            }
            else{
                printf("| ");
            }
        }
        printf("\n");
    }
}

void pintaGrafo(int n) {

	switch(n) {
        case 0:
            imprimirMapaPercurso(0,0);
            break;
        case 1:
            imprimirMapaPercurso(0,1);
            break;
        case 2:
        	imprimirMapaPercurso(0,2);
            break;
        case 3:
            imprimirMapaPercurso(0,3);
            break;
		case 4:
            imprimirMapaPercurso(0,4);
            break;
        case 5:
            imprimirMapaPercurso(0,5);
            break;
        case 6:
            imprimirMapaPercurso(1,0);
            break;
        case 7:
            imprimirMapaPercurso(1,1);
            break;
        case 8:
            imprimirMapaPercurso(1,2);
            break;
        case 9:
            imprimirMapaPercurso(1,3);
            break;
        case 10:
            imprimirMapaPercurso(1,4);
            break;
        case 11:
            imprimirMapaPercurso(1,5);
            break;
        case 12:
            imprimirMapaPercurso(2,0);
            break;
        case 13:
            imprimirMapaPercurso(2,1);
            break;
        case 14:
            imprimirMapaPercurso(2,2);
            break;
        case 15:
            imprimirMapaPercurso(2,3);
            break;
        case 16:
            imprimirMapaPercurso(2,4);
            break;
        case 17:
            imprimirMapaPercurso(2,5);
            break;
        case 18:
            imprimirMapaPercurso(3,0);
            break;
        case 19:
            imprimirMapaPercurso(3,1);
            break;
        case 20:
            imprimirMapaPercurso(3,2);
            break;
        case 21:
            imprimirMapaPercurso(3,3);
            break;
        case 22:
            imprimirMapaPercurso(3,4);
            break;
        case 23:
            imprimirMapaPercurso(3,5);
            break;
        default:
            printf("Valor não existente");
            break;
    }
}


