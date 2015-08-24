
#include "GestorInventario.h"

#include "stdlib.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

GestorInventario::GestorInventario(){}
GestorInventario::~GestorInventario(){}


ListaArticulo* GestorInventario::cargarArticulos(){
	ListaArticulo *listaTotal = new ListaArticulo();
	listaTotal->cargarArticulos();
	return listaTotal;
}


int GestorInventario::covertirAEntero(char * pcodigo) {
	int num = atoi(pcodigo);
	return num;
}


