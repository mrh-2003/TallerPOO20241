#pragma once
#include "Figura.h"
#define izquierda 75
#define derecha 77
#define arriba 72
#define abajo 80

class Monigote : public Figura {
private:
	int vidas;
	int pasos;
	bool inmune;
public:
	Monigote() {
		w = 1;
		h = 2;
		dx = dy = 0;
		x = 0;
		y = 0;
		vidas = 3;
		pasos = 0;
		inmune = false;
	}
	void dibujar() {
		Console::SetCursorPosition(x, y);
		cout << "0";
		Console::SetCursorPosition(x, y + 1);
		cout << "+";
	}
	void mover() {
		validarMovimiento(0, 0);
	}
	void direccion(char tecla) {
		dx = dy = 0;
		switch (tecla)
		{
		case izquierda: dx = -3; break;
		case derecha: dx = 3; break;
		case arriba: dy = -2; break;
		case abajo: dy = 2; break;
		}
	}
	void reposicionar() {
		vidas--;
		borrar();
		x = 0;
		y = 0;
	}
	int getVidas() {
		return vidas;
	}
	int getPasos() {
		return pasos;
	}
	void setPasos() {
		pasos++;
	}
	void setInmune(bool _inmune ) {
		inmune = _inmune;
	}
	bool getInmune() {
		return inmune;
	}
};