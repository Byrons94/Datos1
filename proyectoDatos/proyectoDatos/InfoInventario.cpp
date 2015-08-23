#include "InfoInventario.h"
#include <string.h>
#include <stdlib.h>

InfoInventario::InfoInventario(){
	setCodigo("");
	setDescripcion("");
}

InfoInventario::InfoInventario(char * pcodigo, char * pdescripcion){
	setCodigo(pcodigo);
	setDescripcion(pdescripcion);
}

InfoInventario::~InfoInventario(){}


void InfoInventario::setCodigo(char *pcodigo){
	strcpy_s(this->codigo, pcodigo);
}

void InfoInventario::setDescripcion(char *pdescripcion){
	strcpy_s(this->descripcion, pdescripcion);
}

//void InfoInventario::setListaInterna(ListaInventario * plista){
//	this->listaInterna = plista;
//}

void InfoInventario::setListaArticulos(ListaArticulo * plista){
	this->listaArticulos = plista;
}

char * InfoInventario::getCodigo(){
	return this->codigo;
}

char * InfoInventario::getDescripcion(){
	return this->descripcion;
}

//ListaInventario * InfoInventario::getListaInterna(){
//	return this->listaInterna;
//}

ListaArticulo * InfoInventario::getListaArticulos(){
	return this->listaArticulos;
}

