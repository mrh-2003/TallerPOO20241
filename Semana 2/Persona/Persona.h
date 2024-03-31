#pragma once
#include <iostream>
#include <string>

using namespace std;
using namespace System;

class Persona
{
public:
	Persona();
	Persona(string nombre, int edad, char sexo);
	Persona(string nombre, int edad, char sexo, double peso, double altura);
	~Persona();
	int calcularIMC();
	bool esMayorDeEdad();
	void comprobarSexo(char sexo);
	string toString();
	void generaDNI();
	void setNombre(string valor);
	void setSexo(char valor);
	void setEdad(int valor);
	void setPeso(double valor);
	void setAltura(double valor);

private:
	string nombre, dni;
	char sexo;
	int edad;
	double peso, altura;
};

Persona::Persona()
{
	nombre = "";
	sexo = 'H';
	edad = peso = altura = 0;
	generaDNI();
}

Persona::Persona(string nombre, int edad, char sexo) {
	this->nombre = nombre;
	this->edad = edad;
	this->sexo = sexo;
	peso = altura = 0;
	generaDNI();
}
Persona::Persona(string nombre, int edad, char sexo, double peso, double altura) {
	this->nombre = nombre;
	this->edad = edad;
	this->sexo = sexo;
	this->altura = altura;
	this->peso = peso;
	generaDNI();
}

Persona::~Persona()
{
}


int Persona::calcularIMC() {
	double imc = peso / pow(altura, 2);
	if (imc < 20) return -1;
	else if (imc <= 25) return 0;
	else return 1;
}
bool Persona::esMayorDeEdad() {
	return edad >= 18;
}
void Persona::comprobarSexo(char sexo) {
	if (sexo == 'H' || sexo == 'M')
		this->sexo = sexo;
	else
		this->sexo = 'H';
}
string Persona::toString() {
	return "DNI: " + dni + " Nombre: " + nombre + " Edad: " + to_string(edad) + " Sexo: " + sexo + " Peso: "+ to_string(peso) + " Altura: " + to_string(altura) + "\n";
}
void Persona::generaDNI() {
	Random r;
	for (int i = 0; i < 8; i++)
		dni += to_string(r.Next(0, 10));
}

void Persona::setNombre(string valor) { nombre = valor; }
void Persona::setSexo(char valor) { sexo = valor; }
void Persona::setEdad(int valor) { edad = valor; }
void Persona::setPeso(double valor) { peso = valor; }
void Persona::setAltura(double valor) { altura = valor; }