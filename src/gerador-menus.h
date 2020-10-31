#ifndef GERADOR_MENUS_H_INCLUDED
#define GERADOR_MENUS_H_INCLUDED

/**
 * @author: David Gomesh
 * 
 * Documentação: https://github.com/DavidGomesh/gerador-de-menus-c 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#include "console.h"

typedef struct tipo_tecla{
    int controle;
    int teclaAtual;
} Tecla;

void desenharBordas(int quant, int maiorTam){
    int limiteHorizontal = maiorTam+10;
    int limiteVertical = quant+3;
    for(int lin=1; lin<=limiteVertical; lin++){
        for(int col=1; col<=limiteHorizontal; col++){
            /* BORDAS */
            //Canto superior esquerdo
            if(lin==1 && col==1){
                gotoxy(col, lin);
                printf("%c", 201);
                continue;
            }

            //Canto superior direito
            if(lin==1 && col==limiteHorizontal){
                gotoxy(col, lin);
                printf("%c", 187);
                continue;
            }

            //Canto inferior direito
            if(lin==limiteVertical && col==limiteHorizontal){ 
                gotoxy(col, lin);
                printf("%c", 188);
                continue;
            }

            //Canto inferior esquerdo
            if(lin==limiteVertical && col==1){ 
                gotoxy(col, lin);
                printf("%c", 200);
                continue;
            }
            
            /* BARRAS */
            // Barras horizontais
            if((col>1 && col<limiteHorizontal) && (lin==1 || lin==limiteVertical)){
                gotoxy(col, lin);
                printf("%c", 205);
                continue;
            }

            // Barras verticais
            if((lin>1 && lin<limiteVertical) && (col==1 || col==limiteHorizontal)){ 
                gotoxy(col, lin);
                printf("%c", 186);
                if(col==1){
                    col=limiteHorizontal-1;
                }
                continue;
            }            
        }
    }
    printf("\n");
}

int selecionarOpcao(int quant){
    int opcaoSelecionada = 1;

    

    Tecla tecla;
    tecla.controle = -1;

    do{
        gotoxy(4, opcaoSelecionada+2);
        textcolor(WHITE);
        printf("%c", 175);
        textcolor(LIGHTGREEN);
        gotoxy(1,1);

        tecla.controle = getch();
        // printf("C: %i\n", tecla.controle);

        switch(tecla.controle){
            case 72:
                // printf("Subir!\n");
                gotoxy(4, opcaoSelecionada+2);
                printf("%c", 250);

                if(opcaoSelecionada!=1){
                    opcaoSelecionada--;
                }
                else{
                    opcaoSelecionada = quant;
                }

                break;

            case 80:
                // printf("Descer!\n");
                gotoxy(4, opcaoSelecionada+2);
                printf("%c", 250);

                if(opcaoSelecionada!=quant){
                    opcaoSelecionada++;
                }
                else{
                    opcaoSelecionada = 1;
                }

                break;
        }
    }while(tecla.controle != 13);

    gotoxy(1, quant+4);
    return opcaoSelecionada;
}

int gerarMenu(char titulo[], int quant, ...){
    va_list opcoes;
    va_start(opcoes, quant);

    char opcao[21];
    int maiorTam=strlen(titulo), tamAtual;


    printf("\n  %s\n", titulo, maiorTam);    

    for(int i=0; i<quant; i++){   
        strcpy(opcao, va_arg(opcoes, char *));

        tamAtual = strlen(opcao);
        if(tamAtual>maiorTam){
            maiorTam=tamAtual;
        }

        printf("   %c %s\n", 250, opcao, maiorTam);
    }

    va_end(opcoes);

    desenharBordas(quant, maiorTam);
    return selecionarOpcao(quant);
}

/*
    Horizontal: 5 + maiorTam + 5
    Vertical: 2 + quant + 1

    Canto superior direito: 201
    Canto superior esquerdo: 187
    Canto inferior esquerdo: 188
    Canto inferior direito: 200

    Barras horizontais: 205
    Barras verticais: 186

    Seta: 175
    Ponto: 250
    Quadrado: 254
*/


#endif /* GERADOR_MENUS_H_INCLUDED */