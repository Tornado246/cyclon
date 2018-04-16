#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calcular_area_cuadrado(float lado){
	float area;
	printf("Calculando el area de un cuadrado\n");

	area = lado*lado;
	printf("El area del cuadrado es : %.2f\n",area);
}
void calcular_area_trapecio(float baseS, float baseI, float altura ){
	float area;
	printf("Calculando el area de un Trapecio\n");
	
	area = ((baseS+baseI)*altura/2);
	printf("El area del Trapecio es : %.2f\n",area);
}
void calcular_area_esfera(float radio){
	float Npi ,area;
	printf("Calculando el area de una Esfera\n");
	Npi = 3.1416;
	area = radio*radio*Npi*4;
	printf("El area de la Esfera es : %.2f\n",area);
}

void calcular_perimetro_rectangulo(float largo, float ancho){
	float perimetro;
	printf("Calculando el perimetro de un Rectangulo\n");
	perimetro = (largo+ancho)*2;
	printf("El perimetro del Rectangulo es : %.2f\n",perimetro);
}
void calcular_perimetro_triangulo(float lado1, float lado2, float lado3){
	float perimetro;
	printf("Calculando el perimetro de un Triangulo\n");
	perimetro = lado1+lado2+lado3;
	printf("El perimetro del Triangulo es : %.2f\n",perimetro);
}
void calcular_perimetro_circulo(float radio){
	float Npi ,perimetro;
	printf("Calculando el perimetro de un Circulo\n");
	
	Npi = 3.1416;
	
	perimetro = radio*Npi*2;
	printf("El perimetro del Circulo es : %.2f\n",perimetro);
}

bool menu_area(float cuadrado_lado,float trap_baseS,float trap_baseI,float trap_altura,float esfe_radio){
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
					calcular_area_cuadrado(cuadrado_lado);
					break;
				case 2:
					calcular_area_trapecio(trap_baseS,trap_baseI,trap_altura);
					break;
				case 3:
					calcular_area_esfera(esfe_radio);
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

bool menu_perimetro(float rect_largo, float rect_ancho,float tria_lado1,float tria_lado2,float tria_lado3, float circ_radio){
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
					calcular_perimetro_rectangulo(rect_largo,rect_ancho);
					break;
				case 2:
					calcular_perimetro_triangulo(tria_lado1,tria_lado2,tria_lado3);
					break;
				case 3:
					calcular_perimetro_circulo(circ_radio);
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
	float cuadrado_lado, trap_baseS, trap_baseI,trap_altura,esfe_radio,circ_radio,rect_largo,rect_ancho;
	float tria_lado1,tria_lado2,tria_lado3;
	printf("\tIngrese lado del cuadrado\n\t> ");	
	scanf("\t%f",&cuadrado_lado);
	printf("\tIngrese base superior del trapecio\n\t> ");	
	scanf("%f",&trap_baseS);
	printf("\tIngrese base inferior del trapecio\n\t> ");	
	scanf("%f",&trap_baseI);
	printf("\tIngrese altura del trapecio\n\t> ");
	scanf("%f",&trap_altura);
	printf("\tIngrese radio de la esfera\n\t> ");	
	scanf("%f",&esfe_radio);
	printf("\tIngrese radio del circulo\n\t> ");	
	scanf("%f",&circ_radio);
	printf("\tIngrese largo de rectangulo\n\t> ");	
	scanf("%f",&rect_largo);
	printf("\tIngrese ancho de rectangulo\n\t> ");	
	scanf("%f",&rect_ancho);
	printf("\tIngrese lado 1 del triangulo\n\t> ");	
	scanf("%f",&tria_lado1);
	printf("\tIngrese lado 2 del triangulo\n\t> ");	
	scanf("%f",&tria_lado2);
	printf("\tIngrese lado 3 del triangulo\n\t> ");	
	scanf("%f",&tria_lado3);
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
					continuar = menu_area(cuadrado_lado, trap_baseS, trap_baseI,trap_altura,esfe_radio);
					break;
				case 2:
					continuar = menu_perimetro(rect_largo,rect_ancho,tria_lado1,tria_lado2,tria_lado3,circ_radio);
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


