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
	int x, y, dx, dy, w, h, tipo;
public:
	Terrestre() {
	}
	~Terrestre() {}
	void mover(int ndx, int ndy) {
		if (x + dx < 0 || x + dx + w > wWindows)
			dx = ndx;
		if (y + dy < 0 || y + dy + h > hWindows)
			dy = ndy;
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
	virtual void dibujar(){}
	bool colision(int ex, int ey, int ew, int eh) {
		return x <= ex + ew && ex <= x + w && y <= ey + eh && ey <= y + h;
	}
	virtual void validarMovimiento() {
		mover(0, 0);
	}

	virtual void generarMovimiento() {
		validarMovimiento();
	}

	int getX() { return x;  }
	int getY() { return y;  }
	int getW() { return w;  }
	int getH() { return h;  }
	int getTipo() { return tipo; }
	int getDX() { return dx; }
};
