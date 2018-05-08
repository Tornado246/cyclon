#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//variables globales
int opcion, salir=-1, i, maximo_ingresos=20;

//estructura de participante
struct participantes{
    int codigo, edad, carreras, categoria, sexo, indice;
    char nombre[20], nacionalidad[20];
}participante[99];

int registroCarrera(int n);
int altaParticipante(int n);
int mostrarRegistros(int n);
int mostrarParticipantes(int n);

participantes encontrar_participante_x_cod(int cod, int max_participantes);

int main(){
	int numb=0; //contador de participantes maximo
    salir=0;
    while(salir!=1){
    	system("cls");
        printf("Menu Principal sistema de carreras olimpicas de la universidad.\n  A continuacion le mostramos el menu con las opciones a elegir.\n");
        printf("\nElija una opcion: \n1.Dar de alta a un participante \n2.Registrar en carrera \n3.Mostrar registros\n4.Mostrar todos los participantes\n5.Salir\n");
        scanf("%i",&opcion);
        switch (opcion){
            case 1:
                numb = altaParticipante(numb);
            break;
            case 2:
                registroCarrera(numb);
            break;
            case 3:
                mostrarRegistros(numb);
            break;
            case 4:
                mostrarParticipantes(numb);
            break;
            case 5:
                printf("\nRealmente desea salir?\n1.Si\n2.Regresar\n");
                scanf("%i",&salir);
            break;
            default:
                printf("\nElija una opcion valida\n");
                system("pause");
            break;
        }
    }
    return 0;
}

//funcion dar de alta al participante
int altaParticipante(int n){
    int cod=-1, s;
    do{
        salir=0;
        while(salir<2){
        	if (n==maximo_ingresos){
            	printf("\nHa alcanzado el maximo de participantes posibles de registrar (%i)\n",maximo_ingresos); //pedir nuevo participante
            	system("pause");
            	salir = 2;
            	return n;
			}
			
            fflush(stdin);
            while(cod==-1){
                printf("\nAsigne un codigo:  ");
                scanf("%i",&cod);
                for(i=0;i<=n;i++){
                    if(participante[i].codigo==cod){
                        printf("\nEse codigo ya ha sido utilizado\n");
                        cod=-1;
                    }
                }
            }
            participante[n].codigo=cod;
            fflush(stdin);
            printf("\nEscriba el nombre:  ");
            scanf("%[^\n]",&participante[n].nombre);
            fflush(stdin);
            printf("\nEscriba la edad:  ");
            scanf("%i",&participante[n].edad);
            fflush(stdin);
            s=3;
            while(s>2){
                printf("\nElija el sexo:\n1.Femenino\n2.Masculino\n");
                scanf("%i",&s);
                if(s<=2){
                    participante[n].sexo=s;
                }else{
                    printf("\nElija una opcion valida\n");
                }
            }
            fflush(stdin);
            printf("\nEscriba la nacionalidad:  ");
            scanf("%[^\n]",&participante[n].nacionalidad);
            fflush(stdin);
            printf("\nCantidad de las carreras que ha realizado en el pasado:  ");
            scanf("%i",&participante[n].carreras);
            fflush(stdin);
            participante[n].categoria=0;
            
            participante[n].indice=n;
            cod=-1;
            
			n++;
            
            if (n==maximo_ingresos){
            	printf("\nHa alcanzado el maximo de participantes posibles de registrar (%i)\n",maximo_ingresos); //pedir nuevo participante
            	system("pause");
            	salir = 2;
            	return n;
			}
			else{
				printf("\nDesea agregar a otro participante?\n1.Si\n2.Regresar al menu principal\n"); //pedir nuevo participante
	            scanf("%i",&salir);
	            if(salir>=2){
	                return n;  
	            }
			}
            
        }
            
    }while(opcion<2);
}

//registrar a los participantes
int registroCarrera(int n){
    int cod_reg, reg=-1;
    if(n>0){ //comprobar si hay participantes
        do{
            printf("\nElija una categoria:\n1.Carrera de velocidad\n2.Carrera de resistencia\n3.Regresar al menu principal\n");
            scanf("%i",&opcion);
            participantes este;
            
            switch (opcion){
                case 1:
                    printf("\nEscriba el codigo del participante que desea agregar a la carrera de velocidad:\n");
                    scanf("%i",&cod_reg);
                	este = encontrar_participante_x_cod(cod_reg,n);
                	if(este.codigo>0){
                		if(este.categoria==0){//si no esta registrado
                            printf("\nNombre: %s\n",este.nombre);
                            printf("Edad: %i\n",este.edad);
                            printf("Carreras realizadas: %i\n",este.carreras);
                            printf("\nDesea registrar este participante en la carrera?\n1.Si\n2.Regresar\n");
                            scanf("%i",&reg);
                            if(reg==1){
                                este.categoria=1;
                                participante[este.indice] = este;
                                printf("\nParticipante registrado\n");
                            }
                        }else{//si esta registrado
                            printf("\nEl participante ya esta registrado a una carrera. Desea eliminar su registro?\n1.Si\n2.Regresar\n");
                            scanf("%i",&reg);
                            if(reg==1){
                                este.categoria=0;
                                participante[este.indice] = este;
                                printf("\nSe ha eliminado el registro del participante\n");
                            }
                        }
					}
                    else{
                        printf("\nParticipante no encontrado\n");
                    }
                	break;
                case 2:
                    printf("\nEscriba el codigo del participante que desea agregar a la carrera de resistencia:\n");
                    scanf("%i",&cod_reg);
                    
                	este = encontrar_participante_x_cod(cod_reg,n);
                	if(este.codigo>0){
                		if(este.categoria==0){//si no esta registrado
                            printf("\nNombre: %s\n",este.nombre);
                            printf("Edad: %i\n",este.edad);
                            printf("Carreras realizadas: %i\n",este.carreras);
                            printf("\nDesea registrar este participante en la carrera?\n1.Si\n2.Regresar\n");
                            scanf("%i",&reg);
                            if(reg==1){
                                este.categoria=2;
                                participante[este.indice] = este;
                                printf("\nParticipante registrado\n");
                            }
                        }else{//si esta registrado
                            printf("\nEl participante ya esta registrado a una carrera. Desea eliminar su registro?\n1.Si\n2.Regresar\n");
                            scanf("%i",&reg);
                            if(reg==1){
                                este.categoria=0;
                                participante[este.indice] = este;
                                printf("\nSe ha eliminado el registro del participante\n");
                            }
                        }
					}
                    else{
                        printf("\nParticipante no encontrado\n");
                    }
                	break;
                break;
                case 3:
                    printf("\n...Regresando...\n");
                    return n;
                break;
                default:
                    printf("\nElija una opcion valida\n");
                break;
            }
        }while(opcion<3);
    }else{
        printf("\nNo hay participantes dados de alta\n\n");
    }
    system("pause");
}

