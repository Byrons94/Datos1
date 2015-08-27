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
	void agregarArticulo(int codigoLinea, char * codigo, char *pnombre, char * pmarca, char * ptamanio, double pprecio);
	void agregarPasillo(int, char *, char *, ListaPasillos * listap);

	void agregarLGeneral(int numero, char * codigo, char * descripcion, ListaGenerales * listap);

	void agregarLEspecifica(int numero, char * codigo, char * descripcion, ListaEspecifica * listae);


};

