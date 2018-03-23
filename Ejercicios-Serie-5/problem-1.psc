Funcion calcular_area_cuadrado
	Definir  lado,area como real;
	Escribir "Calculando el area de un cuadrado";
	
	Escribir "	Ingrese Lado";
	leer lado;
	
	area <- lado*lado;
	Escribir "El area del cuadrado es :",area;
FinFuncion

Funcion calcular_area_trapecio
	Definir baseS, baseI, altura ,area como real;
	Escribir "Calculando el area de un Trapecio";
	
	Escribir "   Ingrese base superior";	
	leer baseS;
	Escribir("   Ingrese base inferior");	
	leer baseI;
	Escribir("   Ingrese altura");	
	leer altura;
	
	area <- ((baseS+baseI)*altura/2);
	Escribir "El area del Trapecio es : ",area;
FinFuncion

Funcion calcular_area_esfera
	Definir radio, Npi ,area como real;
	Escribir "Calculando el area de una Esfera";
	Npi <- 3.1416;
	Escribir "   Ingrese radio";	
	leer radio;
	
	area <- radio*radio*Npi*4;
	Escribir "El area de la Esfera es : ",area;
FinFuncion

Funcion calcular_perimetro_rectangulo
	Definir largo, ancho ,perimetro como real;
	Escribir "Calculando el perimetro de un Rectangulo";
	
	Escribir("   Ingrese largo");	
	Leer largo;
	Escribir("   Ingrese ancho");	
	Leer ancho;
	
	perimetro <- (largo+ancho)*2;
	Escribir "El perimetro del Rectangulo es : ",perimetro;
FinFuncion

Funcion calcular_perimetro_triangulo
	Definir i Como Entero;
	Definir lado ,perimetro Como Real;
	Dimension lado[3];
	Escribir("Calculando el perimetro de un Triangulo");
	
	Para i<-0 hasta 2 con paso 1 hacer
		Escribir "   Ingrese lado ",(i+1);	
		Leer lado[i];	
	FinPara
	perimetro <- lado[0]+lado[1]+lado[2];
	Escribir "El perimetro del Triangulo es : ",perimetro;
FinFuncion

Funcion calcular_perimetro_circulo
	Definir radio, Npi ,perimetro Como Real;
	Escribir "Calculando el perimetro de un Circulo";
	
	Npi <- 3.1416;
	Escribir "   Ingrese radio";	
	Leer radio;
	
	perimetro <- radio*Npi*2;
	Escribir "El perimetro del Circulo es : ",perimetro;
FinFuncion

Funcion volver <- menu_area()
	Borrar Pantalla;
	Definir opcion Como Entero;
	Definir continuar, volver Como Logico;
	continuar <- Verdadero;
	volver <- Verdadero;
	Repetir
		Escribir "Calcular area de:";
		Escribir "   1. Cuadrado";
		Escribir "   2. Trapecio";
		Escribir "   3. Esfera";
		Escribir "   4. Salir";
		leer opcion;
		
		si (opcion>4 o opcion<1) entonces
			Escribir("Opcion ingresada no es valida");
		Sino
			Segun opcion Hacer
				1:
					calcular_area_cuadrado();
				2:
					calcular_area_trapecio();
				3:
					calcular_area_esfera();
				De Otro Modo: //opcion 4
					continuar <- Falso;
					definir salir Como Caracter;
					Escribir "Esta seguro que desea salir del programa?";
					Escribir "(s para Confirmar, otra tecla para volver al menu anterior)";
					leer salir;
					
					Si salir == "s" Entonces
						volver <- Falso;
						Escribir "Hasta luego";
					FinSi
			FinSegun
		FinSi
		
		si (continuar) entonces
			esperar tecla;
			Limpiar Pantalla;
		FinSi
	Hasta Que no continuar
FinFuncion

Funcion volver <- menu_perimetro()
	Borrar Pantalla;
	Definir opcion Como Entero;
	Definir continuar, volver Como Logico;
	continuar <- Verdadero;
	volver <- Verdadero;
	Repetir
		Escribir "Calcular perimetro de:";
		Escribir "   1. Rectangulo";
		Escribir "   2. Triagulo";
		Escribir "   3. Circulo";
		Escribir "   4. Salir";
		leer opcion;
		
		si (opcion>4 o opcion<1) entonces
			Escribir("Opcion ingresada no es valida");
		Sino
			Segun opcion Hacer
				1:
					calcular_perimetro_rectangulo();
				2:
					calcular_perimetro_triangulo();
				3:
					calcular_perimetro_circulo();
				De Otro Modo: //opcion 4
					continuar <- Falso;
					definir salir Como Caracter;
					Escribir "Esta seguro que desea salir del programa?";
					Escribir "(s para Confirmar, otra tecla para volver al menu anterior)";
					leer salir;
					
					Si salir == "s" Entonces
						volver <- Falso;
						Escribir "Hasta luego";
					FinSi
			FinSegun
		FinSi
		
		si (continuar) entonces
			esperar tecla;
			Limpiar Pantalla;
		FinSi
	Hasta Que no continuar
FinFuncion

Proceso serie5
	Definir opcion Como Entero;
	Definir salir Como Caracter;
	Definir continuar como logico;
	
	continuar <- Verdadero;
	Repetir
		Escribir("Seleccione la informacion que desea calcular:");
		Escribir("   1. Areas");
		Escribir("   2. Perimetros");
		Escribir("   3. Salir");
		Leer opcion;
		Si opcion>3 || opcion<1 Entonces
			Escribir("Opción ingresada no es valida");
		Sino
			Segun opcion Hacer
				1:
					continuar <- menu_area();
				2:
					continuar <- menu_perimetro();
				De Otro Modo:	//opcion 3
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
