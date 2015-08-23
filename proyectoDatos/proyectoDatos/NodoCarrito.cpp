#include "NodoCarrito.h"

//constructor
NodoCarrito::NodoCarrito(){
	setSgte(NULL);
	setAnte(NULL);
	setInfo(NULL);
}

NodoCarrito::NodoCarrito(InfoCarrito * info){
	setSgte(NULL);
	setAnte(NULL);
	setInfo(info);
}

//destructor
NodoCarrito::~NodoCarrito(){}

void NodoCarrito::setSgte(NodoCarrito * pSgte){
	this->sgte = pSgte;
}

void NodoCarrito::setAnte(NodoCarrito * pante){
	this->ante = pante;
}

void NodoCarrito::setInfo(InfoCarrito * pLista){
	this->info = pLista;
}

NodoCarrito * NodoCarrito::getSgte(){
	return this->sgte;
}

NodoCarrito * NodoCarrito::getAnte(){
	return this->ante;
}

InfoCarrito * NodoCarrito::getInfo(){
	return this->info;
}
