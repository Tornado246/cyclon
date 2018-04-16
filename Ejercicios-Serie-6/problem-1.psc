Funcion calcular_area_cuadrado(lado)
	Definir  area como real;
	Escribir "Calculando el area de un cuadrado";
	area <- lado*lado;
	Escribir "El area del cuadrado es :",area;
FinFuncion

Funcion calcular_area_trapecio(baseS, baseI, altura)
	Definir area Como Real;
	Escribir "Calculando el area de un Trapecio";
	area <- ((baseS+baseI)*altura/2);
	Escribir "El area del Trapecio es : ",area;
FinFuncion

Funcion calcular_area_esfera(radio)
	Definir area como real;
	Escribir "Calculando el area de una Esfera";
	area <- radio*radio*PI*4;
	Escribir "El area de la Esfera es : ",area;
FinFuncion

Funcion calcular_perimetro_rectangulo(largo, ancho)
	Definir perimetro como real;
	Escribir "Calculando el perimetro de un Rectangulo";
	perimetro <- (largo+ancho)*2;
	Escribir "El perimetro del Rectangulo es : ",perimetro;
FinFuncion

Funcion calcular_perimetro_triangulo(lado1,lado2,lado3)
	Definir perimetro Como Real;
	Escribir("Calculando el perimetro de un Triangulo");
	perimetro <- lado1+lado2+lado3;
	Escribir "El perimetro del Triangulo es : ",perimetro;
FinFuncion

Funcion calcular_perimetro_circulo(radio)
	Definir perimetro Como Real;
	Escribir "Calculando el perimetro de un Circulo";
	
	perimetro <- radio*PI*2;
	Escribir "El perimetro del Circulo es : ",perimetro;
FinFuncion

Funcion volver <- menu_area(cuadrado_lado, trap_baseS, trap_baseI,trap_altura,esfe_radio)
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
					calcular_area_cuadrado(cuadrado_lado);
				2:
					calcular_area_trapecio(trap_baseS, trap_baseI,trap_altura);
				3:
					calcular_area_esfera(esfe_radio);
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

Funcion volver <- menu_perimetro(rect_largo,rect_ancho,tria_lado1,tria_lado2,tria_lado3,circ_radio)
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
					calcular_perimetro_rectangulo(rect_largo,rect_ancho);
				2:
					calcular_perimetro_triangulo(tria_lado1,tria_lado2,tria_lado3);
				3:
					calcular_perimetro_circulo(circ_radio);
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
	
	Definir cuadrado_lado, trap_baseS, trap_baseI,trap_altura,esfe_radio,circ_radio,rect_largo,rect_ancho Como Real;
	definir tria_lado1,tria_lado2,tria_lado3 Como Real;
	
	Escribir "Ingrese lado del cuadrado";	
	Leer cuadrado_lado;
	Escribir "Ingrese base superior del trapecio";	
	Leer trap_baseS;
	Escribir "Ingrese base inferior del trapecio";	
	Leer trap_baseI;
	Escribir "Ingrese altura del trapecio";
	Leer trap_altura;
	Escribir "Ingrese radio de la esfera";	
	Leer esfe_radio;
	Escribir "Ingrese radio del circulo";	
	Leer circ_radio;
	Escribir "Ingrese largo de rectangulo";	
	Leer rect_largo;
	Escribir "Ingrese ancho de rectangulo";	
	Leer rect_ancho;
	Escribir "Ingrese lado 1 del triangulo";	
	Leer tria_lado1;
	Escribir "Ingrese lado 2 del triangulo";	
	Leer tria_lado2;
	Escribir "Ingrese lado 3 del triangulo";	
	Leer tria_lado3;
	
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
					continuar <- menu_area(cuadrado_lado, trap_baseS, trap_baseI,trap_altura,esfe_radio);
				2:
					continuar <- menu_perimetro(rect_largo,rect_ancho,tria_lado1,tria_lado2,tria_lado3,circ_radio);
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
