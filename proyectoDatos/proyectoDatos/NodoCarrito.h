#pragma once
#include "InfoCarrito.h"

class NodoCarrito
{
	NodoCarrito  * sgte;
	NodoCarrito  * ante;
	InfoCarrito * info;

public:
	NodoCarrito();
	NodoCarrito(InfoCarrito* info);
	~NodoCarrito();

	void setSgte(NodoCarrito *);
	void setAnte(NodoCarrito *);
	void setInfo(InfoCarrito *);

	NodoCarrito * getSgte();
	NodoCarrito * getAnte();
	InfoCarrito * getInfo();

};

