Proceso positivos50
	Definir nPosit,contar,maxContador,inicial Como Entero;
	Dimension  nPosit[50];
	contar<-0;
	maxContador<-50;
	inicial<-1;
	Mientras contar < maxContador Hacer
		si inicial mod 2 = 0 Entonces
			nPosit[contar]<-inicial;
			contar<-contar+1;
		FinSi
		inicial<-inicial+1;
	FinMientras
	
	Para contar<-maxContador-1 Hasta 0 Con Paso -1 Hacer
		Escribir nPosit[contar];
	FinPara
FinProceso
