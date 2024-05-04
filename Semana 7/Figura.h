#pragma once
#include <iostream>
#include <conio.h>
#include <vector>
#define wWindows 100
#define hWindows 30

using namespace std;
using namespace System;

class Figura {
protected:
	int x, y, dx, dy, w, h;
public:
	Figura(){}
	virtual void dibujar() = 0;
	virtual void mover() = 0;
	void borrar() {
		for (int i = 0; i < h; i++) {
			Console::SetCursorPosition(x, y + i);
			for (int j = 0; j < w; j++)
				cout << " ";
		}
	}
	void validarMovimiento(int _dx, int _dy) {
		if (x + dx < 0 || x + dx + w > wWindows)
			dx = _dx;
		if (y + dy < 0 || y + dy + h > hWindows)
			dy = _dy;
		x += dx;
		y += dy;
	}
	bool colision(int ex, int ey, int ew, int eh) {
		return ex <= x + w && x <= ex + ew && ey <=  y + h && y <= ey + eh;
	}
	int getX() { return x; }
	int getY() { return y; }
	int getW() { return w; }
	int getH() { return h; }
};