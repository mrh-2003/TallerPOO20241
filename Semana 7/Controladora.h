#pragma once
#include "Casa.h"
#include "Monigote.h"
#include "Vacuna.h"
#include "Virus.h"

class Controladora {
private:
	vector<Figura *> objetos;
	Casa casa;
	Monigote personaje;
	Vacuna vacuna;
	bool vacunaActiva, llegueCasa;
	int contMov, cantVac;
public:
	Controladora() {
		int n = 3 ;
		for (int i = 0; i < n; i++)
			objetos.push_back(new Virus());
		vacunaActiva = false;
		llegueCasa = false;
		contMov = 0;
		cantVac = 0;
	}
	void gestionarTodo() {
		for (int i = 0; i < objetos.size(); i++) {
			objetos[i]->borrar();
			objetos[i]->mover();
			objetos[i]->dibujar();
		}
		casa.dibujar();
		personaje.borrar();
		personaje.mover();
		personaje.dibujar();
		if (vacunaActiva) {
			vacuna.borrar();
			vacuna.mover();
			vacuna.dibujar();
		}
	}
	void colision() {
		if (personaje.getInmune() == false) {
			for (int i = 0; i < objetos.size(); i++)
				if (objetos[i]->colision(personaje.getX(), personaje.getY(), personaje.getW(), personaje.getH())) {
					personaje.reposicionar();
					objetos[i]->borrar();
					objetos.erase(objetos.begin() + i);
				}
		}
		if (vacunaActiva) {
			if (personaje.colision(vacuna.getX(), vacuna.getY(), vacuna.getW(), vacuna.getH())) {
				vacuna.borrar();
				vacunaActiva = false;
				vacuna.reposicionar();
				personaje.setInmune(true);
			}
		}
		if (personaje.colision(casa.getX(), casa.getY(), casa.getW(), casa.getH()))
			llegueCasa = true;
	}
	bool siTerminar() {
		return personaje.getVidas() == 0 || llegueCasa; 
	}
	void jugar() {
		char tecla = NULL;
		do
		{
			tecla = NULL;
			if (!vacunaActiva && cantVac <= 5)
				if (rand() % 100 == 0) {
					vacunaActiva = true;
					cantVac++;
				}
			if (contMov == 10) {
				personaje.setInmune(false);
				contMov = 0;
			}
			if (kbhit()) {
				tecla = getch();
				if(personaje.getInmune())
					contMov++;
				personaje.setPasos();
			}
			personaje.direccion(tecla);
			gestionarTodo();
			colision();
			_sleep(100);

			Console::SetCursorPosition(0, hWindows - 2);
			cout << "  ";
			Console::SetCursorPosition(0, hWindows - 2);
			cout << contMov; //
			Console::SetCursorPosition(0,hWindows - 1);
			cout << personaje.getVidas();
		} while (!siTerminar());
		Console::Clear();
		cout << "Cantiad de pasos: " << personaje.getPasos();
		getch();
		getch();
		getch();
		getch();
	}
};