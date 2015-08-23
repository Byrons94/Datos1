#include "NodoUsuario.h"


NodoUsuario::NodoUsuario(){	
	setSgte(NULL);
	setInfo(NULL);
}

NodoUsuario::NodoUsuario(InfoUsuario * pInfo){
	setSgte(NULL);
	setInfo(pInfo);
}

NodoUsuario::~NodoUsuario(){}

void NodoUsuario::setSgte(NodoUsuario * pSgte){
	this->sgte = pSgte;
}

void NodoUsuario::setInfo(InfoUsuario * pInfo){
	this->info = pInfo;
}

NodoUsuario * NodoUsuario::getSgte(){
	return this->sgte;
}

InfoUsuario * NodoUsuario::getInfo(){
	return this->info;
}
