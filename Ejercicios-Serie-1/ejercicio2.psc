algoritmo ejercicio2
	definir inscripcion, mensualidad, monto como real;
	definir esTrabajador como cadena;
	
	escribir "indique si es trabajador (S/N)";
	leer esTrabajador;
	
	inscripcion <- 100000.00;
	mensualidad <- 150000.00;
	
	monto <- inscripcion + mensualidad;
	si (esTrabajador = "S" | esTrabajador = "s")  entonces 
		monto <- monto *0.5;
	finsi
	escribir "El monto a pagar es : ", monto;
	
finalgoritmo
