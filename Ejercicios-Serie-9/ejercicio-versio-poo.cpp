#include <iostream>
#include <string>

using namespace std;

//Definición de variables globales
int i;

//Definicion de clases a usar
class disco{
	private:
		string titulo;
		int numero_canciones;
		
	public:
		void registrar(int indice){
			cout << "\tIngrese el titulo del disco "<< indice << endl <<"\t";
			cin >> titulo;
			cout << "\tIngrese la cantidad de canciones del disco "<< indice << endl <<"\t";
			cin >> numero_canciones;
		}
		void mostrar(int indice){
			cout << "\t   "<< indice << ") ";
			cout << "\t" << titulo <<" ("<< numero_canciones <<" canciones)" << endl;
		}
};

class pelicula{
	private:
		string clasificacion;
		string nombre;
		string nombre_personaje;	
	public:
		void registrar(int indice){
			cout << "\tIngrese el nombre de la pelicula " << indice << endl<<"\t";
			cin >> nombre;
			cout << "\tIngrese la clasificacion de la pelicula " << indice << endl<<"\t";
			cin >> clasificacion;
			cout << "\tIngrese el nombre del personaje en la pelicula " << indice << endl<<"\t";
			cin >> nombre_personaje;
		}
		void mostrar(int indice){
			cout << "\tPELICULA "<< (indice) << endl;
			cout << "\tNombre Pelicula                 : " << nombre << endl;
			cout << "\tClasificacion Pelicula          : " << clasificacion << endl;
			cout << "\tNombre del Actor en la Pelicula : " << nombre_personaje << endl;
		}
};

class novela{
	private:
		string nombre;
		string nombre_personaje;
	public:
		void registrar(int indice){
			cout << "\tIngrese el nombre de la novela " << indice << endl<<"\t";
			cin >> nombre;
			cout << "\tIngrese el nombre del personaje en la novela " << indice << endl<<"\t";
			cin >> nombre_personaje;
		}
		void mostrar(int indice){
			cout << "\tNOVELA "<< (indice) << endl;
			cout << "\tNombre Novela                 : " << nombre << endl;
			cout << "\tNombre del Actor en la Novela : " << nombre_personaje << endl;
		}
};

class actor{
	private:
		string nombre;
		int edad;
		int numero_peliculas;
		pelicula peliculas[99];
		int numero_novelas;
		novela novelas[99];
	public:
		void registrar(){
			system("cls");
			cout << "Ingresa la informacion del actor" << endl;
			cout << "Ingrese nombre del actor" << endl;
			cin >> nombre;
			cout << "Ingrese edad del actor" << endl;
			cin >> edad;
			do{
				cout << "Ingrese cantidad de peliculas del actor" << endl;
				cin >> numero_peliculas;
				if(numero_peliculas>99){
					cout << "\tEl maximo posible de peliculas a ingresar es 99" << endl;
				}
			}while(numero_peliculas>99);
			
			for(i=0;i<numero_peliculas;i++){
				pelicula nueva_P;
				nueva_P.registrar(i+1);
				peliculas[i] = nueva_P;
			}
			
			do{
				cout << "Ingrese cantidad de novelas del actor" << endl;
				cin >> numero_novelas;
				if(numero_novelas>99){
					cout << "\tEl maximo posible de novelas a ingresar es 99" << endl;
				}
			}while(numero_novelas>99);
			
			for(i=0;i<numero_novelas;i++){
				novela nueva_N;
				nueva_N.registrar(i+1);
				novelas[i] = nueva_N;
			}
		}
		void mostrar(){
			system("cls");
			cout << "Información registrada del Actor" << endl;
			cout << "\tNombre del Actor : " << nombre << endl;
			cout << "\tEdad del Actor   : " << edad << endl;
			cout << "\tPeliculas        : " << numero_peliculas << endl;
			for(i=0;i<numero_peliculas;i++){
				peliculas[i].mostrar(i+1);
			}
			cout << endl << "\tNovelas         : " << numero_novelas << endl;
			for(i=0;i<numero_novelas;i++){
				novelas[i].mostrar(i+1);
				/*	//Estas lineas no funcionan en orientacion a objetos, porque las variables son privadas en la clase novela
				cout << "\tNOVELA "<< (i+1) << endl;
				cout << "\tNombre Novela                 : " << novelas[i].nombre << endl;
				cout << "\tNombre del Actor en la Novela : " << novelas[i].nombre_personaje << endl;
				*/
			}
			system("pause");
		}
};

class cantante{
	private:
		string nombre;
		int edad;
		int numero_discos;
		disco discos[99];
	public:
		void registrar(){
			system("cls");
			cout << "Ingresa la informacion del cantante"<< endl<< endl;
			cout <<  "Ingrese nombre del cantante"<< endl;
			cin >> nombre;
			cout << "Ingrese edad del cantante"<< endl;
			cin >> edad;
			do{
				cout << "Ingrese cantidad de discos del cantante"<< endl;
				cin >> numero_discos;
				if(numero_discos>99){
					cout << "\tEl maximo posible de discos a ingresar es 99"<< endl;
				}
			}while(numero_discos>99);
			
			for(i=0;i<numero_discos;i++){
				disco nuevo;
				nuevo.registrar(i+1);
				discos[i] = nuevo;
			}
		}
		void mostrar(){
			system("cls");
			cout << "Informacion registrada del Cantante" << endl;
			cout << "\tNombre  : " << nombre << endl;
			cout << "\tEdad    : " << edad << endl;
			cout << "\tDiscos  : " << numero_discos << endl;
			for(i=0;i<numero_discos;i++){
				discos[i].mostrar(i+1);
			}
			system("pause");
		}
};

int main(){
	int opcion;
	bool salir = false;
	while(!salir){
		system("cls");
		cout << "Indique el tipo de artista que desea almacenar" << endl;
		cout << "\t1) Cantante" << endl;
		cout << "\t2) Actor" << endl;
		cout << endl << "\t\tSu opcion : ";
		cin >> opcion;
		switch(opcion){
			case 1:
			{
				cantante nuevo;
				nuevo.registrar();
				nuevo.mostrar();
			}
			break;
			case 2:
			{
				actor nuevo;
				nuevo.registrar();
				nuevo.mostrar();
			}
			break;
			default:
				//opcion invalida
				salir = true;
		}	
	}
	return 1;
}
