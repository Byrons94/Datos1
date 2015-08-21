#pragma once
#include "NodoCarrito.h" 
class ListaCarrito
{
private:
	int tamanio;
	NodoCarrito * cab;



public:
	ListaCarrito();
	~ListaCarrito();

	void setTamanio(int);
	void setCab(NodoCarrito);
	int getTamanio();
	NodoCarrito getCab();


};

