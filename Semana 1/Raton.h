#pragma once
#include <iostream>

using namespace std;
using namespace System;

class Raton
{
public:
	Raton();
	~Raton();
	void borrar();
	void mover();
	void dibujar();
private:
	int x, y, w, h, dx, dy;
};

Raton::Raton() //INICIO
{
	w = 18;
	h = 3;
	x = 10; //PUNTO INICIAL
	y = 20;
	dy = 0;
	dx = 2;
}

Raton::~Raton() //FINAL
{
}

void Raton::borrar() {
	Console::SetCursorPosition(x, y);
	cout << "                  ";
	Console::SetCursorPosition(x, y + 1);
	cout << "                  ";
	Console::SetCursorPosition(x, y + 2);
	cout << "                  ";
}
void Raton::mover() {
	if (x + dx < 0 || x+ w + dx > 100)
		dx = -dx;
	if (y + dy < 0 || y + h + dy > 30)
		dy = -dy;
	x = x + dx;
	y = y + dy;
}
void Raton::dibujar() {
	Console::SetCursorPosition(x, y);
	cout << "          ____()()";
	Console::SetCursorPosition(x, y + 1);
	cout << "       /       @@";
	Console::SetCursorPosition(x, y + 2);
	cout << "`~~~*~\\_; m__m._>o";	
}