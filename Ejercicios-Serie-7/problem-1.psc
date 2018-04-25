
Funcion inventario_reporte(codigo,nombre,n_anaquel,precio_unit)
	Borrar Pantalla;
	Escribir "Reporte de Inventario";
	
	Escribir "  Codigo Producto : ",codigo;
	Escribir "  Nombre Producto : ",nombre;
	Escribir "  Numero Anaquel  : ",n_anaquel;
	Escribir "  Precio Unitario : ",precio_unit;
FinFuncion

Funcion cantidad <- venta_menudeo()
	Borrar Pantalla;
	Definir cantidad Como Entero;
	
	Escribir "Venta Menudeo";
	Escribir "  Ingrese la cantidad a comprar :";
	leer cantidad;
	Si (cantidad<=0) Entonces
		Escribir "Cantidad ingresada no es valida (debe ser mayor que 0)";
		cantidad <- 0;
	Sino
		Si (cantidad<=10) Entonces
			Escribir "Se ha registrado la venta menudeo correctamente";
		Sino
			Escribir "Cantidad ingresada excede las condiciones para venta menudeo";
			cantidad <- 0;
		FinSi
	FinSi
FinFuncion

Funcion cantidad <- venta_mayoreo()
	Borrar Pantalla;
	Definir cantidad Como Entero;
	
	Escribir "Venta Mayoreo";
	Escribir "  Ingrese la cantidad a comprar :";
	leer cantidad;
	Si (cantidad<=0) Entonces
		Escribir "Cantidad ingresada no es valida (debe ser mayor que 0)";
		cantidad <- 0;
	Sino
		Si (cantidad<=10) Entonces
			Escribir "Cantidad ingresada excede las condiciones para venta mayoreo";
			cantidad <- 0;			
		Sino
			Escribir "Se ha registrado la venta mayoreo correctamente";
		FinSi
	FinSi
FinFuncion

Funcion venta_imprimir(codigo,nombre,n_anaquel,precio_unit, cantidad)
	Borrar Pantalla;
	Definir pIVA,subtotal,total Como Real;
	
	pIVA <- 0.16;
	total <- precio_unit*cantidad;
	subtotal <- total/(1+pIVA);
	
	Escribir "Impresion de Venta";
	Escribir "  Codigo Producto  : ",codigo;
	Escribir "  Nombre Producto  : ",nombre;
	Escribir "  Cantidad Vendida : ",cantidad;
	Escribir "  Precio Unitario  : ",precio_unit;
	Escribir "  Subtotal         : ",(subtotal);
	Escribir "  IVA              : ",(total-subtotal);
	Escribir "  Total            : ",(total);
	
FinFuncion

Funcion cliente_alta(cliente_codigo Por Referencia,cliente_nombre Por Referencia,cliente_telefono Por Referencia,cliente_ciudad Por Referencia)
	Borrar Pantalla;
	Escribir "Alta de Cliente:";
	Escribir "  Codigo del cliente  :";
	Leer cliente_codigo;
	Escribir "  Nombre del cliente  :";
	Leer cliente_nombre;
	Escribir "  Telefono del cliente  :";
	Leer cliente_telefono;
	Escribir "  Ciudad del cliente  :";
	Leer cliente_ciudad;
	Escribir "Alta de Cliente ingresada correctamente";
FinFuncion

funcion cliente_imprimir(cliente_codigo Por Referencia,cliente_nombre Por Referencia,cliente_telefono Por Referencia,cliente_ciudad Por Referencia)
	Borrar Pantalla;
	Escribir "Impresion Cliente:";
	Escribir "  Codigo del cliente   :",cliente_codigo;
	Escribir "  Nombre del cliente   :",cliente_nombre;
	Escribir "  Telefono del cliente :",cliente_telefono;
	Escribir "  Ciudad del cliente   :",cliente_ciudad;
FinFuncion



Funcion volver <- modulo_inventario(codigo,nombre,n_anaquel,precio_unit)
	Borrar Pantalla;
	Definir opcion Como Entero;
	Definir continuar, volver Como Logico;
	continuar <- Verdadero;
	volver <- Verdadero;
	Repetir
		Escribir "Modulo de Inventario:";
		Escribir "   1. Reporte";
		Escribir "   2. Salir";
		leer opcion;
		
		si (opcion>2 o opcion<1) entonces
			Escribir("Opcion ingresada no es valida");
		Sino
			Segun opcion Hacer
				1:
					inventario_reporte(codigo,nombre,n_anaquel,precio_unit);
				De Otro Modo: //opcion 2
					continuar <- Falso;
			FinSegun
		FinSi
		
		si (continuar) entonces
			esperar tecla;
			Limpiar Pantalla;
		FinSi
	Hasta Que no continuar
