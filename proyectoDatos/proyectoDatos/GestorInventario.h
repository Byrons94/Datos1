#pragma once
#include "ListaArticulo.h"
class GestorInventario
{
public:
	GestorInventario();
	~GestorInventario();

	ListaArticulo *cargarArticulos();

	ListaArticulo * leerFichero();

	int crearProducto(char *, char *, char *, double, double, ListaArticulo *);
	bool almacenarArticuloEnFichero(InfoArticulo *);
	void convertirAChar(char *, string);
};

