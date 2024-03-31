#include "Persona.h"
#include <conio.h>


void main() {
	string nombre;
	char sexo;
	int edad;
	double peso, altura;
	Persona obj1;
	Persona obj2;
	Persona obj3;
	cout << "Ingrese nombre: ";
	cin >> nombre;															 
	cout << "Ingrese edad: ";												 
	cin >> edad;															 
	cout << "Ingrese sexo: ";												 
	cin >> sexo;															 
	cout << "Ingrese peso:";												 
	cin >> peso;															 
	cout << "Ingrese altura: ";												 
	cin >> altura;															 
	obj1 = Persona(nombre, edad, sexo, peso, altura);						 
	obj2 = Persona(nombre, edad + 10, sexo);								 
	obj3 = Persona();														 
	obj3.setNombre(nombre);													 
	obj3.setEdad(edad - 10);												 
	obj3.setSexo(sexo);
	obj3.setPeso(peso + 10);
	obj3.setAltura(altura);
	cout << "El peso de la persona 1: " << obj1.calcularIMC() << endl;
	cout << "El peso de la persona 2: " << obj2.calcularIMC() << endl;
	cout << "El peso de la persona 3: " << obj3.calcularIMC() << endl;

	cout << "Es mayor de edad la persona 1: " << obj1.esMayorDeEdad() << endl;
	cout << "Es mayor de edad la persona 2: " << obj2.esMayorDeEdad() << endl;
	cout << "Es mayor de edad la persona 3: " << obj3.esMayorDeEdad() << endl;

	getch();

}