#pragma once
#include "stdafx.h"
#include "ListaCarrito.h"

class NodoEntrega
{
private:
	NodoCarrito * carrito;
	NodoEntrega *sgte;

public:
	NodoEntrega();
	NodoEntrega(NodoCarrito *);
	~NodoEntrega();

	void setCarrito(NodoCarrito *);
	void setSgte(NodoEntrega *);

	NodoCarrito * getCarrito();
	NodoEntrega * getSgte();

};

