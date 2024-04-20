#pragma once
#include <vector>
#include <conio.h>
#include "Gamma.h"
#include "Alfa.h"
#include "Beta.h"

class Controladora
{
public:
	Controladora();
	~Controladora();
	void juego();
	void logicaMovimiento();
	void logicaEliminar();
private:
	vector< Gamma> gammas;
	vector<Alfa> alfas;
	vector<Beta> betas;
	int  cA, cB, cTotal;
};

Controladora::Controladora()
{
	cA = cB = cTotal = 0;
}

Controladora::~Controladora()
{
}

void Controladora::juego() {
	char tecla = NULL;
	string mensaje = "comienza la invasión...!!!";
	Console::SetCursorPosition((wWindows - mensaje.size()) / 2,15);
	cout << mensaje;
	_sleep(1000);
	Console::Clear();
	do
	{
		tecla = NULL;
		if (kbhit())
			tecla = toupper(getch());
		if (tecla == 'A') {
			alfas.push_back(Alfa());
			cA++;
			cTotal++;
		}
		if (cA == 2) {
			betas.push_back(Beta());
			cA = 0;
			cB++;
			cTotal++;
		}
		if (cB == 2) {
			gammas.push_back(Gamma());
			cB = 0;
			cTotal++;
		}
		logicaMovimiento();
		logicaEliminar();
		_sleep(100);
	} while (cTotal < 20);
	mensaje = "Hemos sido invadidos...";
	Console::SetCursorPosition((wWindows - mensaje.size()) / 2, 15);
	cout << mensaje;
	getch();
	getch();
	getch();
}


void Controladora::logicaMovimiento() {
	for (int i = 0; i < alfas.size(); i++) {
		alfas[i].borrar();
		alfas[i].mover();
		alfas[i].dibujar();
	}
	for (int i = 0; i < betas.size(); i++) {
		betas[i].borrar();
		betas[i].mover();
		betas[i].dibujar();
	}
	for (int i = 0; i < gammas.size(); i++) {
		gammas[i].borrar();
		gammas[i].mover();
		gammas[i].dibujar();
	}
}
void Controladora::logicaEliminar() {
	for (int i = 0; i < alfas.size(); i++)
		if (alfas[i].getDY() == 0) {
			alfas[i].borrar();
			alfas.erase(alfas.begin() + i);
			i--;
		}
	for (int i = 0; i < betas.size(); i++)
		if (betas[i].getDY() == 0) {
			betas[i].borrar();
			betas.erase(betas.begin() + i);
			i--;
		}
	for (int i = 0; i < gammas.size(); i++)
		if (gammas[i].getDY() == 0) {
			gammas[i].borrar();
			gammas.erase(gammas.begin() + i);
			i--;
		}
}