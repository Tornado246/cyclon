algoritmo ejercicio1
	definir alNombre,alCodigo como texto;
	definir nota, promedio, sumatoria como real;
	definir contador como entero;
	
	escribir "Indique el codigo del alumno";
	leer alCodigo;
	escribir "Indique el nombre del alumno ";
	leer alNombre;
	contador <- 0;
	sumatoria <-0;
	mientras contador <4 hacer
		escribir "Ingrese nota", (contador+1);
		leer nota;
		sumatoria <- sumatoria + nota;
		contador <- contador +1;
	finmientras
	promedio <- sumatoria/contador;
	si promedio>= 95 entonces
		promedio <- 100;
	finsi
	Borrar Pantalla;
	escribir "Detalle Final Alumno";
	escribir "   Codigo : ", alCodigo;
	escribir "   Nombre : ", alNombre;
	escribir "   Promedio : ", promedio;
finalgoritmo