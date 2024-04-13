#pragma once
#include <iostream>
#define wWindows 100
#define hWindows 30

#define izquierda 75
#define derecha 77
#define arriba 72
#define abajo 80

using namespace std;
using namespace System;

class Monigote
{
public:
	Monigote();
	~Monigote();
	void mover();
	void borrar();
	void dibujar();
	void direccion(char tecla);
	int getX();
	int getY();
private:
	int x, y, dx, dy, w, h, color;
};

Monigote::Monigote()
{
	h = 2;
	w = 1;
	x = rand() % (wWindows - w);
	y = rand() % (hWindows - h);
	color = 1 + rand() % 15;
	dx = dy = 0;
}

Monigote::~Monigote()
{
}

void Monigote::mover()
{
	if (x + dx < 0 || x + w + dx > wWindows)
		dx = 0;
	if (y + dy < 0 || y + h + dy > hWindows)
		dy = 0;
	x = x + dx;
	y += dy;
}

void Monigote::borrar()
{
	for (int i = 0; i < h; i++) {
		Console::SetCursorPosition(x, y + i);
		for (int j = 0; j < w; j++)        
			cout << " ";
	}
}

void Monigote::dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << "0";
	Console::SetCursorPosition(x, y + 1);
	cout << "┼";
	Console::ForegroundColor = ConsoleColor::Gray;
}

void Monigote::direccion(char tecla)
{
	dx = dy = 0;
	//switch (tecla)
	//{
	//case 'A': dx = -2; break;
	//case 'D': dx = 2; break;
	//case 'W': dy = -1; break;
	//case 'S': dy = -1; break;
	//}
	switch (tecla)
	{
	case izquierda: dx = -1; break;
	case derecha: dx = 1; break;
	case arriba: dy = -1; break;
	case abajo: dy = 1; break;
	}
}
int Monigote::getX(){return x;}
int Monigote::getY(){return y;}