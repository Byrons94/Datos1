#include "NodoTemplate.h"

template<class T>
NodoTemplate<T>::NodoTemplate(){
	setSgte(NULL);
	setAnte(NULL);
	setLista(NULL);
}

template<class T>
NodoTemplate<T>::NodoTemplate(TInfoInventario<T> *lista){
	setSgte(NULL);
	setAnte(NULL);
	setLista(lista);
}

template<class T>
NodoTemplate<T>::~NodoTemplate(){}

template<class T>
void NodoTemplate<T>::setSgte(NodoTemplate<T> * pante){
	this->ante = pante;
}

template<class T>
void NodoTemplate<T>::setAnte(NodoTemplate<T> *sgte){
	this->sgte = sgte;
}

template<class T>
void NodoTemplate<T>::setLista(TInfoInventario<T> *plista){
	this->lista = plista;
}

template<class T>
 NodoTemplate<T> * NodoTemplate<T>::getAnte(){
	return this->ante;
}

template<class T>
NodoTemplate<T> * NodoTemplate<T>::getSgte(){
	return this->sgte;
}

template<class T>
TInfoInventario<T> NodoTemplate<T>::getLista(){
	return this->lista;
}
