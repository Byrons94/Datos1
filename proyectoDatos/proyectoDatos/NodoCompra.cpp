#include "NodoCompra.h"

NodoCompra::NodoCompra(){}

NodoCompra::NodoCompra(InfoCompra * pinfo){
	setLineaDetalle(pinfo);
	setSgte(NULL);
}

NodoCompra::~NodoCompra(){}

void NodoCompra::setLineaDetalle(InfoCompra * plinea){
	this->lineaDetalle = plinea;
}

void NodoCompra::setSgte(NodoCompra * psgte){
	this->sgte = psgte;
}

InfoCompra * NodoCompra::getLineaDetalle(){
	return this->lineaDetalle;
}

NodoCompra * NodoCompra::getSgte(){
	return this->sgte;
}
