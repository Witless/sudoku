#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
int matriz[25][25];
int Corrector(int i, int j)
{
    matriz[i][j] = 0;
    for(i=0;i<25;i++)
    {
        for(j=0;j<25;j++)
        {
             printf("%d",matriz[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    srand(time(NULL));
    int i, j;
    //generamos matriz
    for(i=0;i<25;i++)
    {
        for(j=0;j<25;j++)
        {
            matriz[i][j] = rand() % 10;
        }
    }
    for(i=0;i<25;i++)
    {
        for(j=0;j<25;j++)
        {
            printf("%d",matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n-------------------------------------------------------------\n");
    for (i = 1; i<25;i++)
    {
        for(j=0;j<i;j++)
        {
            Corrector(i,j);
            printf("\n-------------------------------------------------------------\n");
        }
    }
    return 0;
}

