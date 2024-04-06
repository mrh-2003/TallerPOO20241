#pragma once
#include "Eclipse.h"
#include "vector"


class Controladora
{
public:
	Controladora();
	~Controladora();
	Eclipse getEclipse();
	void registrar();
	void modificar();
	void eliminar();
	void listar();
	void eclipsesVisiblesEuropa();
	void eclipsesSismos();
	void eclipsesNoche();
	void menu();
private:
	vector<Eclipse> eclipses;
};

Controladora::Controladora()
{
}

Controladora::~Controladora()
{
}

Eclipse Controladora::getEclipse() {
	string tipo, sismo, lluvia, visibilidad, fecha;
	int hora;
	cout << "Ingresar tipo: ";
	cin >> tipo;
	cout << "Ingresar sismo";
	cin >> sismo;
	cout << "Ingresar lluvia";
	cin >> lluvia;
	cin.ignore();
	cout << "Ingrese visibilidad: ";
	getline(cin, visibilidad);
	cout << "Ingresar fecha";
	cin >> fecha;
	cout << "Ingrese hora: ";
	cin >> hora;

	return Eclipse(tipo, sismo, lluvia, visibilidad, fecha, hora);
}

void Controladora::registrar() {
	eclipses.push_back(getEclipse());
}

void Controladora::listar() {
	cout << "Indice\tTipo\tSismo\tLluvia\tVisi\tFecha\thora\n";
	for (int i = 0; i < eclipses.size(); i++)
		cout << i << "\t" << eclipses[i].getString() << endl;
}
void Controladora::modificar() {
	int indice;
	listar(); ///[5 (5) 5 5 5 5 5  5 5 5]
	cout << "Ingrese el indice a modificar: ";
	cin >> indice;
	Eclipse nuevo = getEclipse();
	eclipses[indice].setTipo(nuevo.getTipo());
	eclipses[indice].setFecha(nuevo.getFecha());
	eclipses[indice].setHora(nuevo.getHora());
	eclipses[indice].setLluvia(nuevo.getLluvia());
	eclipses[indice].setSismo(nuevo.getSismo());
	eclipses[indice].setVisibilidad(nuevo.getVisibilidad());
}
void Controladora::eliminar() {
	int indice;
	listar();
	cout << "Ingrese el indice a eliminar: ";
	cin >> indice;
	eclipses.erase(eclipses.begin() + indice);
}
void Controladora::eclipsesVisiblesEuropa() {
	for (int i = 0; i < eclipses.size(); i++)
		if (eclipses[i].getVisibilidad() == "Europa")
			cout << eclipses[i].getString() << endl;
}
void Controladora::eclipsesSismos() {
	for (int i = 0; i < eclipses.size(); i++)
		if (eclipses[i].getSismo() == "Si")
			cout << eclipses[i].getString() << endl;
}
void Controladora::eclipsesNoche() {
	for (int i = 0; i < eclipses.size(); i++)
		if (eclipses[i].getHora() > 1800)
			cout << eclipses[i].getString() << endl;
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
			cout << "5. Visible Europa\n";
			cout << "6. Eclipse con sismo\n";
			cout << "7. Eclipse de noche\n";
			cout << "0. Salir\n";
			cout << "Ingresa la opcion: ";
			cin >> op;
		} while (!(op >=0 && op <= 7));
		switch (op)
		{
		case 1: registrar(); break;
		case 2: modificar(); break;
		case 3: eliminar(); break;
		case 4:listar(); break;
		case 5: eclipsesVisiblesEuropa(); break;
		case 6: eclipsesSismos(); break;
		case 7: eclipsesNoche(); break;
		}
		system("pause");
		system("cls");
	} while (op != 0);
}