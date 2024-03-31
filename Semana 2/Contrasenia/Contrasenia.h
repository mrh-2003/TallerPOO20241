#pragma once
#include <iostream>
#include <string>

using namespace std;
using namespace System;

class Contrasenia
{
public:
	Contrasenia();
	Contrasenia(int longitud);
	~Contrasenia();
	bool esSeguro();
	void generarContrasena();
	int getLongitud();
	void setLongitud(int longitud);
	string getContra();
private:
	int longitud;
	string contra;
};

Contrasenia::Contrasenia()
{
	longitud = 8;
	contra = "";
	generarContrasena();
}

Contrasenia::Contrasenia(int longitud)
{
	this->longitud = longitud;
	contra = "";
	generarContrasena();
}

Contrasenia::~Contrasenia()
{
}

bool Contrasenia::esSeguro() {
	int cMayuscula = 0, cMinuscula = 0, cNumeros = 0;
	for (int i = 0; i < contra.size(); i++)
		if (contra[i] >= 'a' && contra[i] <= 'z')
			cMinuscula++;
		else if (contra[i] >= 'A' && contra[i] <= 'Z')
			cMayuscula++;
		else
			cNumeros++;
	return cMayuscula > 2 && cMinuscula > 1 && cNumeros > 5;
}

void Contrasenia::generarContrasena() {
	Random r; 
	for (int i = 0; i < longitud; i++) {
		switch (r.Next(0, 3))
		{
		case 0: contra += char(r.Next('a', 'z' + 1)); break;
		case 1:  contra += char(r.Next('A', 'Z' + 1)); break;
		case 2:  contra += to_string(r.Next(0, 10)) ; break;
		}
		_sleep(10);
	}
}

int Contrasenia::getLongitud() {
	return longitud;
}
void Contrasenia::setLongitud(int longitud) {
	this->longitud = longitud;
}
string Contrasenia::getContra() {
	return contra;
}