#pragma once
#include "Terrestre.h"

class Carro : public Terrestre{
private:
public:
	Carro(){
		w = 8;
		h = 3;
		dy = dx = 0;
		x = 0;
		dx = 3;
		tipo = 1;
		y = rand() % (hWindows - h);
	}
	void dibujar() {
		Console::SetCursorPosition(x, y);
		cout <<"   | ~\\_";
		Console::SetCursorPosition(x, y+1);
		cout <<"[| _ | -";
		Console::SetCursorPosition(x, y+2);
		cout <<" (_)(_)";
	}
	void generarMovimiento() {
		dx = 3 + rand() % 3;
		validarMovimiento();
	}
};