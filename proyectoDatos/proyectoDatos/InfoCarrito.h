#pragma once
#include "ListaCompra.h"
class InfoCarrito
{

private:
	char   codigo[15];
	char   nombre[15];
	char   codCliente[15];
	bool   estado; // false  = no entregado, true = entregado
	double monto;
	ListaCompra * lista;

public:	
	InfoCarrito();
	InfoCarrito(char *, char *, ListaCompra*);
	InfoCarrito(char *, char *, char*, bool, double, ListaCompra* );
	~InfoCarrito();

	void setCodigo(char *);
	void setNombre(char *);
	void setCodClie(char *);
	void setEstado(bool);
	void setMonto(double);
	void setListaCompra(ListaCompra * );


	char * getCodigo();
	char * getNombre();
	char * getCodClie();
	bool   getEstado();
	double getMonto();
	ListaCompra * getListaCompra();


};

