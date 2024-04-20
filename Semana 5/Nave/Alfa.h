#pragma once
#include "Nave.h"

class Alfa : public Nave
{
public:
	Alfa();
	~Alfa();
	void dibujar();
private:

};

Alfa::Alfa()
{
	w = 19;
	h = 5;
	x = 3;
}

Alfa::~Alfa()
{
}
void Alfa::dibujar() {
	Console::SetCursorPosition(x, y);
	    cout << "      _.-- - ._ ";
	Console::SetCursorPosition(x, y + 1);
		cout << "    .'         '.";
	Console::SetCursorPosition(x, y + 2);
		cout << "_.-~======== = ~-._";
	Console::SetCursorPosition(x, y + 3);
		cout << "  (______________)";
	Console::SetCursorPosition(x, y + 4);
		cout << "     \\_______ /";
}