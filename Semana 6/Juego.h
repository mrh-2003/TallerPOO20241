#pragma once
#include "Carro.h"
#include "Bus.h"
#include "Bicicleta.h"
#include "Persona.h"

class Juego {
private:
	vector<Terrestre> transportes;
	Persona persona;
public:
	Juego() {

	}

	void logicaMovimiento() {

	}

	void jugar() {
		do
		{
			logicaMovimiento();
			_sleep();
		} while (true);
	}

	bool colisionar() {

	}
};