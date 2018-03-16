Proceso serie4
	Definir veces,i,x,aux Como Entero;
	Definir opcion Como Entero;
	Definir salir Como Caracter;
	
	Escribir("Ingrese la cantidad valores enteros va a capturar");
	Leer veces;
	
	Definir arreglo,ordenado como Entero;
	Dimension arreglo[veces],ordenado[veces];
	
	Definir continuar como logico;
	continuar <- Verdadero;
	Repetir
		Escribir("Elige la opcion deseada");
		Escribir("   1. Capturar valores");
		Escribir("   2. Ordenar valores");
		Escribir("   3. imprimir valores originales");
		Escribir("   4. imprimir valores ordenados");
		Escribir("   5. Salir");
		Leer opcion;
		Si opcion>5 || opcion<1 Entonces
			Escribir("Opción ingresada no es valida\n");
		Sino
			Segun opcion Hacer
				1:
					//obtener los numeros
					Para i<-0 Hasta veces-1 Con Paso 1 Hacer
						Escribir "Ingresa Entero ",(i+1)," : ";
						Leer arreglo[i];
						//voy copiando en arreglo para ordenar luego
						ordenado[i] <- arreglo[i];
					FinPara
				2:
					//ordenar metodo burbuja (simple)
					Para i<-0 Hasta veces-2 Con Paso 1 Hacer
						Para x<-i+1 Hasta veces-1 Con Paso 1 Hacer
							Si ordenado[i]>ordenado[x] Entonces
								aux <- ordenado[i];
								ordenado[i] <- ordenado[x];
								ordenado[x] <- aux;
							FinSi
						FinPara
					FinPara
					
				    Escribir "Se ha ordenado correctamente el arreglo";
				3:
					//imprimir origina
					Para i<-0 Hasta veces-1 Con Paso 1 Hacer
						Escribir "Entero [",(i+1),"] : ",arreglo[i];
					FinPara
	
				4:
					//imprimir ordenado
					Para i<-0 Hasta veces-1 Con Paso 1 Hacer
						Escribir "Entero [",(i+1),"] : ",ordenado[i];
					FinPara
				De Otro Modo:
					Escribir "Esta seguro que desea salir? (s para Confirmar, otra para Cancelar)";
					Leer salir;
					Si salir == "s" Entonces
						continuar = Falso;
						Escribir "Hasta luego";
					FinSi
			FinSegun
		FinSi
		Escribir "";
		Escribir "	Presione una tecla para continuar...";
		Esperar Tecla;
		Borrar Pantalla;
	Hasta Que no continuar 
	
FinProceso
