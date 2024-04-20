#pragma once
#include "Nave.h"

class Gamma : public Nave
{
public:
	Gamma();
	~Gamma();
	void dibujar();
private:

};

Gamma::Gamma()
{
	w = 17;
	h = 6;
	x = 70;
}

Gamma::~Gamma()
{
}
void Gamma::dibujar() {
	Console::SetCursorPosition(x, y);
	cout << "    .-\" ^ \"-.";
	Console::SetCursorPosition(x, y + 1);
	cout << "    /_....._\\";
	Console::SetCursorPosition(x, y + 2);
	cout << "  .-\"` `\"-.";
	Console::SetCursorPosition(x, y + 3);
	cout << "( ooo ooo ooo )";
	Console::SetCursorPosition(x, y + 4);
	cout << "'-.,_________,.-'";
	Console::SetCursorPosition(x, y + 5);
	cout << "      / \\";
}