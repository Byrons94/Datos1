#include "InfoEntrega.h"

InfoEntrega::InfoEntrega() {
	setPasillo("");
	setGeneral("");
	setEspecifica("");
	setProducto("");
	setCantidad(0);
	setMonto(0);
}


InfoEntrega::InfoEntrega(char * codCarrito, char * pasillo, char *general, char *especifica, char *producto, int cantidad, double monto) {
	setCodCarrito(codCarrito);
	setPasillo(pasillo);
	setGeneral(general);
	setEspecifica(especifica);
	setProducto(producto);
	setCantidad(cantidad);
	setMonto(monto);
}

InfoEntrega::InfoEntrega(char * pasillo, char *general, char *especifica, char *producto, int cantidad, double monto) {
	setCodCarrito("");
	setPasillo(pasillo);
	setGeneral(general);
	setEspecifica(especifica);
	setProducto(producto);
	setCantidad(cantidad);
	setMonto(monto);
}


void InfoEntrega::setCodCarrito(char * pcod) {
	strcpy_s(this->codigoCarrito, pcod);
}

void InfoEntrega::setPasillo(char *ppasillo) {
	strcpy_s(this->pasillo, ppasillo);
}

void InfoEntrega::setGeneral(char * pgeneral) {
	strcpy_s(this->lgeneral, pgeneral);
}

void InfoEntrega::setEspecifica(char * pespecifica) {
	strcpy_s(this->lespecifica, pespecifica);
}

void InfoEntrega::setProducto(char * pporducto) {
	strcpy_s(this->producto, pporducto);
}

void InfoEntrega::setCantidad(int pcantidad) {
	this->cantidad = pcantidad;
}

void InfoEntrega::setMonto(double pmonto) {
	this->monto = pmonto;
}


char * InfoEntrega::getCodCarrito() {
	return this->codigoCarrito;
}

char * InfoEntrega::getPasillo() {
	return this->pasillo;
}

char * InfoEntrega::getGeneral() {
	return this->lgeneral;
}

char * InfoEntrega::getEspecifica() {
	return this->lespecifica;
}

char * InfoEntrega::getProducto() {
	return this->producto;
}

int InfoEntrega::getCantidad() {
	return this->cantidad;
}

double InfoEntrega::getMonto() {
	return this->monto;
}





InfoEntrega::~InfoEntrega()
{
}
