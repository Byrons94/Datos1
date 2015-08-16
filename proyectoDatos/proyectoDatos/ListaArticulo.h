#pragma once
#include "NodoArticulo.h" 
#include "stdafx.h"

class ListaArticulo
{

private:
	NodoArticulo *cab;
	int tamanio;

public:
	ListaArticulo();
	~ListaArticulo();

	void setCab(NodoArticulo *);
	void setTamanio(int);
	NodoArticulo * getCab();
	int getTamanio();

	NodoArticulo * DirNodo(char *);
	
	bool Agregar(InfoArticulo *);
	bool Eliminar(char  *);
	bool Modificar(InfoArticulo*);

	void DesplegarListaArticulos();
	
};

