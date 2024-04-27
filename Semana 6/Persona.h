#pragma once
#include "Terrestre.h"
#define izquierda 75
#define derecha 77
#define arriba 72
#define abajo 80


class Persona : public Terrestre {
private:
	int vidas;
public:
	Persona() {
		vidas = 3;
		w = 1;
		h = 1;
		dy = dx = 0;
		y = hWindows - 4;
		x = wWindows / 2;
	}
	void dibujar() {
		Console::SetCursorPosition(x, y);
		cout << char(254);
	}
	void direccion(char tecla) {
		dx = dy = 0;
		switch (tecla)
		{
		case derecha: dx = 2; break;
		case izquierda: dx = -2; break;
		case arriba: dy = -1; break;
		case abajo: dy = 1; break;
		}
	}
	void setVidas() {
		vidas--;
	}
	int getVidas() {
		return vidas;
	}
};