#pragma once
#include "ListaArticulo.h"
#include "ListaPasillos.h"


class GestorInventario
{
public:
	GestorInventario();
	~GestorInventario();

	//Articulos
	ListaArticulo *cargarArticulos();
	ListaArticulo * leerFicheroArticulos();
	ListaPasillos * cargarPasillos();
	ListaPasillos * leerFicheroPasillos();
	void convertirAChar(char *, std::string);

	int covertirAEntero(char * pcodigo);

};

