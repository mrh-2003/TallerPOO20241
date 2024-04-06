#pragma once
#include "Plato.h"
#include <vector>


class Controladora
{
public:
	Controladora();
	~Controladora();
	Plato getPlato();
	void registrar();
	void modificar();
	void eliminar();
	void listar();
	void platosCaros();
	void platosPicantes();
	void menu();
private:
	vector<Plato> platos;
};

Controladora::Controladora()
{
}

Controladora::~Controladora()
{
}

Plato Controladora::getPlato() {
	string nombre, esPicante;
	int temperatura, cantidad;
	double precio;
	cout << "Ingresar nombre: ";
	cin.ignore();
	getline(cin, nombre);
	cout << "Ingresar si es picante";
	cin >> esPicante;
	cout << "Ingresar temperatura";
	cin >> temperatura;
	cout << "Ingrese cantidad: ";
	cin >> cantidad;
	cout << "Ingresar precio";
	cin >> precio;

	return Plato(cantidad,precio, nombre,esPicante,temperatura);
}

void Controladora::registrar() {
	platos.push_back(getPlato());
}

void Controladora::listar() {
	cout << "Indice\tCantidad\tPrecio\tNombre\tPicante\tTemperatura\n";
	for (int i = 0; i < platos.size(); i++)
		cout << i << "\t" << platos[i].getString() << endl;
}
void Controladora::modificar() {
	int indice;
	listar(); 
	cout << "Ingrese el indice a modificar: ";
	cin >> indice;
	Plato nuevo = getPlato();
	platos[indice].setnombre(nuevo.getnombre());
	platos[indice].setcantidad(nuevo.getcantidad());
	platos[indice].setesPicante(nuevo.getesPicante());
	platos[indice].setprecio(nuevo.getprecio());
	platos[indice].settemperatura(nuevo.gettemperatura());
}
void Controladora::eliminar() {
	int indice;
	listar();
	cout << "Ingrese el indice a eliminar: ";
	cin >> indice;
	platos.erase(platos.begin() + indice);
}

void Controladora::platosCaros() {
	for (int i = 0; i < platos.size(); i++)
		if (platos[i].getprecio() > 100)
			cout << platos[i].getString() << endl;
}
void Controladora::platosPicantes() {
	for (int i = 0; i < platos.size(); i++)
		if (platos[i].getesPicante() == "Si")
			cout << platos[i].getString() << endl;
}

void  Controladora::menu() {
	int op;
	do
	{
		do
		{
			cout << "1. Ingresar\n";
			cout << "2. Modificar\n";
			cout << "3. Eliminar\n";
			cout << "4. Listar\n";
			cout << "5. Platos caros\n";
			cout << "6. Platos picantes\n";
			cout << "0. Salir\n";
			cout << "Ingresa la opcion: ";
			cin >> op;
		} while (!(op >=0 && op <= 6));
		switch (op)
		{
		case 1: registrar(); break;
		case 2: modificar(); break;
		case 3: eliminar(); break;
		case 4:listar(); break;
		case 5: platosCaros(); break;
		case 6: platosPicantes(); break;
		}
		system("pause");
		system("cls");
	} while (op != 0);
}