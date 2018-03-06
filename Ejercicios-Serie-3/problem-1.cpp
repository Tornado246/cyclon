#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int opcion;
	char empresaName[50]="",empresaAddress[150]="", empresaRubro[50]="";
	int ETrab,Ctrab,tJoven,tMaduro,tMayor;
	int edadMin = 18, edadMax = 65;
	bool continuar = true;
	
	do{
		printf("Elige la opcion deseada\n\n");
		printf("\t1. Captura datos de la empresa\n");
		printf("\t2. Imprimir datos de la empresa\n");
		printf("\t3. Captura las edades de los empleados\n");
		printf("\t4. Salir\n");
		scanf("%d",&opcion);
		
		if(opcion>4 || opcion<1){
			printf("Opción ingresada no es valida\n");
		}
		else{
			switch(opcion){
				case 1:
					//obtener la información definida para la empresa
					printf("Ingresa nombre de la empresa\n");
					scanf("%s",&empresaName);
					printf("Ingresa direccion de la empresa\n");
					scanf("%s",&empresaAddress);
					printf("Ingresa rubro de la empresa\n");
					scanf("%s",&empresaRubro);
					break;
				case 2:
					//imprimir la información definida para la empresa
					printf("Nombre de la Empresa       : %s\n",empresaName);
					printf("Direccion de la Empresa    : %s\n",empresaAddress);
					printf("Rubro de la Empresa        : %s\n",empresaRubro);
					break;
				case 3:
					Ctrab = 0;
					tJoven = 0;
					tMaduro = 0;
					tMayor = 0;
					do{
						do{
							printf("Ingrese la edad del trabajador %d (Para detener ingrese 0)\n",Ctrab+1);
							scanf("%d",&ETrab);		
						}while((ETrab>edadMax || ETrab<edadMin) && ETrab != 0);
						if(ETrab!=0){
							if(ETrab<22){
								tJoven = tJoven + 1;
							}
							else{
								if(ETrab<=50){
									tMaduro = tMaduro + 1;
								}
								else{
									tMayor = tMayor + 1;
								}
							}
							Ctrab = Ctrab + 1;
						}
					}while(ETrab!=0);
					
					printf("Cantidad de trabajadores Menores (entre %d y 21 a%cos) es: %d\n",edadMin,-92,tJoven);	//-92 es para imprimir letra ñ
					printf("Cantidad de trabajadores Maduros (entre 22 y 50 a%cos) es: %d\n",-92,tMaduro);
					printf("Cantidad de trabajadores Mayores (entre 51 y %d a%cos) es: %d\n",edadMax,-92,tMayor);
					
					break;
				default:	//opcion 4
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

