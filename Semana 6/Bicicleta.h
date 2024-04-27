#pragma once
#include "Terrestre.h"

class Bicicleta : public Terrestre {
private:
public:
	Bicicleta() {
		w = 8;
		h = 2;
		dy = 0;
		dx = 1 + rand() % 3; //[1- 3]
	}
	void dibujar() {
		if (dx > 0) {
			Console::SetCursorPosition(x, y);
			cout << ".._\\";
			Console::SetCursorPosition(x, y + 1);
			cout << "(o)(o)";
		}
		else {
			Console::SetCursorPosition(x, y);
			cout << "/_.. ";
			Console::SetCursorPosition(x, y + 1);
			cout << "(o)(o)";
		}
	}
};