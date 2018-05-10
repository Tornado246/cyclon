#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definición de variables globales
int i;

//Definición de estructuras del caso
struct disco{
	char titulo[50];
	int numero_canciones;
};

struct cantante{
	char nombre[50];
	int edad;
	int numero_discos;
	disco discos[99];
};

struct pelicula{
	char clasificacion[30];
	char nombre[50];
	char nombre_personaje[50];
};

struct novela{
	char nombre[50];
	char nombre_personaje[50];
};

struct actor{
	char nombre[50];
	int edad;
	int numero_peliculas;
	pelicula peliculas[99];
	int numero_novelas;
	novela novelas[99];
};

//Definición de prototipos de funciones (para ser definidas completamente abajo de main)
cantante cantante_registrar();
void cantante_mostrar(cantante C);
actor actor_registrar();
void actor_mostrar(actor A);
disco disco_registrar(int indice);
pelicula pelicula_registrar(int indice);
novela novela_registrar(int indice);

int main(){
	int opcion;
	bool salir = false;
	while(!salir){
		system("cls");
		printf("Indique el tipo de artista que desea almacenar\n");
		printf("\t1) Cantante\n");
		printf("\t2) Actor\n");
		printf("\n\t\tSu opcion : ");
		scanf("%i",&opcion);
	
		switch(opcion){
			case 1:
				cantante nuevo_cantante;
				nuevo_cantante = cantante_registrar();
				cantante_mostrar(nuevo_cantante);
				break;
			case 2:
				actor nuevo_actor;
				nuevo_actor = actor_registrar();
				actor_mostrar(nuevo_actor);
				break;
			default:
				//opcion invalida
				salir = true;
		}	
	}
	
	return 0;
}

cantante cantante_registrar(){
	system("cls");
	printf("Ingresa la informacion del cantante\n\n");
	cantante nuevo;
	printf("Ingrese nombre del cantante\n");
	scanf("%s",&nuevo.nombre);
	printf("Ingrese edad del cantante\n");
	scanf("%i",&nuevo.edad);
	do{
		printf("Ingrese cantidad de discos del cantante\n");
		scanf("%i",&nuevo.numero_discos);
		if(nuevo.numero_discos>99){
			printf("\tEl maximo posible de discos a ingresar es 99\n");
		}
	}while(nuevo.numero_discos>99);
	
	for(i=0;i<nuevo.numero_discos;i++){
		nuevo.discos[i] = disco_registrar(i+1);
	}
	return nuevo;
}
void cantante_mostrar(cantante Scantante){
	system("cls");
	printf("Informacion registrada del Cantante\n");
	printf("\tNombre  : %s\n",Scantante.nombre);
	printf("\tEdad    : %i\n",Scantante.edad);
	printf("\tDiscos  : %i\n",Scantante.numero_discos);
	for(i=0;i<Scantante.numero_discos;i++){
		printf("\t   %i) ",i+1);
		printf("\t%s (%i canciones)\n",Scantante.discos[i].titulo,Scantante.discos[i].numero_canciones);
	}
	system("pause");
}

actor actor_registrar(){
	system("cls");
	printf("Ingresa la informacion del actor");
	actor nuevo;
	printf("Ingrese nombre del actor\n");
	scanf("%s",&nuevo.nombre);
	printf("Ingrese edad del actor\n");
	scanf("%i",&nuevo.edad);
	do{
		printf("Ingrese cantidad de peliculas del actor\n");
		scanf("%i",&nuevo.numero_peliculas);
		if(nuevo.numero_peliculas>99){
			printf("\tEl maximo posible de peliculas a ingresar es 99\n");
		}
	}while(nuevo.numero_peliculas>99);
	
	for(i=0;i<nuevo.numero_peliculas;i++){
		nuevo.peliculas[i] = pelicula_registrar(i+1);
	}
	
	do{
		printf("Ingrese cantidad de novelas del actor\n");
		scanf("%i",&nuevo.numero_novelas);
		if(nuevo.numero_novelas>99){
			printf("\tEl maximo posible de novelas a ingresar es 99\n");
		}
	}while(nuevo.numero_novelas>99);
	
	for(i=0;i<nuevo.numero_novelas;i++){
		nuevo.novelas[i] = novela_registrar(i+1);
	}
	return nuevo;
}
void actor_mostrar(actor Sactor){
	system("cls");
	printf("Información registrada del Actor\n");
	printf("\tNombre del Actor : %s\n",Sactor.nombre);
	printf("\tEdad del Actor   : %s\n",Sactor.edad);
	printf("\tPeliculas              : %i\n",Sactor.numero_peliculas);
	for(i=0;i<Sactor.numero_peliculas;i++){
		printf("\tPELICULA %i\n",i+1);
		printf("\tNombre Pelicula                 : %s\n",Sactor.peliculas[i].nombre);
		printf("\tClasificacion Pelicula          : %s\n",Sactor.peliculas[i].clasificacion);
		printf("\tNombre del Actor en la Pelicula : %s\n",Sactor.peliculas[i].nombre_personaje);
	}
	printf("\n\tNovelas              : %i\n",Sactor.numero_novelas);
	for(i=0;i<Sactor.numero_novelas;i++){
		printf("\tNOVELA %i\n",i+1);
		printf("\tNombre Novela                 : %s\n",Sactor.novelas[i].nombre);
		printf("\tNombre del Actor en la Novela : %s\n",Sactor.novelas[i].nombre_personaje);
	}
	system("pause");
	
}

disco disco_registrar(int indice){
	disco nuevo;
	printf("\tIngrese el titulo del disco %i\n\t",indice);
	scanf("%s",&nuevo.titulo);
	printf("\tIngrese la cantidad de canciones del disco %i\n\t",indice);
	scanf("%i",&nuevo.numero_canciones);
	return nuevo;
}

pelicula pelicula_registrar(int indice){
	pelicula nueva;
	printf("\tIngrese el nombre de la pelicula %i\n\t",indice);
	scanf("%s",&nueva.nombre);
	printf("\tIngrese la clasificacion de la pelicula %i\n\t",indice);
	scanf("%s",&nueva.clasificacion);
	printf("\tIngrese el nombre del personaje en la pelicula %i\n\t",indice);
	scanf("%s",&nueva.nombre_personaje);
	return nueva;
}

novela novela_registrar(int indice){
	novela nueva;
	printf("\tIngrese el nombre de la novela %i\n\t",indice);
	scanf("%s",&nueva.nombre);
	printf("\tIngrese el nombre del personaje en la novela %i\n\t",indice);
	scanf("%s",&nueva.nombre_personaje);
	return nueva;
}
