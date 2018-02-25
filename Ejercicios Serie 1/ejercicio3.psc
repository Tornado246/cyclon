algoritmo ejercicio3
	definir opcion como numero;
	definir nPI como real;
	nPI<-3.1416;
	escribir "Elija una opcion de entre la lista de opciones";
	escribir "   1. Area de un triangulo";
	escribir "   2. Area de un rectangulo";
	escribir "   3. Area de un circulo";
	escribir "   4. Area de un cubo";
	escribir "   6. Area de una esfera";
	escribir "   7. Salir";
	leer opcion;
	
	segun opcion hacer
		1:
			definir base, altura como real;
			escribir "Ingrese la base y altura del triangulo";
			leer base;
			leer altura;
			escribir "El area del triangulo es ", (base*altura)/2;
		2:
			definir largo, alto como real;
			escribir "Ingrese el largo y alto del rectangulo";
			leer largo;
			leer alto;
			escribir "El area del rectangulo es ", (largo*alto);
		3:
			definir radio como real;
			Escribir "Ingrese el radio del circulo";
			Leer radio;
			Escribir "El area del circulo es ",(radio*radio*nPI);
		4:
			Definir lado como real;
			Escribir "Ingrese el lado del cubo";
			Leer lado;
			Escribir "El area del cubo es ",(cubo*cubo*cubo);
		6:
			Definir radio como real;
			Escribir "Ingrese el radio de la esfera";
			Leer radio;
			Escribir "El area de la esfera es ",(radio*radio*radio*(4/3)*nPI);
		7:
			Escribir "Usted ha salido exitosmente";
		De Otro Modo:
			Escribir "Opcion ingresada no es valida";
	finsegun 
finalgoritmo