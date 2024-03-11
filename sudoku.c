/* Trabalho em progresso */

#include <stdio.h>

int verificar_horizontal(int matriz[9][9]) {
    int i, j, l, check=1;
    for(int i=0; i<9 && check; i++)
        for(int j=0; j<9 && check; j++)
            for(int l=0; l<9 && check; l++)
                if((j != l) && (matriz[i][j] == matriz[i][l]))
                    check = 0;
    return check;
}

int verificar_vertical(int matriz[9][9]) {
    int i, j, l, check = 1;

    for(j = 0; j < 9 && check; j++)
        for(i = 0; i < 9 && check; i++)
            for(l = 0; l < 9 && check; l++)
                if((i != l) && (matriz[i][j] == matriz[l][j]))
                    check = 0;
    return check;
}

void testarMatriz(int matriz[9][9]){

    int i, j;
    for(i = 0; i < 9; i++)
        for(j = 0; j < 9; j++){
            scanf("%i", &matriz[i][j]);
            while(matriz[i][j] < 1 || matriz[i][j] > 9){
                scanf("%i", &matriz[i][j]);
            }
        }
}

int checarMenor(int mini[3][3]){

    int i, j, num, existe = 0;

    for(num = 1; num <= 9; num++){
        for(i = 0; i < 3; i++)
            for(j = 0; j < 3; j++)
                if(mini[i][j] == num) existe++;
        if(existe > 1) return 0;
        existe = 0;
    }

    return 1;
}

int checarMenores(int matriz[9][9]){

    int i, j, k, l, mini[3][3];

    for(i = 0; i < 9; i += 3)
        for(j = 0; j < 9; j += 3){
            for(k = 0; k < 3; k++)
                for(l = 0; l < 3; l++)
                    mini[k][l] = matriz[k+i][l+j];
            if(!checarMenor(mini))
                return 0;
        }

    return 1;
}

int main(){
    int matriz[9][9];
    testarMatriz(matriz);

    if(verificar_horizontal(matriz) && verificar_vertical(matriz) && checarMenores(matriz))
        printf("A matriz inserida forma um Sudoku. Parabéns!\n");
    else
        printf("A matriz inserida nao forma um Sudoku. Que pena!\n");

    return 0;
}
