#include "NodoInventario.h"


NodoInventario::NodoInventario(){
	setAnte(NULL);
	setAnte(NULL);
	setInfo(NULL);
}

NodoInventario::NodoInventario(InfoInventario * pinfo){
	setAnte(NULL);
	setAnte(NULL);
	setInfo(pinfo);
}

NodoInventario::~NodoInventario(){}

void NodoInventario::setSgte(NodoInventario *psgte){
	this->sgte = psgte;
}

void NodoInventario::setAnte(NodoInventario *pante){
	this->ante = pante;
}

void NodoInventario::setInfo(InfoInventario *pinfo){
	this->info = pinfo;
}

NodoInventario * NodoInventario::getSgte(){
	return this->sgte;
}

NodoInventario * NodoInventario::getAnte(){
	return this->ante;
}

InfoInventario * NodoInventario::getInfo(){
	return this->info;
}
