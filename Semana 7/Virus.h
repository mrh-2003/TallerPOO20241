#pragma once
#include "Figura.h"

class Virus : public Figura {
private:
public:
	Virus() {
		w = 5;
		h = 3;
		dx = 1 + rand() % 5;
		dy = 1 + rand() % 3;
		x = rand() % (wWindows - w);
		y = rand() % (hWindows - h);
	}
	void dibujar() {
		Console::SetCursorPosition(x, y);
		cout << ",-^-.";
		Console::SetCursorPosition(x, y + 1);
		cout << "|\\/\\|";
		Console::SetCursorPosition(x, y + 2);
		cout << "`-V-'";
	}
	void mover() {
		validarMovimiento(-dx, -dy);
	}
};