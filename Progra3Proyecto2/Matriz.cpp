#include "pch.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
Matriz::Matriz():filas(0), columnas(0), primero(nullptr)
{}

bool Matriz::estaVacia() {
	return primero == nullptr;
}

void Matriz::agregarDerecho(int _fila, int _valor) 
{
	Nodo* nuevo = new Nodo(_valor, nullptr, nullptr);

	if (estaVacia()) {
		primero = nuevo;
		return;
	}
	else 
	{
		Nodo* filaActual = primero;

		while (filaActual->getAbajo() != nullptr) 
		{
			filaActual = filaActual->getAbajo();
		}

		Nodo* columnaActual = filaActual;
		
		while (columnaActual->getDerecho() != nullptr) {
			columnaActual = columnaActual->getDerecho();
		}
		columnaActual->setDerecho(nuevo);
	}

}

void Matriz::agregarAbajo(int _columna, int _valor)
{
	Nodo* nuevo = new Nodo(_valor, nullptr, nullptr);

	if (estaVacia()) {
		primero = nuevo;
		return;
	}
	else
	{
		Nodo* filaActual = primero;

		while (filaActual->getAbajo() != nullptr)
		{
			filaActual = filaActual->getAbajo();
		}

		filaActual->setAbajo(nuevo);

	}
}

void Matriz::enlazar()
{
	Nodo* nuevaFila = primero;
	if (filas < 2 || columnas < 2)
		return;
	/*Nodo* actual = nuevaFila;
	Nodo* inferior = actual->getAbajo();
	actual = actual->getDerecho();
	inferior = inferior->getDerecho();*/

	while (nuevaFila->getAbajo() != nullptr)
	{
		Nodo* actual = nuevaFila;
		Nodo* inferior = actual->getAbajo();
		actual = actual->getDerecho();
		inferior = inferior->getDerecho();
		while (actual != nullptr)
		{
			actual->setAbajo(inferior);
			actual = actual->getDerecho();
			inferior = inferior->getDerecho();
		}
		nuevaFila = nuevaFila->getAbajo();
		
	}
}

void Matriz::cargarMatriz(System::String^ _nombreS)
{
	primero = nullptr;
	filas = 1;
	columnas = 0;
	string _nombreA = msclr::interop::marshal_as<string>(_nombreS);
	ifstream matrizIn(_nombreA, ios::in);

	if(!matrizIn)
	{
		cout << "Error cargando archivo";
		return;
	}

	int elemento;
	char salto=' ';
	bool cFinal = false;
	bool fFinal = false;
	int contadorC = 1;

	do 
	{
		matrizIn >> elemento;
		if (salto == '\n') 
		{
			agregarAbajo(0, elemento);
			filas++;
			contadorC = 1;
			cFinal = true;
		}
		else
		{
			contadorC++;
			if (cFinal && contadorC > columnas) {
				primero = nullptr;
				break;
			}
			agregarDerecho(0, elemento);
			if(!cFinal)
				columnas++;
		}
			
		salto = ' ';
	} while (matrizIn.get(salto));

	enlazar();
}

System::String^ Matriz::imprimir()
{
	string numeros="|  ";
	System::String^ numeroS;
	if (estaVacia()) {
		numeros = "Error en el tamano de las matrices";
		numeroS = msclr::interop::marshal_as<System::String^>(numeros);
		return numeroS;
	}

	Nodo* columnaActual;
	Nodo* filaActual = primero;
	while (filaActual != nullptr) 
	{
		columnaActual = filaActual;
		while (columnaActual != nullptr)
		{
			numeros += to_string(columnaActual->getValor());
			numeros += "  |  ";
			columnaActual = columnaActual->getDerecho();
		}
		filaActual = filaActual->getAbajo();
		if(filaActual != nullptr)
			numeros += "\n|  ";
	} 
	numeroS= msclr::interop::marshal_as<System::String^>(numeros);
	return numeroS;
}

Matriz Matriz::suma(Matriz m2)
{
	Matriz sol;
	if (this->filas != m2.getFilas() || this->columnas != m2.getColumnas())
		return sol;
	

	Nodo* columnaActual1;
	Nodo* columnaActual2;
	Nodo* filaActual1 = primero;
	Nodo* filaActual2 = m2.primero;

	bool nuevafila = false;
	while (filaActual1 != nullptr)
	{
		columnaActual1 = filaActual1;
		columnaActual2 = filaActual2;
		while (columnaActual1 != nullptr)
		{
			if (!nuevafila)
				sol.agregarDerecho(0, columnaActual1->getValor() + columnaActual2->getValor());
			else
				sol.agregarAbajo(0, columnaActual1->getValor() + columnaActual2->getValor());
			columnaActual1 = columnaActual1->getDerecho();
			columnaActual2 = columnaActual2->getDerecho();
			nuevafila = false;
		}
		filaActual1 = filaActual1->getAbajo();
		filaActual2 = filaActual2->getAbajo();
		nuevafila = true;
	}

	return sol;
}

