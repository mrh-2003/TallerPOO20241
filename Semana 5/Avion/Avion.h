#pragma once
#include <iostream>
#define wWindows 100
#define hWindows 30
using namespace std;
using namespace System;
class Avion
{
public:
	Avion();
	~Avion();
	void borrar();
	void mover();
	void dibujar();
protected:
	int x, y, dx, dy, w, h;
};

Avion::Avion()
{
	dx = 2+  rand() % 5;
	dy = 1;
}

Avion::~Avion()
{
}

void Avion::borrar() {
	for (int i = 0; i < h; i++) {
		Console::SetCursorPosition(x, y + i);
		for (int j = 0; j < w; j++)
			cout << " ";
	}
}
void Avion::mover() {
	if (x + dx <0 || x + dx + w > wWindows)
		dx = -dx;
	if (y + dy <0 || y + dy + h > hWindows)
		dy = -dy;
	x += dx;
	y += dy;
}
void Avion::dibujar() {

}