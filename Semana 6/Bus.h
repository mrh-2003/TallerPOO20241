#pragma once
#include "Terrestre.h"

class Bus : public Terrestre {
private:
public:
	Bus() {
		w = 18;
		h = 3;
		dy = dx = 0;
		x = wWindows - w;
		dx = -4;
		tipo = 2;
		y = rand() % (hWindows - h);
	}
	void dibujar() {
		Console::SetCursorPosition(x, y);
		cout << "   /_|[][][][][]|";
		Console::SetCursorPosition(x, y + 1);
		cout << "  (             |";
		Console::SetCursorPosition(x, y + 2);
		cout << "|= --OO--- - OO -=";
	}
	void generarMovimiento() {
		dx = -(5 + rand() % 3);
		validarMovimiento();
	}
};