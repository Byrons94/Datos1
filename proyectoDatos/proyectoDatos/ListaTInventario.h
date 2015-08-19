#pragma once
#include "NodoTemplate.h"
template <class T>
class ListaTInventario
{
	NodoTemplate<T> *cab;
	int tamanio;

public:
	ListaTInventario();
	~ListaTInventario();

	void setCab(NodoTemplate<T> *);
	void setTamanio(int);
	NodoTemplate<T> * getCab();
	int getTamanio();

	NodoTemplate<T> * DirNodo(char *);

	bool Agregar(TInfoInventario<T> *);
	bool Eliminar(char  *);
	bool Modificar(TInfoInventario<T> *);

	void DesplegarListaArticulos();

};

