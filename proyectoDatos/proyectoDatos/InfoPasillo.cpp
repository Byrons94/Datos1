#include "InfoPasillo.h"


//constructores
InfoPasillo::InfoPasillo(){
	setNumero(0);
	setCodigo("");
	setDescripcionn("");
	setListageneral(NULL);
}

InfoPasillo::InfoPasillo(int pnumero, char * pcodigo, char * pdescripcion){
	setNumero(pnumero);
	setCodigo(pcodigo);
	setDescripcionn(pdescripcion);
	setListageneral(NULL);
}

InfoPasillo::InfoPasillo(int pnumero, char * pcodigo, char * pdescripcion, ListaGenerales * plista){
	setNumero(pnumero);
	setCodigo(pcodigo);
	setDescripcionn(pdescripcion);
	setListageneral(plista);
}

//destructor
InfoPasillo::~InfoPasillo(){}

//sets
void InfoPasillo::setNumero(int pnumero){
	this->numero = pnumero;
}

void InfoPasillo::setCodigo(char * pcodigo){
	strcpy_s(this->codigo, pcodigo);
}

void InfoPasillo::setDescripcionn(char * pdescripcion){
	strcpy_s(this->descripcion, pdescripcion);
}

void InfoPasillo::setListageneral(ListaGenerales * plista){
	this->lista = plista;
}

int InfoPasillo::getNumero(){
	return this->numero;
}

char * InfoPasillo::getCodigo(){
	return this->codigo;
}

char * InfoPasillo::getDescripcion(){
	return this->descripcion;
}

ListaGenerales * InfoPasillo::getListaGeneral(){
	return this->lista;
}
