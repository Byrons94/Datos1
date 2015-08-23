#include "InfoCompra.h"


InfoCompra::InfoCompra(){
	setPasillo("");
	setGeneral("");
	setEspecifica("");
	setProducto("");
	setCantidad(0);
	setMonto(0);
}


InfoCompra::InfoCompra(char * codCarrito, char * pasillo, char *general, char *especifica, char *producto, int cantidad, double monto){
	setCodCarrito(codCarrito);
	setPasillo(pasillo);
	setGeneral(general);
	setEspecifica(especifica);
	setProducto(producto);
	setCantidad(cantidad);
	setMonto(monto);
}

InfoCompra::InfoCompra(char * pasillo, char *general, char *especifica, char *producto, int cantidad, double monto) {
	setCodCarrito("");
	setPasillo(pasillo);
	setGeneral(general);
	setEspecifica(especifica);
	setProducto(producto);
	setCantidad(cantidad);
	setMonto(monto);
}

InfoCompra::~InfoCompra()
{}

void InfoCompra::setCodCarrito(char * pcod){
	strcpy_s(this->codigoCarrito, pcod);
}

void InfoCompra::setPasillo(char *ppasillo){
	strcpy_s(this->pasillo, ppasillo);
}

void InfoCompra::setGeneral(char * pgeneral){
	strcpy_s(this->lgeneral, pgeneral);
}

void InfoCompra::setEspecifica(char * pespecifica){
	strcpy_s(this->lespecifica, pespecifica);
}

void InfoCompra::setProducto(char * pporducto){
	strcpy_s(this->producto, pporducto);
}

void InfoCompra::setCantidad(int pcantidad){
	this->cantidad = pcantidad;
}

void InfoCompra::setMonto(double pmonto){
	this->monto = pmonto;
}


char * InfoCompra::getCodCarrito(){
	return this->codigoCarrito;
}

char * InfoCompra::getPasillo(){
	return this->pasillo;
}

char * InfoCompra::getGeneral(){
	return this->lgeneral;
}

char * InfoCompra::getEspecifica(){
	return this->lespecifica;
}

char * InfoCompra::getProducto(){
	return this->producto;
}

int InfoCompra::getCantidad(){
	return this->cantidad;
}

double InfoCompra::getMonto(){
	return this->monto;
}
