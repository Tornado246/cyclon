Proceso factorial
	Definir valor,base,contador como entero;
	valor <- 7;
	base <- 1;
	Escribir "Calculando el factorial de ",valor;
	Para contador<-1 Hasta valor Con Paso 1 Hacer
		base <- base * contador;
	FinPara
	Escribir "(",valor,"!) = ",base;
FinProceso
