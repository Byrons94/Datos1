#include "InfoGenerales.h"

InfoGenerales::InfoGenerales(){
	setNumero(0);
	setCodigo("");
	setDescripcionn("");
	setListaEspecifica(NULL);
}

InfoGenerales::InfoGenerales(int numero, char * codigo, char * descripcion){
	setNumero(numero);
	setCodigo(codigo);
	setDescripcionn(descripcion);
	setListaEspecifica(NULL);
}

InfoGenerales::InfoGenerales(int numero, char * codigo, char * descripcion, ListaEspecifica * lista){
	setNumero(numero);
	setCodigo(codigo);
	setDescripcionn(descripcion);
	setListaEspecifica(lista);
}

InfoGenerales::~InfoGenerales(){}


void InfoGenerales::setNumero(int pnumero){
	this->numero = pnumero;
}

void InfoGenerales::setCodigo(char * pcodigo){
	strcpy_s(this->codigo, pcodigo);
}

void InfoGenerales::setDescripcionn(char * pdescripcion){
	strcpy_s(this->descripcion, pdescripcion);
}

void InfoGenerales::setListaEspecifica(ListaEspecifica * plista){
	this->lista = plista;
}

int InfoGenerales::getNumero(){
	return  this->numero;
}

char * InfoGenerales::getCodigo(){
	return this->codigo;
}

char * InfoGenerales::getDescripcion(){
	return this->descripcion;
}


ListaEspecifica * InfoGenerales::getListaEspecifica(){
	return this->lista;
}

void  InfoGenerales::cargarEspecificas() {
	ListaEspecifica * lista = new ListaEspecifica();
	int especificas = atoi(this->codigo);
	lista->cargarEspecificas(especificas);
	setListaEspecifica(lista);
}
