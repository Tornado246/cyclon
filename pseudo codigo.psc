Proceso pago_sueldo
	//1. Declaro Variables
		Definir sueldo_semanal,sueldo_base_semanal,impuesto_IMSS,impuesto_renta,sueldo_extra,sueldo_diario Como Real;
		Definir hora_extra,cod_empleado Como Entero;
		Definir nombre_empleado Como Caracter;
	//2. pidos los datos necesario
		Escribir 'Ingrese el codigo del Empleado';
		Leer cod_empleado;
		Escribir 'Ingrese el nombre del Empleado';
		Leer nombre_empleado;
		Escribir 'Ingrese las horas Extra';
		Leer hora_extra;
	//3. establezco los calculos predefinidos-
		sueldo_diario <- 125.50*8;
		sueldo_base_semanal <- sueldo_diario*7;
		sueldo_extra <- 125.50*hora_extra*2;
		impuesto_renta <- sueldo_base_semanal*0.003;
		impuesto_IMSS <- sueldo_base_semanal*0.047;
	//4. calculo
		sueldo_semanal <- sueldo_base_semanal+sueldo_extra-impuesto_renta-impuesto_IMSS;
	//5. muestro el resultado en pantalla
		Escribir 'El sueldo del empleado ',cod_empleado,' ',nombre_empleado,' es: ',sueldo_semanal;
FinProceso

