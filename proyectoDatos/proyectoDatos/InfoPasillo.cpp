#include "InfoPasillo.h"


//constructores
InfoPasillo::InfoPasillo(){
	setNumero(0);
	setCodigo("");
	setDescripcionn("");
	setListaGeneral(NULL);
}

InfoPasillo::InfoPasillo(int pnumero, char * pcodigo, char * pdescripcion){
	setNumero(pnumero);
	setCodigo(pcodigo);
	setDescripcionn(pdescripcion);
	setListaGeneral(NULL);
}

InfoPasillo::InfoPasillo(int pnumero, char * pcodigo, char * pdescripcion, ListaGenerales * plista){
	setNumero(pnumero);
	setCodigo(pcodigo);
	setDescripcionn(pdescripcion);
	setListaGeneral(plista);
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

void InfoPasillo::setListaGeneral(ListaGenerales * lista){
	this->lista = lista;
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

void  InfoPasillo::cargarGeneralesPasillo(){
	ListaGenerales * lista = new ListaGenerales();
	int codigoPasillo = atoi(this->getCodigo());
	lista->cargarGenerales(codigoPasillo);
	setListaGeneral(lista);
}
