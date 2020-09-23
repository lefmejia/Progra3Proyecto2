#pragma once
#ifndef MATRIZ_H
#define MATRIZ_H
#include "pch.h"
#include "Nodo.h"

class Matriz {
private:
	Nodo* primero;
	//Nodo* rightMost;
	//Nodo* downMost;
	int filas, columnas;

public:
	Matriz();
	bool estaVacia();
	void agregarDerecho(int, int);
	void agregarAbajo(int, int);
	void cargarMatriz(const char*);
};
#endif // !MATRIZ_H
