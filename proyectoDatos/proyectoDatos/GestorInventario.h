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

};

