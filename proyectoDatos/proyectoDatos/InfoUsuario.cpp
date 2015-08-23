#include "InfoUsuario.h"



InfoUsuario::InfoUsuario(){
	setCodigo("");
	setNombre("");
	setContrasenna("");
	setRol(0);
}

InfoUsuario::InfoUsuario(char * pcodigo, char * pnombre, char * pcontrasenna, int prol){
	setCodigo(pcodigo);
	setNombre(pnombre);
	setContrasenna(pcontrasenna);
	setRol(prol);
}

InfoUsuario::~InfoUsuario()
{}

void InfoUsuario::setCodigo(char * pcodigo){
	strcpy_s(this->codigo, pcodigo);
}

void InfoUsuario::setNombre(char * pNombre){
	strcpy_s(this->nombre, pNombre);
}

void InfoUsuario::setContrasenna(char * pContrasenna){
	strcpy_s(this->contrasenna, pContrasenna);
}

void InfoUsuario::setRol(int pRol){
	this->rol = pRol;
}

char * InfoUsuario::getCodigo(){
	return this->codigo;
}

char * InfoUsuario::getNombre(){
	return this->nombre;
}

char * InfoUsuario::getContrasenna(){
	return this->contrasenna;
}

int InfoUsuario::getRol(){
	return this->rol;
}
