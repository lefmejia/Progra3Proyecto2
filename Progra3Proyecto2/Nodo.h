#pragma once
#ifndef NODO_H
#define NODO_H
class Nodo {

private:
	int valor;
	Nodo* nodoDerecho;
	Nodo* nodoAbajo;

public:
	Nodo();
	Nodo(int, Nodo*, Nodo*);

	int getValor();
	Nodo* getDerecho();
	Nodo* getAbajo();

	void setValor(int);
	void setDerecho(Nodo*);
	void setAbajo(Nodo*);
};
#endif // !NODO_H
