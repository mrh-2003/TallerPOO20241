#include <iostream>
#include "Raton.h"

using namespace std;

void main() {

	Raton perez;
	
	while (true)
	{
		perez.borrar();
		perez.mover();
		perez.dibujar();
		_sleep(100);
	}
}