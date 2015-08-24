#include "NodoEntrega.h"



NodoEntrega::NodoEntrega()
{
}

NodoEntrega::NodoEntrega(NodoCarrito *pcarrito)
{
	setCarrito(pcarrito);
	setSgte(NULL);
}




NodoEntrega::~NodoEntrega()
{
}

void NodoEntrega::setCarrito(NodoCarrito *)
{
}

void NodoEntrega::setSgte(NodoEntrega *sgte)
{
	this->sgte = sgte;
}



NodoCarrito * NodoEntrega::getCarrito()
{
	return carrito;
}

NodoEntrega * NodoEntrega::getSgte()
{
	return this->sgte;
}
