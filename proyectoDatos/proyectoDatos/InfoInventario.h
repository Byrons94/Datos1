#pragma once
#include "ListaArticulo.h"


class InfoInventario{
private:
	char codigo[15];
	char descripcion[50];
	ListaArticulo * listaArticulos;

	//ListaInventario * listaInterna;

public:
	InfoInventario();
	InfoInventario(char*, char*);
	~InfoInventario();

	void setCodigo(char *);
	void setDescripcion(char *);
	//void setListaInterna(ListaInventario *);
	void setListaArticulos(ListaArticulo *);

	char *getCodigo();
	char *getDescripcion();
	//ListaInventario * getListaInterna();
	ListaArticulo *getListaArticulos();
};

