#include<stdio.h>
main ()

{
	unsigned i=0, array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, *p;

	
	// Esto sería sólo para una vez obtenidos los datos de la primera fila, generar una especie de tabla 
   do
   {
   
   printf(" %i |", array[i]);
   i++;
} while(i<9);

   //A partir de aquí se volverían a manipular las variables para imprimirlas en la siguiente fila y sucesivamente
}    






