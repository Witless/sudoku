#include <stdio.h>
#include <stdlib.h>
#include <time.h>

<<<<<<< HEAD
/* Este programa AHORA MISMO, solo genera sudokus 2x3. También cabe destacar que cada x intentos, el programa no es capaz de alcanzar una solución, lo cual no da muchas esperanzas en el de 3x3... */
=======
>>>>>>> 3310aaabae1c53d6f7e6ebaa26223ccdfa66d93c
int Matriz(int Mn[3][3])
{
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

/* Esta función comprueba que las matrices sigan las normas en cuanto a filas. De no hacerlo, genera matrices hasta que las cumpla. */
int Check_row(int M1[3][3], int M2[3][3], int M3[3][3])
{
    int check = 0;
    do
    {
        check = 0;
        for(int i = 0; i<3;i++)
        {
            for(int j = 0; j<3;j++)
            {
                for(int k = 0; k<3;k++)
                {
                    if(M1[i][j] == M2[i][k])
                    {
                        Matriz(M2);
                        check = 1;
                    }
                    if(M1[i][j] == M3[i][k])
                    {
                        Matriz(M3);
                        check = 1;
                    }
                }
                for(int k = 0; k<3;k++)
                {
                    if(M2[i][j] == M3[i][k])
                    {
                        Matriz(M3);
                        check = 1;
                    }
                }
            }
        }
    }while(check);
    return 0;
}

/* Esta función comprueba que las matrices sigan las normas en cuanto a columnas. De no hacerlo, genera matrices hasta que las cumpla. */
int Check_col(int M1[3][3], int M2[3][3])
{
    int check = 0;
    do
    {
        check = 0;
        for(int i = 0; i<3;i++)
        {
            for(int j = 0; j<3;j++)
            {
                for(int k = 0; k<3;k++)
                {
                    if(M1[j][i] == M2[k][i])
                    {
                        Matriz(M2);
                        check = 1;
                    }
                }
            }
        }
    }while(check);
    return 0;
}

int Check_col2(int M1[3][3], int M2[3][3], int M3[3][3])
{
    int check = 0;
    do
    {
        check = 0;
        for(int i = 0; i<3;i++)
        {
            for(int j = 0; j<3;j++)
            {
                for(int k = 0; k<3;k++)
                {
                    if(M1[j][i] == M2[k][i])
                    {
                        Matriz(M2);
                        check = 1;
                    }
                    if(M1[j][i] == M3[k][i])
                    {
                        Matriz(M3);
                        check = 1;
                    }
                }
                for(int k = 0; k<3;k++)
                {
                    if(M2[j][i] == M3[k][i])
                    {
                        Matriz(M3);
                        check = 1;
                    }
                }
            }
        }
    }while(check);
    return 0;
}

int Check_rows_and_cols(int M1[3][3],int M2[3][3],int M3[3][3],int M4[3][3],int M5[3][3],int M6[3][3])
{
    int counter = 0;
    int check;
    do{
        check = 0;
        int temp1[3][3],temp2[3][3];
        /* Generamos las matrices M4, M5 y M6 siguiendo las normas en cuanto a columnas */
        Check_col(M1,M4);
        Check_col(M2,M5);
        Check_col(M3,M6);
        /* Este for almacena dichas matrices en matrices temporales (que nos serviran para saber si al comprobar si siguen las normas en cuanto filas, estas son alteradas) */
        for(int i = 0;i<3;i++)
        {
            for(int j = 0;j<3;j++)
            {
                temp1[i][j] = M5[i][j];
                temp2[i][j] = M6[i][j];
            }
        }
        /* Comprobamos si siguen las normas en cuanto a filas */
        Check_row(M4,M5,M6);
        /* Este for detecta cualquier cambio en las matrices, respecto a sus matrices temporales. Si son iguales, tenemos sudoku 2x3 */
        for(int i = 0;i<3;i++)
        {
            for(int j = 0;j<3;j++)
            {
                if((M5[i][j] != temp1[i][j])||(M6[i][j] != temp2[i][j]))
                {
                    check = 1;
                }
            }
        }
        printf("1");
        counter++;
        if(counter == 100)
        {
           counter = 0;
           Matriz(M1);
           Matriz(M2);
           Matriz(M3);
           Check_row(M1,M2,M3);
        }
    }while(check);
    return 0;
}

/* La tontería de aquí debajo es para printearlo de forma "sudoku" */
int Display(int M1[3][3],int M2[3][3],int M3[3][3],int M4[3][3],int M5[3][3],int M6[3][3],int M7[3][3],int M8[3][3],int M9[3][3])
{
    for(int i = 0;i<3;i++)
    {
       for(int j = 0;j<3;j++)
       {
           printf("%i", M1[i][j]);
       }
       printf(" ");
       for(int j = 0;j<3;j++)
       {
           printf("%i", M2[i][j]);
       }
       printf(" ");
       for(int j = 0;j<3;j++)
       {
           printf("%i", M3[i][j]);
       }
       printf("\n");
    }
    printf("\n");
    for(int i = 0;i<3;i++)
    {
       for(int j = 0;j<3;j++)
       {
           printf("%i", M4[i][j]);
       }
       printf(" ");
       for(int j = 0;j<3;j++)
       {
           printf("%i", M5[i][j]);
       }
       printf(" ");
       for(int j = 0;j<3;j++)
       {
           printf("%i", M6[i][j]);
       }
       printf("\n");
    }
        printf("\n");
    for(int i = 0;i<3;i++)
    {
       for(int j = 0;j<3;j++)
       {
           printf("%i", M7[i][j]);
       }
       printf(" ");
       for(int j = 0;j<3;j++)
       {
           printf("%i", M8[i][j]);
       }
       printf(" ");
       for(int j = 0;j<3;j++)
       {
           printf("%i", M9[i][j]);
       }
       printf("\n");
    }
    return 0;
}

int main(void)
{
    srand(time(0)); /* Le metemos una seed al rand, porque si no, siempre es el mismo rand */
    int M1[3][3],M2[3][3],M3[3][3],M4[3][3],M5[3][3],M6[3][3],M7[3][3],M8[3][3],M9[3][3];
    int check, dif, j, r, s;
    int counter = 0;
    int k = rand()%9;
    int l = rand()%9;
    char u = '?';
    char x='?';
    char M11[3][3];

    /* Iniciamos todas las matrices */
    Matriz(M1);
    Matriz(M2);
    Matriz(M3);
    Check_row(M1,M2,M3);
    Matriz(M4);
    Check_col(M1,M4);
    Matriz(M5);
    Check_col(M2,M5);
    Matriz(M6);
    Check_col(M3,M6);
    Check_rows_and_cols(M1,M2,M3,M4,M5,M6);
    /* Las ultimas 3 matrices solo siguen las normas en cuanto a filas, falta solucionar esta ultima parte */
    Matriz(M7);
    Matriz(M8);
    Matriz(M9);

    do{
        check = 0;
        int temp1[3][3],temp2[3][3],temp3[3][3];
        /* Generamos las matrices M4, M5 y M6 siguiendo las normas en cuanto a columnas */
        Check_col2(M1,M4,M7);
        Check_col2(M2,M5,M8);
        Check_col2(M3,M6,M9);
        /* Este for almacena dichas matrices en matrices temporales (que nos serviran para saber si al comprobar si siguen las normas en cuanto filas, estas son alteradas) */
        for(int i = 0;i<3;i++)
        {
            for(int j = 0;j<3;j++)
            {
                temp1[i][j] = M7[i][j];
                temp2[i][j] = M8[i][j];
                temp3[i][j] = M9[i][j];
            }
        }
        /* Comprobamos si siguen las normas en cuanto a filas */
        Check_row(M7,M8,M9);
        /* Este for detecta cualquier cambio en las matrices, respecto a sus matrices temporales. Si son iguales, tenemos sudoku 2x3 */
        for(int i = 0;i<3;i++)
        {
            for(int j = 0;j<3;j++)
            {
                if((M7[i][j] != temp1[i][j])||(M8[i][j] != temp2[i][j])||(M9[i][j] != temp3[i][j]))
                {
                    check = 1;
                }
            }
        }
        counter++;
        if(counter == 100)
        {
           counter = 0;
           Matriz(M4);
           Matriz(M5);
           Matriz(M6);
           Check_rows_and_cols(M1,M2,M3,M4,M5,M6);
        }
        printf("2");
    }while(check);

    printf("\n");
    Display(M1,M2,M3,M4,M5,M6,M7,M8,M9);

    printf("1 Dificultad Baja\n 2 Dificultad Media\n 3 Dificultad Difícil\n 4 Dificultad Extrema\n");

      scanf("%d", &dif);
    switch (dif)
    {
      case 1:
        for (int i=1; i<=10; i++)
        {
          j=rand()%9;

          switch (j)
          {

            case 1 :
             for (r=0;r<3;r++)
             {
                for (s=0;s<3;s++)
                {
                M11[r][s]=M1[r][s];
                }
             }
             M11[k][l] = u;
             printf(M1);

            break;


          }



        }





    }

   Display(M11,M2,M3,M4,M5,M6,M7,M8,M9);




return 0;
}
