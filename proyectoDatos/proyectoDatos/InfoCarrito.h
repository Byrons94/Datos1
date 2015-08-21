#pragma once
#include "ListaArticulo.h"
class InfoCarrito
{

private:
	char   codigo[15];
	char   nombre[15];
	char   codCliente[15];
	bool   estado; // false  = no entregado, true = entregado
	double monto;
	ListaArticulo * lista;

public:	
	InfoCarrito();
	InfoCarrito(char *, char *, ListaArticulo*);
	InfoCarrito(char *, char *, char*, bool, double, ListaArticulo* );
	~InfoCarrito();

	void setCodigo(char *);
	void setNombre(char *);
	void setCodClie(char *);
	void setEstado(bool);
	void setMonto(double);
	void setListaArticulo(ListaArticulo *);

	char * getCodigo();
	char * getNombre();
	char * getCodClie();
	bool   getEstado();
	double getMonto();
	ListaArticulo * getListaArticulo();

};

