#include "NodoEspecifica.h"



NodoEspecifica::NodoEspecifica(){
	setAnte(NULL);
	setSgte(NULL);
	setInfo(NULL);
}

NodoEspecifica::NodoEspecifica(InfoEspecifica * pinfo){
	setInfo(pinfo);
	setSgte(NULL);
	setAnte(NULL);
}

NodoEspecifica::~NodoEspecifica(){}


void NodoEspecifica::setSgte(NodoEspecifica * psgte){
	this->sgte = psgte;
}

void NodoEspecifica::setAnte(NodoEspecifica * pante){
	this->ante = pante;
}

void NodoEspecifica::setInfo(InfoEspecifica * pinfo){
	this->info = pinfo;
}

NodoEspecifica * NodoEspecifica::getSgte(){
	return this->sgte;
}

NodoEspecifica * NodoEspecifica::getAnte(){
	return this->ante;
}

InfoEspecifica * NodoEspecifica::getInfo(){
	return this->info;
}
