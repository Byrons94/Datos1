#pragma once
#include "ListaArticulo.h"
#include "ListaPasillos.h"


class GestorInventario
{
public:
	GestorInventario();
	~GestorInventario();

	ListaArticulo *cargarArticulos();

	int covertirAEntero(char * );

	void agregarArticulo(int codigoLinea, char * pnombre, char * pmarca, char * ptamanio, double pprecio);

	void agregarArticulo(char * pnombre, char * pcontrasenna, int prol);

};

