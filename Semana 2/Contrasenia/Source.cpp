#include "Contrasenia.h"
#include <vector>
#include <conio.h>


void main() {
	Random r;
	int n = r.Next(5, 11);
	vector<Contrasenia> contrasenias;
	vector<bool> siFuertes;
	for (int i = 0; i < n; i++)
		contrasenias.push_back(Contrasenia(15));
	for (int i = 0; i < contrasenias.size(); i++)
		siFuertes.push_back(contrasenias[i].esSeguro());

	for (int i = 0; i < contrasenias.size(); i++)
		cout << contrasenias[i].getContra() << " -- " << siFuertes[i] << endl;

	getch();
}
