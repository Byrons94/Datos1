#pragma once
#include "InfoEntrega.h"
#include "stdafx.h"

class NodoEntrega
{
private:
	InfoEntrega * lineaDetalle;
	NodoEntrega *sgte;

public:
	NodoEntrega();
	NodoEntrega(InfoEntrega *);
	~NodoEntrega();

	void setLineaDetalle(InfoEntrega *);
	void setSgte(NodoEntrega *);

	InfoEntrega * getLineaDetalle();
	NodoEntrega * getSgte();

};