Matriz Matriz::resta(Matriz m2)
{
	Matriz sol;
	if (this->filas != m2.getFilas() || this->columnas != m2.getColumnas())
		return sol;


	Nodo* columnaActual1;
	Nodo* columnaActual2;
	Nodo* filaActual1 = primero;
	Nodo* filaActual2 = m2.primero;

	bool nuevafila = false;
	while (filaActual1 != nullptr)
	{
		columnaActual1 = filaActual1;
		columnaActual2 = filaActual2;
		while (columnaActual1 != nullptr)
		{
			if (!nuevafila)
				sol.agregarDerecho(0, columnaActual1->getValor() - columnaActual2->getValor());
			else
				sol.agregarAbajo(0, columnaActual1->getValor() - columnaActual2->getValor());
			columnaActual1 = columnaActual1->getDerecho();
			columnaActual2 = columnaActual2->getDerecho();
			nuevafila = false;
		}
		filaActual1 = filaActual1->getAbajo();
		filaActual2 = filaActual2->getAbajo();
		nuevafila = true;
	}

	return sol;
}

Matriz Matriz::multiplicacion(Matriz m2)
{
	Matriz sol;
	if (this->columnas != m2.getFilas() && this->filas != m2.getColumnas())
		return sol;

	/*vector<vector<int>> vec;
	vector<int> newVec;*/
	
	Nodo* filaActual1 = primero;
	Nodo* filaActual2 = m2.primero;
	Nodo* columnaActual1=filaActual1;
	Nodo* columnaActual2=filaActual2;
	bool nuevafila = false;

	int suma = 0;
	for (int i = 0; i < this->filas;i++)
	{
		for (int j = 0;j < m2.getColumnas();j++) 
		{
			while (filaActual1 != nullptr)
			{
				suma += filaActual1->getValor() * columnaActual2->getValor();
				filaActual1 = filaActual1->getDerecho();
				columnaActual2 = columnaActual2->getAbajo();
			
			}
			if (nuevafila)
			{
				sol.agregarAbajo(0, suma);
				nuevafila = false;

			}
			else 
			{
				sol.agregarDerecho(0, suma);
			}
			suma = 0;
			filaActual1 = primero;
			columnaActual2 = m2.primero;
			for (int k = 0; k <= j;k++)
			{
				columnaActual2 = columnaActual2->getDerecho();
			}
			for (int k = 0; k < i;k++)
			{
				filaActual1 = filaActual1->getAbajo();
			}

		}
		nuevafila = true;
		filaActual1 = primero;
		columnaActual2 = m2.primero;
		for (int k = 0; k <= i;k++)
		{
			filaActual1 = filaActual1->getAbajo();
		}
	}

	return sol;
}

int Matriz::determinante()
{
	int det=0;

	if (filas == 2)
	{
		det = primero->getValor() * this->primero->getAbajo()->getDerecho()->getValor() - primero->getDerecho()->getValor() * primero->getAbajo()->getValor();
		return det;
	}
	else
	{
		
		Nodo* actual = primero;
		Nodo* filaActual = primero;
		Nodo* columnaActual = filaActual;
		Nodo* actual2 = primero;

		while (actual2->getDerecho() != nullptr) {
			actual2 = actual2->getDerecho();
		}
		bool nuevaFila = false;
		bool salto = true;
		int cont = 0;
		for (int i = 0; i < this->filas;i++)
		{
			Matriz aux;
			aux.primero = nullptr;
			int j = 0;
			actual = primero;
			filaActual = primero;
			columnaActual = filaActual;
			while (filaActual != nullptr)
			{
				columnaActual = filaActual;
				while (columnaActual->getDerecho() != nullptr)
				{
					if (i == j && salto)
					{
						filaActual = filaActual->getAbajo();
						columnaActual = filaActual;
						salto = false;
					}
					if (columnaActual == nullptr)
						break;
					if (nuevaFila) {
						aux.agregarAbajo(0, columnaActual->getValor());
						
						nuevaFila = false;
					}
					else {
						aux.agregarDerecho(0, columnaActual->getValor());
						
					}
					columnaActual = columnaActual->getDerecho();
				}
				if (filaActual != nullptr) {
					filaActual = filaActual->getAbajo();
					nuevaFila = true;
				}
				j++;
				salto = true;
			}
			j = 0;
			aux.filas = this->filas - 1;
			aux.columnas = this->columnas - 1;
			aux.enlazar();
			det += pow(-1, columnas + (i + 1)) * actual2->getValor() * aux.determinante();
			actual2 = actual2->getAbajo();
		}
	}

	return det;
}

void Matriz::guardarMatriz(System::String^ _nombre)
{
	string _nombreA = msclr::interop::marshal_as<string>(_nombre);
	ofstream matrizOut(_nombreA, ios::out);

	Nodo* columnaActual;
	Nodo* filaActual = primero;
	bool nuevaFila = false;
	while (filaActual != nullptr)
	{
		columnaActual = filaActual;
		while (columnaActual != nullptr)
		{
			matrizOut << columnaActual->getValor();
			if (columnaActual->getDerecho() != nullptr)
				matrizOut << " ";
			columnaActual = columnaActual->getDerecho();
		}
		filaActual = filaActual->getAbajo();
		if(filaActual!=nullptr)
			matrizOut << "\n";
	}
}
int Matriz::getFilas() {
	return filas;
}

int Matriz::getColumnas() {
	return columnas;
}

void Matriz::sumarFila(int a) {
	filas += a;
}

void Matriz::sumarColumna(int a) {
	columnas += a;
}