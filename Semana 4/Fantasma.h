#pragma once
#include <iostream>
#define wWindows 100
#define hWindows 30

using namespace std;
using namespace System;

class Fantasma
{
public:
	Fantasma();
	~Fantasma();
	void mover();
	void borrar();
	void dibujar();
private:
	int x, y, dx, dy, w, h, color;
};

Fantasma::Fantasma()
{
	h = 8;
	w = 11;
	x = rand() % (wWindows - w);
	y = rand() % (hWindows - h);
	color = 1 + rand() % 15;

	//if(rand() % 2)
	//	dx = 2;
	//else
	//	dx = -2;
	
	//dx = rand() % 2 ? 2 : -2;

	dx = (rand() % 2 * 2 - 1) *3; //-2 2
	dy = (rand() % 2 * 2 - 1) *2;
}

Fantasma::~Fantasma()
{
}

void Fantasma::mover()
{
	if (x + dx < 0 || x + w + dx > wWindows)
		dx = -dx;
	if (y + dy < 0 || y + h + dy > hWindows)
		dy *= -1; //dy = dy *-1;
	x = x + dx;
	y += dy;
}

void Fantasma::borrar()
{
	for (int i = 0; i < h; i++){
		Console::SetCursorPosition(x, y + i);
		for (int j = 0; j < w; j++)//            
			cout << " ";
	}
}

void Fantasma::dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << "   .-.";
	Console::SetCursorPosition(x, y+1);
	cout << "   ( \" )";
	Console::SetCursorPosition(x, y+2);
	cout << "/\\_.' '._/\\";
	Console::SetCursorPosition(x, y+3);
	cout << "|         |";
	Console::SetCursorPosition(x, y+4);
	cout << " \\       /";
	Console::SetCursorPosition(x, y+5);
	cout << "  \\    /`";
	Console::SetCursorPosition(x, y+6);
	cout << "(__)  /";
	Console::SetCursorPosition(x, y+7);
	cout << "`.__.'";
	Console::ForegroundColor = ConsoleColor::Gray;
}
