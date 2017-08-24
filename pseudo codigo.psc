Proceso pago_sueldo
	Definir sueldo_semanal Como Real;
	Definir sueldo_base_semanal Como Real;
	Definir impuesto_IMSS Como Real;
	Definir impuesto_renta Como Real;
	Definir sueldo_extra Como Real;
	Definir sueldo_diario Como Real;
	Definir hora_extra Como Entero;
	Definir nombre_empleado Como Caracter;
	Definir cod_empleado Como Entero;
	Escribir 'Ingrese el codigo del Empleado';
	Leer cod_empleado;
	Escribir 'Ingrese el nombre del Empleado';
	Leer nombre_empleado;
	Escribir 'Ingrese las horas Extra';
	Leer hora_extra;
	sueldo_diario <- 125.50*8;
	sueldo_base_semanal <- sueldo_diario*7;
	sueldo_extra <- 125.50*hora_extra*2;
	impuesto_renta <- sueldo_base_semanal*0.003;
	impuesto_IMSS <- sueldo_base_semanal*0.047;
	sueldo_semanal <- sueldo_base_semanal+sueldo_extra-impuesto_renta-impuesto_IMSS;
	Escribir 'El sueldo del empleado ',cod_empleado,' ',nombre_empleado,' es: ',sueldo_semanal;
FinProceso

