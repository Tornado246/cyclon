Proceso tabla_multiplicar
	definir base, cantidad,cont1,cont2 Como Entero;
	escribir "Programa para imprimir una tabla de multiplicar";
	escribir "	Ingrese la base de la tabla que desea mostrar";
	leer base;
	Escribir "	Ingrese hasta donde quiere imprimir la tabla";
	leer cantidad;
	Para cont1<-1 Hasta cantidad Con Paso 1 Hacer
		Escribir "		",base," x ",cont1," = ",(base*cont1);
	FinPara
	
FinProceso
