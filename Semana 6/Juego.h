#pragma once
#include "Carro.h"
#include "Bus.h"
#include "Bicicleta.h"
#include "Persona.h"

class Juego {
private:
	vector<Terrestre*> transportes;
	Persona persona;
	time_t tiempoInicial;
public:
	Juego() {
		tiempoInicial = time(0); // Tiempo actual 11:25:30:10
		for (int i = 0; i < 5; i++)
			agregarTransporte();
	}

	void agregarTransporte() {
		switch (rand() % 3)
		{
		case 0: transportes.push_back(new Bicicleta()); break;
		case 1: transportes.push_back(new Bus()); break;
		case 2: transportes.push_back(new Carro()); break;
		}
	}

	void logicaMovimiento() {
		for (int i = 0; i < transportes.size(); i++) {
			transportes[i]->borrar();
			transportes[i]->generarMovimiento();
			transportes[i]->dibujar();
		}
		persona.borrar();
		persona.generarMovimiento();
		persona.dibujar();
	}

	void jugar() {
		char tecla;
		do
		{
			Console::SetCursorPosition(0, 0);
			cout << "Vidas: " << persona.getVidas();
			tecla = NULL;
			if (kbhit())
				tecla = toupper(getch());
			persona.direccion(tecla);
			logicaMovimiento();
			if (difftime(time(0), tiempoInicial) > 3) {
				tiempoInicial = time(0);
				agregarTransporte();
			}
			colisionar();
			eliminar();
			_sleep(100);
		} while (!siTerminar());
	}

	void colisionar() {
		for (int i = 0; i < transportes.size(); i++)
			if (transportes[i]->colision(persona.getX(), persona.getY(), persona.getW(), persona.getH())) 
				if (transportes[i]->getTipo() != 0) {
					persona.setVidas();
					transportes[i]->borrar();
					transportes.erase(transportes.begin() + i);
				}
	}

	bool siTerminar() {
		return persona.getVidas() == 0 || transportes.size() == 10;
	}

	void eliminar() {
		for (int i = 0; i < transportes.size(); i++) 
			if (transportes[i]->getDX() == 0) {
				transportes[i]->borrar();
				transportes.erase(transportes.begin() + i);
			}
	}
};