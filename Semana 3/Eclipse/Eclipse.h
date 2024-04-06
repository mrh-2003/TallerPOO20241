#pragma once
#include <iostream>
#include <string>

using namespace std;

class Eclipse
{
public:
	Eclipse();
	Eclipse(string _tipo, string _sismo, string _lluvia, string _visibilidad, string _fecha, int _hora);
	~Eclipse();
	string getString(); //MOSTRAR INFORMACION
	void setTipo(string valor);
	void setSismo(string valor);
	void setLluvia(string valor);
	void setVisibilidad(string valor);
	void setFecha(string valor);
	void setHora(int valor);

	string getTipo        ();
	string getSismo       ();
	string getLluvia      ();
	string getVisibilidad ();
	string getFecha       ();
	int getHora        ();
private:
	string tipo, sismo, lluvia, visibilidad, fecha;
	int hora;
};

Eclipse::Eclipse()
{
}

Eclipse::Eclipse(string _tipo, string _sismo, string _lluvia, string _visibilidad, string _fecha, int _hora)
{
	tipo = _tipo;
	sismo = _sismo;
	lluvia = _lluvia;
	visibilidad = _visibilidad;
	fecha = _fecha;
	hora = _hora;
}

Eclipse::~Eclipse()
{
}

string Eclipse::getString() {
	return tipo + "\t" + sismo + "\t" + lluvia + "\t" + visibilidad + "\t" + fecha + "\t" + to_string(hora);
}

void Eclipse::setTipo        (string valor){ tipo        = valor;}
void Eclipse::setSismo       (string valor){ sismo       = valor;}
void Eclipse::setLluvia      (string valor){ lluvia      = valor;}
void Eclipse::setVisibilidad (string valor){ visibilidad = valor;}
void Eclipse::setFecha       (string valor){ fecha       = valor;}
void Eclipse::setHora           (int valor){ hora        = valor;}


string Eclipse::getTipo       () {return tipo       ;}
string Eclipse::getSismo      () {return sismo      ;}
string Eclipse::getLluvia     () {return lluvia     ;}
string Eclipse::getVisibilidad() {return visibilidad;}
string Eclipse::getFecha      () {return fecha      ;}
int    Eclipse::getHora       () {return hora       ;}