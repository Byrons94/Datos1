#include "NodoArticulo.h"



NodoArticulo::NodoArticulo(){
	setSgte(NULL);
	setAnte(NULL);
	setInfo(NULL);
}

NodoArticulo::~NodoArticulo(){}

NodoArticulo::NodoArticulo(InfoArticulo * pinfo){
	setSgte(NULL);
	setAnte(NULL);
	setInfo(pinfo);
}

void NodoArticulo::setSgte(NodoArticulo * psgte){
	this->sgte = psgte;
}

void NodoArticulo::setAnte(NodoArticulo * pante){
	this->ante = pante;
}

void NodoArticulo::setInfo(InfoArticulo * pinfo){
	this->info = pinfo;
}

NodoArticulo * NodoArticulo::getSgte(){
	return this->sgte;
}

NodoArticulo * NodoArticulo::getAnte(){
	return this->ante;
}

InfoArticulo * NodoArticulo::getInfo(){
	return this->info;
}
