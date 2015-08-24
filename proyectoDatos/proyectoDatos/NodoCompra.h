#pragma once
#include "InfoCompra.h"
class NodoCompra
{
private:
	InfoCompra * lineaDetalle;
	NodoCompra *sgte;


	
public:
	NodoCompra();
	NodoCompra(InfoCompra *);
	~NodoCompra();

	void setListaCompra(InfoCompra * plinea);

	void setLineaDetalle(InfoCompra * );
	void setSgte(NodoCompra *);

	InfoCompra * getLineaDetalle();
	NodoCompra * getSgte();



};

