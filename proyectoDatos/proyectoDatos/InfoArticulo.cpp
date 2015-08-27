#include "InfoArticulo.h"


InfoArticulo::InfoArticulo(){
	setCodigo ("");
	setNombre ("");
	setMarca  ("");
	setTamanio(0);
	setPrecio (0);
}
InfoArticulo::~InfoArticulo(){}


InfoArticulo::InfoArticulo(int codigoLinea, char *pcodigo, char *pnombre, char *pmarca, char * ptamanio, int pprecio){
	setCodLinea(codigoLinea);
	setCodigo(pcodigo);
	setNombre(pnombre);
	setMarca(pmarca);
	setTamanio(ptamanio);
	setPrecio(pprecio);
}


void InfoArticulo::setCodLinea(int plinea){
	this->lineaEspecifica = plinea;
}

void InfoArticulo::setCodigo(char *pcodigo){
	strcpy_s(this->codigo, pcodigo);
}

void InfoArticulo::setNombre(char *pnombre){
	strcpy_s(this->nombre, pnombre);
}

void InfoArticulo::setMarca(char *pmarca){
	strcpy_s(this->marca, pmarca);
}

void InfoArticulo::setTamanio(char * ptamanio){
	strcpy_s(this->tamanio, ptamanio);
}


void InfoArticulo::setPrecio(int pprecio){
	this->precio = pprecio;
}

int InfoArticulo::getCodlinea(){
	return this->lineaEspecifica;
}

char * InfoArticulo::getCodigo(){
	return this->codigo;
}

char * InfoArticulo::getNombre(){
	return this->nombre;
}

char * InfoArticulo::getMarca(){
	return this->marca;
}

char * InfoArticulo::getTamanio(){
	return this->tamanio;
}

int InfoArticulo::getPrecio(){
	return this->precio;
}

void InfoArticulo::convertirAChar(char *palabra, std::string palabraString) {
	palabraString.erase(palabraString.find(' '), 1); //elimina los espacios en blanco que se hacen al principio
	std::memcpy(palabra, palabraString.c_str(), palabraString.size() + 1); // convierte el string en char array
}

int InfoArticulo::covertirAEntero(char * pcodigo) {
	int num = atoi(pcodigo);
	return num;
}
