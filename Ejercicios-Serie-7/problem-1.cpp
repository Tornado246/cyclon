#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char cliente_nombre[100], cliente_codigo[20], cliente_telefono[20], cliente_ciudad[50];

void inventario_reporte(char codigo[],char nombre[],int n_anaquel, float precio_unit){
	system("cls");
	printf("Reporte de Inventario\n\n");
	printf("\tCodigo Producto : %s\n",codigo);
	printf("\tNombre Producto : %s\n",nombre);
	printf("\tNumero Anaquel  : %d\n",n_anaquel);
	printf("\tPrecio Unitario : %.2f\n",precio_unit);
}

int venta_menudeo(){
	system("cls");
	int cantidad;
	printf("Venta Menudeo\n\n");
	printf("\tIngrese la cantidad por comprar : %d\n",cantidad);
	scanf("%d",&cantidad);
	if(cantidad<=0){
		printf("Cantidad ingresada no es valida (debe ser mayor que 0)\n");
		cantidad = 0;
	}
	else{
		if(cantidad<=10){
			printf("Se ha registrado la venta menudeo correctamente\n");
		}
		else{
			printf("Cantidad ingresada excede las condiciones para venta menudeo\n");
			cantidad = 0;
		}
	}
	return cantidad;
}
int venta_mayoreo(){
	system("cls");
	int cantidad;
	printf("Venta Mayoreo\n\n");
	printf("\tIngrese la cantidad por comprar : %d\n",cantidad);
	scanf("%d",&cantidad);
	if(cantidad<=0){
		printf("Cantidad ingresada no es valida (debe ser mayor que 0)\n");
		cantidad = 0;
	}
	else{
		if(cantidad<=10){
			printf("Cantidad ingresada no cumple las condiciones para venta mayoreo\n");
			cantidad = 0;
		}
		else{
			printf("Se ha registrado la venta mayoreo correctamente\n");
		}
	}
	return cantidad;
}
void venta_imprimir(char codigo[],char nombre[],int n_anaquel, float precio_unit,int cantidad){
	system("cls");
	float pIVA,subtotal,total;
	pIVA = 0.16;
	total = precio_unit*cantidad;
	subtotal = total/(1+pIVA);
	
	printf("Impresion de Venta\n\n");
	printf("\tCodigo Producto  : %s\n",codigo);
	printf("\tNombre Producto  : %s\n",nombre);
	printf("\tCantidad Vendida : %d\n",cantidad);
	printf("\tPrecio Unitario  : %.2f\n",precio_unit);
	printf("\tSubtotal         : %.2f\n",(subtotal));
	printf("\tIVA              : %.2f\n",(total-subtotal));
	printf("\tTotal            : %.2f\n",(total));
}

void cliente_alta(){
	system("cls");
	printf("Alta de Cliente:\n\n");
	printf("\tCodigo del cliente\n\t> ");	
	scanf("\t%s",&cliente_codigo);
	printf("\tNombre del cliente\n\t> ");	
	scanf("%s",&cliente_nombre);
	printf("\tTelefono del cliente\n\t> ");	
	scanf("%s",&cliente_telefono);
	printf("\tCiudad del cliente\n\t> ");	
	scanf("%s",&cliente_ciudad);
	
	printf("\n\n\tAlta de Cliente ingresada correctamente\n");
}
void cliente_imprimir(){
	system("cls");
	printf("Impresion Cliente\n\n");
	printf("\tCodigo del Cliente   : %s\n",cliente_codigo);
	printf("\tNombre del Cliente   : %s\n",cliente_nombre);
	printf("\tTelefono del Cliente : %s\n",cliente_telefono);
	printf("\tCiudad del Cliente   : %s\n",cliente_ciudad);
}

