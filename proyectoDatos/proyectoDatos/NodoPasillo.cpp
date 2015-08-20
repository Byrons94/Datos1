#include "NodoPasillo.h"


NodoPasillo::NodoPasillo(){
	setSgte(NULL);
	setAnte(NULL);
	setInfoPasillo(NULL);
}

NodoPasillo::NodoPasillo(InfoPasillo * pinfo){
	setSgte(NULL);
	setAnte(NULL);
	setInfoPasillo(pinfo);
}
NodoPasillo::~NodoPasillo(){}

void NodoPasillo::setInfoPasillo(InfoPasillo * pinfo){
	this->infoPasillo = pinfo;
}

void NodoPasillo::setSgte(NodoPasillo * psgte){
	this->sgte = psgte;
}

void NodoPasillo::setAnte(NodoPasillo * pante){
	this->ante = pante;
}

InfoPasillo * NodoPasillo::getInfoPasillo(){
	return this->infoPasillo;
}

NodoPasillo * NodoPasillo::getAnte(){
	return this->ante;
}

NodoPasillo * NodoPasillo::getSgte(){
	return this->sgte;
}

