#pragma once
#include "Avion1.h"
#include "Avion2.h"
#include "Avion3.h"

class Controladora
{
public:
	Controladora();
	~Controladora();
	void menu();
private:
	Avion1 objAvion1;
	Avion2 objAvion2;
	Avion3 objAvion3;
};

Controladora::Controladora()
{
}

Controladora::~Controladora()
{
}
void Controladora::menu() {
	int op;
	cout << "Ingrese avion a utilizar: ";
	cin >> op;
	Console::Clear();
	while (true)
	{
		switch (op)
		{
		case 1:
			objAvion1.borrar();
			objAvion1.mover();
			objAvion1.dibujar();
			break;
		case 2:
			objAvion2.borrar();
			objAvion2.mover();
			objAvion2.dibujar();
			break;
		case 3:
			objAvion3.borrar();
			objAvion3.mover();
			objAvion3.dibujar();
			break;
		}
		_sleep(100);
	}
}