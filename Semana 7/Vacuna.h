#pragma once
#include "Figura.h"

class Vacuna : public Figura {
private:
public:
	Vacuna() {
		w = 4;
		h = 1;
		reposicionar();
	}
	void dibujar() {
		Console::SetCursorPosition(x, y);
		cout << "|->|";
	}
	void mover() {
		validarMovimiento(-dx, -dy);
	}
	void reposicionar() {
		do
		{
			dx = rand() % 3 - 1;
			dy = rand() % 3 - 1;
		} while (abs(dx) == abs(dy));
		x = 0;
		y = 0;
	}
};