#include "TInfoInventario.h"

template<class T>
TInfoInventario<T>::TInfoInventario(){
	setCodigo("");
	setDescripcion("");
	setListaInterna(NULL);
}

template<class T>
TInfoInventario<T>::TInfoInventario(T * listaInterna){
	setCodigo("");
	setDescripcion("");
	setListaInterna(listaInterna);
}

template<class T>
TInfoInventario<T>::TInfoInventario(char * codigo, char * descripcion, int pjerarquia ,T * listaInterna){
	setCodigo(codigo);
	setDescripcion(descripcion);
	setListaInterna(listaInterna);
}

template<class T>
TInfoInventario<T>::~TInfoInventario()
{}

template<class T>
void TInfoInventario<T>::setJerarquia(int pjerarquia){
	this->jerarquia = pjerarquia;
}

template<class T>
void TInfoInventario<T>::setCodigo(char * pcodigo){
	strcpy_s(this->codigo, codigo);
}

template<class T>
void TInfoInventario<T>::setDescripcion(char * pdescripcion){
	strcpy_s(this->descripcion, pdescripcion);
}

template<class T>
void TInfoInventario<T>::setListaInterna(T *plista){
	this->listaInterna = plista;
}

template<class T>
int TInfoInventario<T>::getJerarquia(){
	return this->jerarquia;
}

template<class T>
char * TInfoInventario<T>::getCodigo(){
	return this->codigo;
}

template<class T>
char * TInfoInventario<T>::getDescripcion(){
	return this->descripcion;
}

template<class T>
T TInfoInventario<T>::getListaInterna(){
	return this->listaInterna;
}