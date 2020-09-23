// pch.h: Dies ist eine vorkompilierte Headerdatei.
// Die unten aufgeführten Dateien werden nur einmal kompiliert, um die Buildleistung für zukünftige Builds zu verbessern.
// Dies wirkt sich auch auf die IntelliSense-Leistung aus, Codevervollständigung und viele Features zum Durchsuchen von Code eingeschlossen.
// Die hier aufgeführten Dateien werden jedoch ALLE neu kompiliert, wenn mindestens eine davon zwischen den Builds aktualisiert wird.
// Fügen Sie hier keine Dateien hinzu, die häufig aktualisiert werden sollen, da sich so der Leistungsvorteil ins Gegenteil verkehrt.

#ifndef PCH_H
#define PCH_H
#include <msclr\marshal_cppstd.h>
#include <iostream>

using namespace std;
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

class Matriz {
private:
	Nodo* primero;
	//Nodo* rightMost;
	//Nodo* downMost;
	int filas, columnas;
	void enlazar();
	void getCofactor(int**, int**, int, int, int);
	int determinar(int**, int);
public:
	Matriz();
	bool estaVacia();
	void agregarDerecho(int, int);
	void agregarAbajo(int, int);

	void cargarMatriz(System::String^);
	Matriz suma(Matriz);
	Matriz resta(Matriz);
	Matriz multiplicacion(Matriz);
	int determinante();
	int getFilas();
	int getColumnas();
	void sumarColumna(int);
	void sumarFila(int);
	void guardarMatriz(System::String^);
	System::String^ imprimir();
};

#endif //PCH_H