//mostrar categorias
int mostrarRegistros(int n){
    int registrados;
    if(n>0){ //comprobar si hay participantes
    	for(i=0;i<n;i++){
    		if(participante[i].categoria!=0){
                registrados++;
            }
		}
    
        if(registrados>0){  //repasar categorias
        	int vuelta;
            printf("\nElija una opcion:\n1.Mostrar participantes en categoria de velocidad\n2.Mostrar participantes en categoria de resistencia\n3.Regresar\n");
            scanf("%i",&opcion);
            switch(opcion){
                case 1:
                    printf("\nLos participantes de carrera de velocidad son los siguientes:\n");
                    vuelta = 0 ;
					for(i=0;i<n;i++){
                        if(participante[i].categoria==1){
                        	vuelta ++;
                            printf("\nParticipante #%i:\n",(vuelta));
                            printf("\nNombre: %s\n",participante[i].nombre);
                            printf("Edad: %i\n",participante[i].edad);
                            if(participante[i].edad<20){
                                printf("Registrado en carrera de 5km\n");
                            }else if(participante[i].edad<30){
                                printf("Registrado en carrera de 10km\n");
                            }else{
                                printf("Registrado en carrera de 7km\n");
                            }
                            printf("Carreras realizadas: %i\n\n",participante[i].carreras);
                        }
                    }
                    if(vuelta==0){
                    	 printf("No hay participantes registrados en la carrera de velocidad\n\n");
					}
                	break;
                case 2:
                    printf("\nLos participantes de carrera de resistencia son los siguientes:\n");
                    vuelta = 0 ;
                    for(i=0;i<n;i++){
                        if(participante[i].categoria==2){
                        	vuelta ++;
                            printf("\nParticipante #%i:\n",(vuelta));
                            printf("\nNombre: %s\n",participante[i].nombre);
                            printf("Edad: %i\n",participante[i].edad);
                            if(participante[i].edad<20){
                                printf("Registrado en carrera de 5km\n");
                            }else if(participante[i].edad<30){
                                printf("Registrado en carrera de 10km\n");
                            }else{
                                printf("Registrado en carrera de 7km\n");
                            }
                            printf("Carreras realizadas: %i\n\n",participante[i].carreras);
                        }
                    }
                    if(vuelta==0){
                    	 printf("No hay participantes registrados en la carrera de resistencia\n\n");
					}
                	break;
                case 3:
                    printf("\n...Regresando...\n");
                break;
            }
        }else{
            printf("\nNo hay participantes registrados en ninguna carrera\n...Regresando...\n\n");
        }
    }else{
        printf("\nNo hay participantes dados de alta\n\n");
    }
    system("pause");
    return n;
}

int mostrarParticipantes(int n){
    if(n>0){ //comprobar si hay participantes
        printf("\nLa lista de todos los participantes es la siguiente:\n");
        for(i=0;i<n;i++){
        	printf("\nCodigo: %i\n",participante[i].codigo);
            printf("\nNombre: %s\n",participante[i].nombre);
            printf("Edad: %i\n",participante[i].edad);
            if(participante[i].sexo==1){
                printf("Sexo: Femenino\n");
            }else{
                printf("Sexo: Masculino\n");
            }
            printf("Nacionalidad: %s\n",participante[i].nacionalidad);
            if(participante[i].carreras<4){
                printf("Experiencia: Novicio\n");
            }else if(participante[i].carreras>=4 && participante[i].carreras<8){
                printf("Experiencia: Profesional\n");
            }else if(participante[i].carreras>=8){
                printf("Experiencia: Corredor olimpico\n");
            }
            if(participante[i].categoria==1){
                printf("Categoria: Velocidad\n");
            }else if(participante[i].categoria==2){
                printf("Categoria: Resistencia\n");
            }else{
                printf("Categoria: Sin registro\n");
            }
            
        }
    }else{
        printf("\nNo hay participantes dados de alta\n\n");
    }
    system("pause");
    return n;
}

participantes encontrar_participante_x_cod(int cod, int max_participantes){
	int encontrado = -1;
	for(i=0;i<max_participantes;i++){
		if(participante[i].codigo==cod){
			encontrado = i;
		}
	}
	if(encontrado>=0){
		return participante[encontrado];
	}
	else{
		participantes nulo;
		nulo.codigo=-1;
		return nulo;
	}
}

