#pragma once
#include <iostream>
#define wWindows 100
#define hWindows 30
using namespace std;
using namespace System;
class Nave
{
public:
	Nave();
	~Nave();
	void borrar();
	void mover();
	void dibujar();
	int getDY();
protected:
	int x, y, dx, dy, w, h;
};

Nave::Nave()
{
	y = 0;
	dx = 0;
	dy = 1;
}

Nave::~Nave()
{
}

void Nave::borrar() {
	for (int i = 0; i < h; i++)	{
		Console::SetCursorPosition(x, y + i);
		for (int j = 0; j < w; j++)
			cout << " ";
	}
}

void Nave::mover() {
	//if (x + dx <0 || x + dx + w > wWindows)
	//	dx = -dx;
	if (y + dy <0 || y + dy + h > hWindows)
		dy = 0;
	//x += dx;
	y += dy;
}
void Nave::dibujar() {

}

int Nave::getDY() {
	return dy;
}