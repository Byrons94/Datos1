#include "NodoGenerales.h"



NodoGenerales::NodoGenerales(){
	setSgte(NULL);
	setAnte(NULL);
	setInfoGenerales(NULL);
}

NodoGenerales::NodoGenerales(InfoGenerales * plista){
	setSgte(NULL);
	setAnte(NULL);
	setInfoGenerales(plista);
}

NodoGenerales::~NodoGenerales(){}

void NodoGenerales::setSgte(NodoGenerales * psgte){
	this->sgte = psgte;
}

void NodoGenerales::setAnte(NodoGenerales *  pante){
	this->ante = pante;
}

void NodoGenerales::setInfoGenerales(InfoGenerales * plista){
	this->infoGenerales = plista;
}

NodoGenerales * NodoGenerales::getSgte(){
	return this->sgte;
}

NodoGenerales * NodoGenerales::getAnte(){
	return this->ante;
}

InfoGenerales * NodoGenerales::getInfo(){
	return this->infoGenerales;
}
