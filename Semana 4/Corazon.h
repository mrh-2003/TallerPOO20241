#pragma once
#include <iostream>
#define wWindows 100
#define hWindows 30

using namespace std;
using namespace System;

class Corazon
{
public:
	Corazon();
	~Corazon();
	void dibujar();
	int getX();
	int getY();
private:
	int x, y,  w, h, color;
};

Corazon::Corazon()
{
	h = w = 1;
	x = rand() % (wWindows - w);
	y = rand() % (hWindows - h);
	color = 12;
}

Corazon::~Corazon()
{
}

void Corazon::dibujar()
{
	Console::ForegroundColor = ConsoleColor(color);
	Console::SetCursorPosition(x, y);
	cout << "*";
	Console::ForegroundColor = ConsoleColor::Gray;
}

int Corazon::getX() { return x; }
int Corazon::getY() { return y; }