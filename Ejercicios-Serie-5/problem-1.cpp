#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calcular_area_cuadrado(){
	float lado,area;
	printf("Calculando el area de un cuadrado\n");
	
	printf("\tIngrese lado\n\t> ");	
	scanf("\t%f",&lado);
	area = lado*lado;
	printf("El area del cuadrado es : %.2f\n",area);
}
void calcular_area_trapecio(){
	float baseS, baseI, altura ,area;
	printf("Calculando el area de un Trapecio\n");
	
	printf("\tIngrese base superior\n\t> ");	
	scanf("%f",&baseS);
	printf("\tIngrese base inferior\n\t> ");	
	scanf("%f",&baseI);
	printf("\tIngrese altura\n\t> ");	
	scanf("%f",&altura);
	
	area = ((baseS+baseI)*altura/2);
	printf("El area del Trapecio es : %.2f\n",area);
}
void calcular_area_esfera(){
	float radio, Npi ,area;
	printf("Calculando el area de una Esfera\n");
	Npi = 3.1416;
	printf("\tIngrese radio\n\t> ");	
	scanf("%f",&radio);
	
	area = radio*radio*Npi*4;
	printf("El area de la Esfera es : %.2f\n",area);
}

void calcular_perimetro_rectangulo(){
	float largo, ancho ,perimetro;
	printf("Calculando el perimetro de un Rectangulo\n");
	
	printf("\tIngrese largo\n\t> ");	
	scanf("%f",&largo);
	printf("\tIngrese ancho\n\t> ");	
	scanf("%f",&ancho);
	
	
	perimetro = (largo+ancho)*2;
	printf("El perimetro del Rectangulo es : %.2f\n",perimetro);
}
void calcular_perimetro_triangulo(){
	int i;
	float lado[3] ,perimetro;
	printf("Calculando el perimetro de un Triangulo\n");
	
	for(i=0;i<3;i++){
		printf("\tIngrese lado %d\n\t> ",(i+1));	
		scanf("%f",&lado[i]);	
	}
	
	perimetro = lado[0]+lado[1]+lado[2];
	printf("El perimetro del Triangulo es : %.2f\n",perimetro);
}
void calcular_perimetro_circulo(){
	float radio, Npi ,perimetro;
	printf("Calculando el perimetro de un Circulo\n");
	
	Npi = 3.1416;
	printf("\tIngrese radio\n\t> ");	
	scanf("%f",&radio);
	
	perimetro = radio*Npi*2;
	printf("El perimetro del Circulo es : %.2f\n",perimetro);
}

bool menu_area(){
	system("cls");
	int opcion;
	bool continuar = true, volver = true;
	
	do{
		printf("Calcular area de:\n\n");
		printf("\t1. Cuadrado\n");
		printf("\t2. Trapecio\n");
		printf("\t3. Esfera\n");
		printf("\t4. Salir\n");
		scanf("%d",&opcion);
		
		if(opcion>4 || opcion<1){
			printf("Opcion ingresada no es valida\n");
		}
		else{
			switch(opcion){
				case 1:
					calcular_area_cuadrado();
					break;
				case 2:
					calcular_area_trapecio();
					break;
				case 3:
					calcular_area_esfera();
					break;
				default:	//opcion 4
					continuar = false;
					char salir[1];
					printf("Esta seguro que desea salir del programa? \n(s para Confirmar, otra tecla para volver al menu anterior)\n");
					scanf("%s",&salir);
					
					if(strcmp(salir,"s")==0){	//funcion retorna 0 si salir es igual a "s"
						volver = false;
						printf("Hasta luego\n");
					}
					break;
			}
		}
		if(continuar){
			system("pause");
			system("cls");
		}
		
	}while(continuar);
	
	return volver;
}

bool menu_perimetro(){
	system("cls");
	int opcion;
	bool continuar = true, volver = true;
	
	do{
		printf("Calcular perimetro de:\n\n");
		printf("\t1. Rectangulo\n");
		printf("\t2. Triagulo\n");
		printf("\t3. Circulo\n");
		printf("\t4. Salir\n");
		scanf("%d",&opcion);
		
		if(opcion>4 || opcion<1){
			printf("Opcion ingresada no es valida\n");
		}
		else{
			switch(opcion){
				case 1:
					calcular_perimetro_rectangulo();
					break;
				case 2:
					calcular_perimetro_triangulo();
					break;
				case 3:
					calcular_perimetro_circulo();
					break;
				default:	//opcion 4
					continuar = false;
					char salir[1];
					printf("Esta seguro que desea salir del programa? \n(s para Confirmar, otra tecla para volver al menu anterior)\n");
					scanf("%s",&salir);
					
					if(strcmp(salir,"s")==0){	//funcion retorna 0 si salir es igual a "s"
						volver = false;
						printf("Hasta luego\n");
					}
					break;
			}
		}
		if(continuar){
			system("pause");
			system("cls");
		}
		
	}while(continuar);
	
	return volver;
}

int main()
{
	int opcion;
	bool continuar = true;
	
	do{
		printf("Seleccione la informacion que desea calcular:\n\n");
		printf("\t1. Areas\n");
		printf("\t2. Perimetros\n");
		printf("\t3. Salir\n");
		scanf("%d",&opcion);
		
		if(opcion>3 || opcion<1){
			printf("Opcion ingresada no es valida\n");
		}
		else{
			switch(opcion){
				case 1:
					continuar = menu_area();
					break;
				case 2:
					continuar = menu_perimetro();
					break;
				default:	//opcion 3
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


