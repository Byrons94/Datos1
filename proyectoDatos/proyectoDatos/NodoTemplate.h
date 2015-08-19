#pragma once
#include "TInfoInventario.h"
using namespace std;

template <class T>
class NodoTemplate{
	NodoTemplate<T> *sgte;
	NodoTemplate<T> *ante;
	T *lista;

public:
	NodoTemplate();
	NodoTemplate(TInfoInventario<T> *lista);
	~NodoTemplate();

	void setSgte(NodoTemplate<T> *);
	void setAnte(NodoTemplate<T> *);
	void setLista(TInfoInventario<T> *lista);

	NodoTemplate<T> *getAnte();
	NodoTemplate<T> *getSgte();
	TInfoInventario<T> getLista();

};

