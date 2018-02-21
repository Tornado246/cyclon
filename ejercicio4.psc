Proceso ejercicio4
	definir calificacion Como entero;
	definir puedaSeguir Como Logico;
	puedaSeguir <- Falso;
	Repetir
		Escribir "Ingrese la calificacion";
		Leer calificacion;
		si calificacion>100 O calificacion<0 Entonces
			Escribir "    El rango de calificaciones es desde 0 a 100";
		Sino
			puedaSeguir<-Verdadero;
		FinSi
	Hasta Que puedaSeguir

	escribir "Su resultado es :";
	si calificacion>=90 Entonces
		Escribir "   Excelente";
	Sino
		si calificacion >= 80 Entonces
			Escribir "   Muy Bien";
		Sino
			si calificacion >=70 Entonces
				Escribir "   Bien";
			Sino
				si calificacion >=60 Entonces
					Escribir "   Regular";
				Sino
					Escribir "   Malo";
				FinSi
			FinSi
		FinSi
	FinSi
	
FinProceso
