#pragma once
#define STACK_MAX 100
#include "NodoEntrega.h"
#include "stdafx.h"
#include "ListaCarrito.h"
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string.h>

class ColaEntregas
{
private:
	int size; // Establece la cantidad de elementos de la cola.
	NodoEntrega *Frente;
	NodoEntrega *Final;

	void setSize(int);
	int getSize();
	NodoEntrega *getFrente();
	NodoEntrega *getFinal();
	void setFrente(NodoEntrega *);
	void setFinal(NodoEntrega *);


public:
	ColaEntregas();
	~ColaEntregas();

	bool vacio();
	void encolar(NodoCarrito *);
	NodoCarrito * desencolar();
	NodoEntrega * frente();
	int largo();
	void mostrar();

	void cargarColaPendientes();



};

