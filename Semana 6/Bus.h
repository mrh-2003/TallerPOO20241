#pragma once
#include "Terrestre.h"

class Bus : public Terrestre {
private:
public:
	Bus() {
		w = 18;
		h = 3;
		dy = dx = 0;

	}
	void dibujar() {
		Console::SetCursorPosition(x, y);
		cout << "   /_|[][][][][]|";
		Console::SetCursorPosition(x, y + 1);
		cout << "  (             |";
		Console::SetCursorPosition(x, y + 2);
		cout << "|= --OO--- - OO -=";
	}
};