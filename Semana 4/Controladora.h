#pragma once
#include "Corazon.h"
#include "Monigote.h"
#include "Fantasma.h"
#include <vector>
#include <conio.h>

class Controladora
{
public:
	Controladora();
	~Controladora();
	void jugar();
	void mover();
	void colision();
private:
	Monigote monigote;
	vector<Fantasma> fantasmas;
	vector<Corazon> corazones;
};

Controladora::Controladora()
{
	for (int i = 0; i < 10; i++)
		fantasmas.push_back(Fantasma());
	for (int i = 0; i < 12; i++)
		corazones.push_back(Corazon());
}

Controladora::~Controladora()
{
}

void Controladora::jugar() {
	
	char tecla = ' ';
	while (true)
	{
		Console::SetCursorPosition(70, 0);
		cout << "Puntos: " << 12 - corazones.size() << endl;
		if(kbhit())
			tecla = getch();
		monigote.direccion(tecla);

		for (int i = 0; i < fantasmas.size(); i++)
			fantasmas[i].borrar();
		monigote.borrar();

		mover();
		for (int i = 0; i < corazones.size(); i++)
			corazones[i].dibujar();
		for (int i = 0; i < fantasmas.size(); i++)
			fantasmas[i].dibujar();
		monigote.dibujar();

		colision();

		_sleep(100);
	}
}

void Controladora::mover() {
	for (int i = 0; i < fantasmas.size(); i++)
		fantasmas[i].mover();
	monigote.mover();
}

void Controladora::colision() {
	for (int i = 0; i < corazones.size(); i++)
		if (corazones[i].getX() == monigote.getX() && corazones[i].getY() == monigote.getY() ||
			corazones[i].getX() == monigote.getX() && corazones[i].getY() == monigote.getY() + 1) {
			corazones.erase(corazones.begin()+i);
			i--;
		}
}