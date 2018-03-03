#include <stdio.h>
#include <stdlib.h>

int main()
{
	int contar, maxContador ,inicial;
	int nPosit[50];
	
	contar = 0;
	maxContador = 50;
	inicial = 1;
	while(contar < maxContador)  {
		if(inicial % 2 == 0)  {
			nPosit[contar] = inicial;
			contar = contar+1;
		}
		inicial = inicial+1;
	}

	for(contar = maxContador-1;contar>=0; contar--  ){
		printf("%d \n",nPosit[contar]) ;
	}

	system("PAUSE");
    return 0;
}
