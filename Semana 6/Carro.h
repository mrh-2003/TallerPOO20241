#pragma once
#include "Terrestre.h"

class Carro : public Terrestre{
private:
public:
	Carro(){
		w = 8;
		h = 3;
		dy = dx = 0;

	}
	void dibujar() {
		Console::SetCursorPosition(x, y);
		cout <<"   | ~\\_";
		Console::SetCursorPosition(x, y+1);
		cout <<"[| _ | -";
		Console::SetCursorPosition(x, y+2);
		cout <<" (_)(_)";
	}
};