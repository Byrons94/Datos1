#include "InfoCarrito.h"

InfoCarrito::InfoCarrito(){
	setCodigo("");
	setNombre("");
	setCodClie("");
	setEstado(false);
	setMonto(0); 
	setListaCompra(NULL);
}

InfoCarrito::InfoCarrito(char * pCodigo, char * pCodClie, ListaCompra * plista){
	setCodigo(pCodigo);
	setNombre("");
	setCodClie(pCodClie);
	setEstado(false);
	setMonto(0);
	setListaCompra(plista);
}

InfoCarrito::InfoCarrito(char * pCodigo, char * pNombre, char * pCodClie , bool pEntregado, 
							double pmonto, ListaCompra * plista){
	setCodigo(pCodigo);
	setNombre(pNombre);
	setCodClie(pCodClie);
	setEstado(pEntregado);
	setMonto(pmonto);
	setListaCompra(plista);
}

InfoCarrito::~InfoCarrito(){}

void InfoCarrito::setCodigo(char * pCodigo){
	strcpy_s(this->codigo, pCodigo);
}

void InfoCarrito::setNombre(char * pNombre){
	strcpy_s(this->nombre, pNombre);
}

void InfoCarrito::setCodClie(char * pCodClie){
	strcpy_s(this->codCliente, pCodClie);
}

void InfoCarrito::setEstado(bool pEstado){
	this->estado = pEstado;
}

void InfoCarrito::setMonto(double pMonto){
	this->monto = pMonto;
}

void InfoCarrito::setListaCompra(ListaCompra * pLista){
	this->lista = pLista;
}

char * InfoCarrito::getCodigo(){
	return this->codigo;
}

char * InfoCarrito::getNombre(){
	return this->nombre;
}

char * InfoCarrito::getCodClie(){
	return this->codCliente;
}

bool InfoCarrito::getEstado(){
	return this->estado;
}

double InfoCarrito::getMonto(){
	return this->monto;
}

ListaCompra * InfoCarrito::getListaCompra(){
	return this->lista;
}
