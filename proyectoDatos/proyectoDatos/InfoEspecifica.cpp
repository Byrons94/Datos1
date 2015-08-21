#include "InfoEspecifica.h"



InfoEspecifica::InfoEspecifica(){
	setNumero(0);
	setCodigo("");
	setDescripcion("");
	setListaArticulos(NULL);
}

InfoEspecifica::InfoEspecifica(int pnumero, char * pcodigo, char * pdescripcion) {
	setNumero(pnumero);
	setCodigo(pcodigo);
	setDescripcion(pdescripcion);
	setListaArticulos(NULL);
}

InfoEspecifica::InfoEspecifica(int pnumero, char * pcodigo, char * pdescripcion, ListaArticulo * plista){
	setNumero(pnumero);
	setCodigo(pcodigo);
	setDescripcion(pdescripcion);
	setListaArticulos(plista);
}

InfoEspecifica::~InfoEspecifica(){}


void InfoEspecifica::setNumero(int pnumero){
	this->numero = pnumero;
}

void InfoEspecifica::setCodigo(char * pcodigo){
	strcpy_s(this->codigo, pcodigo);
}

void InfoEspecifica::setDescripcion(char * pdescripcion){
	strcpy_s(this->descripcion, pdescripcion);
}

void InfoEspecifica::setListaArticulos(ListaArticulo * plista){
	this->lista = plista;
}

int InfoEspecifica::getNumero(){
	return this->numero;
}

char * InfoEspecifica::getCodigo(){
	return this->codigo;
}

char * InfoEspecifica::getDescripcion(){
	return this->descripcion;
}

ListaArticulo * InfoEspecifica::getListaArticulos(){
	return this->lista;
}
