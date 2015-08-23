#include "ListaTInventario.h"

template<class T>
ListaTInventario<T>::ListaTInventario(){
	setTamanio(0);
	setCab(NULL);
}

template<class T>
ListaTInventario<T>::ListaTInventario(NodoTemplate<T> * pnodo){
	setTamanio(0);
	setCab(pnodo);
}

template<class T>
ListaTInventario<T>::~ListaTInventario(){}

template<class T>
void ListaTInventario<T>::setCab(NodoTemplate<T>* nodoCab){
	this->cab = nodoCab;
}

template<class T>
void ListaTInventario<T>::setTamanio(int ptamanio){
	this->tamanio = ptamanio;
}

template<class T>
NodoTemplate<T>* ListaTInventario<T>::getCab(){
	return this->cab;
}

template<class T>
int ListaTInventario<T>::getTamanio(){
	return this->tamanio;
}

template<class T>
NodoTemplate<T>* ListaTInventario<T>::DirNodo(char * pcodigo){
	return nullptr;
}

template<class T>
bool ListaTInventario<T>::Agregar(TInfoInventario<T>* pInfo){
	return false;
}

template<class T>
bool ListaTInventario<T>::Eliminar(char * pcodigo){
	return false;
}

template<class T>
bool ListaTInventario<T>::Modificar(TInfoInventario<T>* pInfo){
	return false;
}

template<class T>
void ListaTInventario<T>::DesplegarListaArticulos(){
}

