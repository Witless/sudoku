#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Matriz(int Mn[3][3]){
    int numbers[9] = {1,2,3,4,5,6,7,8,9};
    /* Este for simplemente "desordena" el array numbers */
    for (int i = 0; i < 9; i++) {
        int temp = numbers[i];
        int randomIndex = rand() % 9;
        numbers[i]           = numbers[randomIndex];
        numbers[randomIndex] = temp;
    }
    /* Este for pasa el array numbers desordenado, a una matriz 3x3 (en este caso, a la matriz que hayamos metido en la función */
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            Mn[i][j] = numbers[i*3+j];
        }
    }
    return 0;
    }

int main(void)
{
    srand(time(0)); /* Le metemos una seed al rand, porque si no, siempre es el mismo rand */
    int M1[3][3],M2[3][3],M3[3][3],M4[3][3],M5[3][3],M6[3][3],M7[3][3],M8[3][3],M9[3][3];

    /* Iniciamos todas las matrices (de momento, el plan es hacerlo poco a poco y que siga las normas */
    Matriz(M1);
    Matriz(M2);
    Matriz(M3);
    Matriz(M4);
    Matriz(M5);
    Matriz(M6);
    Matriz(M7);
    Matriz(M8);
    Matriz(M9);

    /* La tontería de aquí debajo es para printearlo de forma "sudoku" */
    for(int i = 0;i<3;i++){
       for(int j = 0;j<3;j++){
           printf("%i", M1[i][j]);
       }
       printf(" ");
       for(int j = 0;j<3;j++){
           printf("%i", M2[i][j]);
       }
       printf(" ");
       for(int j = 0;j<3;j++){
           printf("%i", M3[i][j]);
       }
       printf("\n");
    }
    printf("\n");
    for(int i = 0;i<3;i++){
       for(int j = 0;j<3;j++){
           printf("%i", M4[i][j]);
       }
       printf(" ");
       for(int j = 0;j<3;j++){
           printf("%i", M5[i][j]);
       }
       printf(" ");
       for(int j = 0;j<3;j++){
           printf("%i", M6[i][j]);
       }
       printf("\n");
    }
        printf("\n");
    for(int i = 0;i<3;i++){
       for(int j = 0;j<3;j++){
           printf("%i", M7[i][j]);
       }
       printf(" ");
       for(int j = 0;j<3;j++){
           printf("%i", M8[i][j]);
       }
       printf(" ");
       for(int j = 0;j<3;j++){
           printf("%i", M9[i][j]);
       }
       printf("\n");
    }
return 0;
}
