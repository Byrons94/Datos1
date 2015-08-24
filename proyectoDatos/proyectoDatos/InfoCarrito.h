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
	int contador = 0;

public:	
	InfoCarrito();
	InfoCarrito(char *, char *, ListaCompra*);
	InfoCarrito(char *, char *, char*, bool, double, ListaCompra* );
	InfoCarrito::InfoCarrito(char * pNombre, char * pCodClie, bool pEntregado,
		double pmonto, ListaCompra * plista);
	~InfoCarrito();

	void setCodigo(char *);
	void setNombre(char *);
	void setCodClie(char *);
	void setEstado(bool);
	void setMonto(double);
	void setListaCompra(ListaCompra * );

	char * autoIncrementar();

	char * getCodigo();
	char * getNombre();
	char * getCodClie();
	bool   getEstado();
	double getMonto();
	ListaCompra * getListaCompra();

	int ultimoRegistro();

	void convertirAChar(char * palabra, std::string palabraString);

	int covertirAEntero(char * pcodigo);


};

