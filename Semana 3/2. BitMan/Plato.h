#pragma once
#include <iostream>
#include <string>

using namespace std;

class Plato
{
public:
	Plato();
	Plato(int _cantidad, double _precio, string _nombre, string _esPicante, int _temperatura);
	~Plato();
	string getString(); //MOSTRAR INFORMACION
	void setcantidad(int valor);
	void setprecio(double valor);
	void setnombre(string valor);
	void setesPicante(string valor);
	void settemperatura(int valor);

	int getcantidad();
	double getprecio();
	string getnombre();
	string getesPicante();
	int gettemperatura();
private:
	string nombre, esPicante;
	int temperatura, cantidad;
	double precio;
};

Plato::Plato()
{
}

Plato::Plato(int _cantidad, double _precio, string _nombre, string _esPicante, int _temperatura)
{
	cantidad = _cantidad;
	precio = _precio;
	nombre = _nombre;
	esPicante = _esPicante;
	temperatura = _temperatura;
}

Plato::~Plato()
{
}

string Plato::getString() {
	return to_string(cantidad) + "\t" + to_string(precio) + "\t" + nombre + "\t" + esPicante + "\t" + to_string(temperatura);
}

void Plato::setcantidad(int valor) { cantidad = valor; }
void Plato::setprecio(double valor) { precio = valor; }
void Plato::setnombre(string valor) { nombre = valor; }
void Plato::setesPicante(string valor) { esPicante = valor; }
void Plato::settemperatura(int valor) { temperatura = valor; }


int Plato::getcantidad() { return cantidad; }
double Plato::getprecio() { return precio; }
string Plato::getnombre() { return nombre; }
string Plato::getesPicante() { return esPicante; }
int    Plato::gettemperatura() { return temperatura; }