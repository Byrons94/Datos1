
#include "GestorInventario.h"

#include "stdlib.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "InfoArticulo.h"

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

void GestorInventario::agregarArticulo(int codigoLinea, char *pnombre, char *pmarca, char * ptamanio, double pprecio)
{
	ListaArticulo *lista = new ListaArticulo();
	InfoArticulo *info = new InfoArticulo(codigoLinea, pnombre, pmarca, ptamanio, pprecio);
	lista->almacenarArticuloEnFichero(info);
}
