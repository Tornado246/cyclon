#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int veces,i,x,aux;
	printf("Ingrese la cantidad valores enteros va a capturar\n");
	scanf("%d",&veces);
	
	int arreglo[veces],ordenado[veces];
	int opcion;
	bool continuar = true;
	
	do{
		printf("Elige la opcion deseada\n\n");
		printf("\t1. Capturar valores\n");
		printf("\t2. Ordenar valores\n");
		printf("\t3. imprimir valores originales\n");
		printf("\t4. imprimir valores ordenados\n");
		printf("\t5. Salir\n");
		scanf("%d",&opcion);
		
		if(opcion>5 || opcion<1){
			printf("Opción ingresada no es valida\n");
		}
		else{
			switch(opcion){
				case 1:
					for(i=0;i<veces;i++){
						printf("Ingresa Entero %d :\t",(i+1));
						scanf("%d",&arreglo[i]);
						//voy copiando en arreglo para ordenar luego
						ordenado[i]=arreglo[i];
					}
					break;
				case 2:
					//ordenar metodo burbuja (simple)
					for(i=0;i<veces-1;i++){
				        for(x=i+1;x<veces;x++){
					        if(ordenado[i]>ordenado[x]){
					        	aux=ordenado[i];
					            ordenado[i]=ordenado[x];
					            ordenado[x]=aux;
					        }
						}
				    }
				    printf("Se ha ordenado correctamente el arreglo\n");
					break;
				case 3:
					//imprimir origina
					for(i=0;i<veces;i++){
						printf("Entero [%d] : %d\n",(i+1),arreglo[i]);
					}
					break;
				case 4:
					//imprimir ordenado
					for(i=0;i<veces;i++){
						printf("Entero [%d] : %d\n",(i+1),ordenado[i]);
					}
					break;		
				default:	//opcion 5
					char salir[1];
					printf("Esta seguro que desea salir? (s para Confirmar, otra para Cancelar)\n");
					scanf("%s",&salir);
					
					if(strcmp(salir,"s")==0){	//funcion retorna 0 si salir es igual a "s"
						continuar = false;
						printf("Hasta luego\n");
					}
					break;
			}
		}
		system("pause");
		system("cls");
	}while(continuar);
	
    return 0;
}

