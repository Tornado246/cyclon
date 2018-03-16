Proceso serie3
	Definir opcion Como Entero;
	Definir empresaName,empresaAddress, empresaRubro Como Caracter;
	Definir salir Como Caracter;
	empresaName = "";
	empresaAddress = "";
	empresaRubro = "";
	definir ETrab,Ctrab,tJoven,tMaduro,tMayor,edadMin,edadMax Como Entero;
	Definir continuar como logico;
	edadMin = 18; 
	edadMax = 65;
	continuar = Verdadero;
	Repetir
		Escribir("Elige la opcion deseada");
		Escribir("   1. Captura datos de la empresa");
		Escribir("   2. Imprimir datos de la empresa");
		Escribir("   3. Captura las edades de los empleados");
		Escribir("   4. Salir");
		Leer opcion;
		Si opcion>4 || opcion<1 Entonces
			Escribir("Opción ingresada no es valida\n");
		Sino
			Segun opcion Hacer
				1:
					//obtener la información definida para la empresa
					Escribir("Ingresa nombre de la empresa");
					Leer empresaName;
					Escribir("Ingresa direccion de la empresa");
					Leer empresaAddress;
					Escribir("Ingresa rubro de la empresa");
					Leer empresaRubro;
				2:
					//imprimir la información definida para la empresa
					Escribir "Nombre de la Empresa       : ",empresaName;
					Escribir "Direccion de la Empresa    : ",empresaAddress;
					Escribir "Rubro de la Empresa        : ",empresaRubro;
				3:
					Ctrab = 0;
					tJoven = 0;
					tMaduro = 0;
					tMayor = 0;
					Repetir
						Repetir 
							Escribir "Ingrese la edad del trabajador ",Ctrab+1," (Para detener ingrese 0)";
							Leer ETrab;
							Si ((ETrab>edadMax O ETrab<edadMin) Y ETrab <> 0)	 Entonces
								Escribir "Edad ingresada no corresponde, el rango valido es entre ",edadMin," y ",edadMax," años";
							FinSi
						Hasta Que no ((ETrab>edadMax O ETrab<edadMin) Y ETrab <> 0)	
						Si ETrab!=0 Entonces
							Si ETrab<22 Entonces
								tJoven = tJoven + 1;
							Sino
								Si ETrab<=50 Entonces
									tMaduro = tMaduro + 1;
								Sino
									tMayor = tMayor + 1;
								FinSi
							FinSi
							Ctrab = Ctrab + 1;
						FinSi
					Hasta Que no (ETrab!=0)

					
					Escribir "Cantidad de trabajadores Menores (entre ",edadMin," y 21 añcos) es: ",tJoven;
					Escribir "Cantidad de trabajadores Maduros (entre 22 y 50 años) es: ",tMaduro;
					Escribir "Cantidad de trabajadores Mayores (entre 51 y ",edadMax," años) es: ", tMayor;
				De Otro Modo:
					Escribir "Esta seguro que desea salir? (s para Confirmar, otra para Cancelar)";
					Leer salir;
					Si salir == "s" Entonces
						continuar = Falso;
						Escribir "Hasta luego";
					FinSi
			FinSegun
		FinSi
		Escribir "";
		Escribir "	Presione una tecla para continuar...";
		Esperar Tecla;
		Borrar Pantalla;
	Hasta Que no continuar 
	
FinProceso
