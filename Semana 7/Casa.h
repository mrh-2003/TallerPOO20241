#pragma once
#include "Figura.h"

class Casa : public Figura {
private:
public:
	Casa() {
		w = 14;
		h = 4;
		dx = 0;
		dy = 0;
		x = wWindows- w;
		y = hWindows - h;
	}
	void dibujar() {
		Console::SetCursorPosition(x, y);
		cout << ".-. _______|";
		Console::SetCursorPosition(x, y+1);
		cout << "|=|/     /  \\";
		Console::SetCursorPosition(x, y+2);
		cout << "| |_____|_""_|";
		Console::SetCursorPosition(x, y+3);
		cout << "|_|_[X]_|____|";
	}
	void mover() {
		validarMovimiento(0, 0);
	}
};