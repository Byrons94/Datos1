#include "NodoEntrega.h"



NodoEntrega::NodoEntrega()
{
}

NodoEntrega::NodoEntrega(InfoEntrega *pinfo)
{
	setLineaDetalle(pinfo);
	setSgte(NULL);
}


NodoEntrega::~NodoEntrega()
{
}

void NodoEntrega::setLineaDetalle(InfoEntrega *plinea)
{
	this->lineaDetalle = plinea;

}

void NodoEntrega::setSgte(NodoEntrega *sgte)
{
	this->sgte = sgte;
}

InfoEntrega * NodoEntrega::getLineaDetalle()
{
	return this->lineaDetalle;
}

NodoEntrega * NodoEntrega::getSgte()
{
	return this->sgte;
}