bool modulo_inventario(char codigo[],char nombre[],int n_anaquel, float precio_unit){
	system("cls");
	int opcion;
	bool continuar = true, volver = true;
	
	do{
		printf("Modulo de Inventario:\n\n");
		printf("\t1. Reporte\n");
		printf("\t2. Salir\n");
		scanf("%d",&opcion);
		
		if(opcion>2 || opcion<1){
			printf("Opcion ingresada no es valida\n");
		}
		else{
			switch(opcion){
				case 1:
					inventario_reporte(codigo,nombre,n_anaquel,precio_unit);
					break;
				default:	//opcion 2
					continuar = false;
					break;
			}
		}
		if(continuar){
			system("pause");
			system("cls");
		}
		
	}while(continuar);
	return volver;
}
bool modulo_venta(char codigo[],char nombre[],int n_anaquel, float precio_unit){
	system("cls");
	int opcion;
	bool continuar = true, volver = true;
	int cantidad_venta;
	cantidad_venta = 0;
	
	do{
		printf("Modulo de Venta:\n\n");
		printf("\t1. Venta Menudeo\n");
		printf("\t2. Venta Mayoreo\n");
		printf("\t3. Imprimir Venta\n");
		printf("\t4. Salir\n");
		scanf("%d",&opcion);
		
		if(opcion>4 || opcion<1){
			printf("Opcion ingresada no es valida\n");
		}
		else{
			switch(opcion){
				case 1:
					cantidad_venta = venta_menudeo();
					break;
				case 2:
					cantidad_venta = venta_mayoreo();
					break;
				case 3:
					if(cantidad_venta>0){
						venta_imprimir(codigo,nombre,n_anaquel,precio_unit,cantidad_venta);
					}
					else{
						printf("\n\tNo hay una venta valida registrada\n");
					}
					break;
				default:	//opcion 4
					continuar = false;
					break;
			}
		}
		if(continuar){
			system("pause");
			system("cls");
		}
		
	}while(continuar);
	return volver;
}
bool modulo_cliente(){
	system("cls");
	int opcion;
	bool continuar = true, volver = true;
	
	do{
		printf("Modulo de Cliente:\n\n");
		printf("\t1. Alta Cliente\n");
		printf("\t2. Imprimir Cliente\n");
		printf("\t3. Salir\n");
		scanf("%d",&opcion);
		
		if(opcion>3 || opcion<1){
			printf("Opcion ingresada no es valida\n");
		}
		else{
			switch(opcion){
				case 1:
					cliente_alta();
					break;
				case 2:
					cliente_imprimir();
					break;
				default:	//opcion 3
					continuar = false;
					break;
			}
		}
		if(continuar){
			system("pause");
			system("cls");
		}
		
	}while(continuar);
	return volver;
}

int main()
{
	int opcion;
	bool continuar = true;
	float precio_unit;
	int n_anaquel;
	char codigo[30], nombre[200];
	printf("\tIngrese Codigo del producto\n\t> ");	
	scanf("\t%s",&codigo);
	printf("\tNombre del Producto\n\t> ");	
	scanf("%s",&nombre);
	printf("\tNumero de Anaquel\n\t> ");	
	scanf("%d",&n_anaquel);
	printf("\tPrecio Unitario (con IVA)\n\t> ");
	scanf("%f",&precio_unit);
	
	do{
		system("cls");
		printf("La Tiendita:\n\n");
		printf("\t1. Modulo Inventario\n");
		printf("\t2. Modulo Venta\n");
		printf("\t3. Modulo Cliente\n");
		printf("\t4. Salir\n");
		scanf("%d",&opcion);
		
		if(opcion>4 || opcion<1){
			printf("Opcion ingresada no es valida\n");
		}
		else{
			switch(opcion){
				case 1:
					continuar = modulo_inventario(codigo,nombre,n_anaquel,precio_unit);
					break;
				case 2:
					continuar = modulo_venta(codigo,nombre,n_anaquel,precio_unit);
					break;
				case 3:
					continuar = modulo_cliente();
					break;
				default:	//opcion 4
					char salir[1];
					printf("Esta seguro que desea salir? (s para Confirmar, otra para Cancelar)\n");
					scanf("%s",&salir);
					
					if(strcmp(salir,"s")==0){	//funcion retorna 0 si salir es igual a "s"
						continuar = false;
						printf("Hasta luego\n");
					}
					break;
			}
		}
		system("pause");
		//system("cls");
	}while(continuar);
	
    return 0;
}


