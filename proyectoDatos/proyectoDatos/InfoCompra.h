#pragma once
#include "stdafx.h"
class InfoCompra
{
private:
	//posee el detalle por detalle de cada compra
	char pasillo[15];
	char lgeneral[15]; //linea
	char lespecifica[15]; //linea
	char producto[15];
	int cantidad;
	double monto;

public:
	InfoCompra();
	InfoCompra(char *, char *, char *, char *, int, double);
	~InfoCompra();

	void setPasillo(char *);
	void setGeneral(char *);
	void setEspecifica(char *);
	void setProducto(char *);
	void setCantidad(int);
	void setMonto(double);

	char * getPasillo();
	char * getGeneral();
	char * getEspecifica();
	char * getProducto();
	int	   getCantidad();
	double getMonto();

};

