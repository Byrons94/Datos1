#pragma once
#include "stdafx.h"
class InfoCompra
{
private:
	//posee el detalle por detalle de cada compra
	char codigoCarrito[15];
	char pasillo[15];
	char lgeneral[15]; //linea
	char lespecifica[15]; //linea
	char producto[15];
	int cantidad;
	double monto;

public:
	InfoCompra();
	InfoCompra(char *, char *, char *, char *, char *, int, double);
	InfoCompra(char * pasillo, char * general, char * especifica, char * producto, int cantidad, double monto);
	~InfoCompra();


	void setCodCarrito(char *);
	void setPasillo(char *);
	void setGeneral(char *);
	void setEspecifica(char *);
	void setProducto(char *);
	void setCantidad(int);
	void setMonto(double);

	char * getCodCarrito();
	char * getPasillo();
	char * getGeneral();
	char * getEspecifica();
	char * getProducto();
	int	   getCantidad();
	double getMonto();

};