FinFuncion

Funcion volver <- modulo_venta(codigo,nombre,n_anaquel,precio_unit)
	Borrar Pantalla;
	Definir opcion, cantidad_venta Como Entero;
	Definir continuar, volver Como Logico;
	continuar <- Verdadero;
	volver <- Verdadero;
	cantidad_venta <- 0;
	Repetir
		Escribir "Modulo de Venta:";
		Escribir "   1. Venta Menudeo";
		Escribir "   2. Venta Mayoreo";
		Escribir "   3. Imprimir Venta";
		Escribir "   4. Salir";
		leer opcion;
		
		si (opcion>4 o opcion<1) entonces
			Escribir("Opcion ingresada no es valida");
		Sino
			Segun opcion Hacer
				1:
					cantidad_venta <- venta_menudeo();
				2:
					cantidad_venta <- venta_mayoreo();
				3:
					Si(cantidad_venta>0) Entonces
						venta_imprimir(codigo,nombre,n_anaquel,precio_unit,cantidad_venta);
					Sino
						Escribir "No hay una venta valida registrada";
					FinSi
				De Otro Modo: //opcion 4
					continuar <- Falso;
			FinSegun
		FinSi
		
		si (continuar) entonces
			esperar tecla;
			Limpiar Pantalla;
		FinSi
	Hasta Que no continuar
FinFuncion

Funcion volver <- modulo_cliente()
	Borrar Pantalla;
	Definir opcion Como Entero;
	Definir continuar, volver Como Logico;
	Definir cliente_codigo,cliente_nombre,cliente_telefono,cliente_ciudad Como Caracter;
	
	continuar <- Verdadero;
	volver <- Verdadero;
	Repetir
		Escribir "Modulo de Cliente:";
		Escribir "   1. Alta Cliente";
		Escribir "   2. Imprimir Cliente";
		Escribir "   3. Salir";
		leer opcion;
		
		si (opcion>3 o opcion<1) entonces
			Escribir("Opcion ingresada no es valida");
		Sino
			Segun opcion Hacer
				1:
					cliente_alta(cliente_codigo,cliente_nombre,cliente_telefono,cliente_ciudad);
				2:
					cliente_imprimir(cliente_codigo,cliente_nombre,cliente_telefono,cliente_ciudad);
				De Otro Modo: //opcion 3
					continuar <- Falso;
			FinSegun
		FinSi
		
		si (continuar) entonces
			esperar tecla;
			Limpiar Pantalla;
		FinSi
	Hasta Que no continuar
FinFuncion

Proceso serie7
	Definir opcion Como Entero;
	Definir salir Como Caracter;
	Definir continuar como logico;
	continuar <- Verdadero;
	
	Definir precio_unit Como Real;
	Definir n_anaquel Como Entero;
	Definir codigo, nombre Como Caracter;
	
	Escribir "Ingrese Codigo del producto";	
	Leer codigo;
	Escribir "Nombre del Producto";	
	Leer nombre;
	Escribir "Numero de Anaquel";	
	Leer n_anaquel;
	Escribir "Precio Unitario (con IVA)";
	Leer precio_unit;
	
	Repetir
		Borrar Pantalla;
		Escribir("La Tiendita:");
		Escribir("   1. Modulo Inventario");
		Escribir("   2. Modulo Venta");
		Escribir("   3. Modulo Cliente");
		Escribir("   4. Salir");
		Leer opcion;
		Si opcion>4 || opcion<1 Entonces
			Escribir("Opción ingresada no es valida");
		Sino
			Segun opcion Hacer
				1:
					continuar <- modulo_inventario(codigo,nombre,n_anaquel,precio_unit);
				2:
					continuar <- modulo_venta(codigo,nombre,n_anaquel,precio_unit);
				3:
					continuar <- modulo_cliente();
				De Otro Modo:	//opcion 4
					Escribir "Esta seguro que desea salir? (s para Confirmar, otra para Cancelar)";
					Leer salir;
					Si salir == "s" Entonces
						continuar <- Falso;
						Escribir "Hasta luego";
					FinSi
			FinSegun
		FinSi
		Escribir "";
		Escribir "	Presione una tecla para continuar...";
		Esperar Tecla;
		
	Hasta Que no continuar 
FinProceso
