#pragma once
#include "Avion.h"

class Avion1 : public Avion
{
public:
	Avion1();
	~Avion1();
	void dibujar();
private:

};

Avion1::Avion1()
{
	w = 11;
	h = 3;
	x = 40;
	y = 15;
}

Avion1::~Avion1()
{
}
void Avion1::dibujar() {
	Console::SetCursorPosition(x, y);
	cout << "-----------";
	Console::SetCursorPosition(x, y + 1);
    cout << "_\\__(_)__/_";
	Console::SetCursorPosition(x, y + 2);
    cout << "  ./ \\.	";
	
}