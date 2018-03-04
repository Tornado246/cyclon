#include <stdio.h>
#include <stdlib.h>

int main()
{
	int base, cantidad,cont1,cont2;
	printf("Programa para imprimir una tabla de multiplicar\n\n");
	printf("Ingrese la base de la tabla que desea mostrar\n");
	scanf("%d",&base);
	printf("Ingrese hasta donde quiere imprimir la tabla\n");
	scanf("%d",&cantidad);
	for(cont1=1;cont1<=cantidad;cont1++) {
		printf("\t %d x %d = %d\n",base,cont1,(base*cont1)) ;
	}
	
	system("PAUSE");
    return 0;
}
