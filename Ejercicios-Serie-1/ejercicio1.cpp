#include <iostream>
#include <string>
using namespace std;
int main()
{
	string alCodigo,alNombre;
	int contador;
	float nota, promedio, sumatoria;
    cout << "Indique el codigo del alumno" << std::endl;
    cin >> alCodigo;
    
    cout << "Indique el nombre del alumno "<< std::endl;
	cin >> alNombre;
	
	contador = 0;
	sumatoria = 0;
	
	while (contador<4){
		cout << "Ingrese nota" << (contador+1) << std::endl;
		cin >>  nota;
		sumatoria = sumatoria + nota;
		contador = contador +1;
	}
		
	
	promedio = sumatoria/contador;
	if(promedio>= 95) {
		promedio = 100;
	}
		
	cout <<  "Detalle Final Alumno" << std::endl;
	cout <<  "   Codigo : " <<  alCodigo << std::endl;
	cout <<  "   Nombre : " <<  alNombre << std::endl;
	cout <<  "   Promedio : " <<  promedio << std::endl;
    
	
	system("PAUSE()");
    return 0;
}
