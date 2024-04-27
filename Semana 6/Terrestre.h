#pragma once
#include <iostream>
#include <conio.h>
#include <vector>

#define wWindows 100
#define hWindows 30

using namespace std;
using namespace System;

class Terrestre
{
protected:
	int x, y, dx, dy, w, h;
public:
	Terrestre() {

	}
	~Terrestre() {}
	void mover() {
		if (x + dx < 0 || x + dx + w > wWindows)
			dx = -dx;
		if (y + dy < 0 || y + dy + h > hWindows)
			dy = -dy;
		x += dx;
		y += dy;
	}
	void borrar() {
		for (int i = 0; i < h; i++) {
			Console::SetCursorPosition(x, y + i);
			for (int j = 0; j < w; j++)
				cout << " ";
		}
	}
	void dibujar(){}
	bool colision(int ex, int ey, int ew, int eh) {
		return x <= ex + ew && ex <= x + w && y <= ey + eh && ey <= y + h;
	}
};
