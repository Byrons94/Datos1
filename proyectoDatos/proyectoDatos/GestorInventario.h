#pragma once
#include "ListaArticulo.h"
#include "ListaTInventario.h"
#include "NodoTemplate.h"

class GestorInventario
{
public:
	GestorInventario();
	~GestorInventario();

	//Articulos
	ListaArticulo *cargarArticulos();
	ListaArticulo * leerFichero();
	int crearProducto(char *, char *, char *, double, double, ListaArticulo *);
	bool almacenarArticuloEnFichero(InfoArticulo *);
	void convertirAChar(char *, string);

	//Inventario
	int crearJerarquia(int, char*, char* );
	bool alamacenarJerarquiaEnFichero(TInfoInventario<ListaArticulo> * info);


};

