#include "pch.h"
Nodo::Nodo():valor(0), nodoDerecho(nullptr), nodoAbajo(nullptr)
{}

Nodo::Nodo(int _valor, Nodo* _derecho, Nodo* _abajo): valor(_valor), nodoDerecho(_derecho), nodoAbajo(_abajo)
{}
 
int Nodo::getValor() {
	return valor;
}

Nodo* Nodo::getDerecho() {
	return nodoDerecho;
}

Nodo* Nodo::getAbajo() {
	return nodoAbajo;
}

void Nodo::setValor(int _valor) {
	valor = _valor;
}

void Nodo::setDerecho(Nodo* _derecho) {
	nodoDerecho = _derecho;
}

void Nodo::setAbajo(Nodo* _abajo) {
	nodoAbajo = _abajo;
}