#pragma once
#include "Avion.h"

class Avion3 : public Avion
{
public:
	Avion3();
	~Avion3();
	void dibujar();
private:

};

Avion3::Avion3()
{
	w = 19;
	h = 3;
	x = 70;
	y = 15;
}

Avion3::~Avion3()
{
}
void Avion3::dibujar() {
	Console::SetCursorPosition(x, y);
	cout << "       __|__";
	Console::SetCursorPosition(x, y + 1);
	cout << "________(*)________";
	Console::SetCursorPosition(x, y + 2);
	cout << "       o/ \o";

}