
#include "GestorInventario.h"

#include "stdlib.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "ListaArticulo.h"
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

void GestorInventario::agregarArticulo(int codigoLinea, char *codigo, char *pnombre, char *pmarca, char * ptamanio, double pprecio){
	ListaArticulo *lista = new ListaArticulo();
	InfoArticulo *info = new InfoArticulo(codigoLinea, codigo,pnombre, pmarca, ptamanio, pprecio);
	lista->almacenarArticuloEnFichero(info);
}

void GestorInventario::agregarPasillo(int numero, char * codigo, char * descripcion, ListaPasillos * listap){
	InfoPasillo * info = new InfoPasillo(numero, codigo, descripcion);
	listap->agregarPasiilo(info);
	listap->insertarAcendente(info);
} 

void GestorInventario::agregarLGeneral(int numero, char * codigo, char * descripcion, ListaGenerales * listag) {
	InfoGenerales * info = new InfoGenerales(numero, codigo, descripcion);
	listag->agregarLGeneral(info);
	listag->insertarAcendente(info);
}

void GestorInventario::agregarLEspecifica(int numero, char * codigo, char * descripcion, ListaEspecifica * listae) {
	InfoEspecifica * info = new InfoEspecifica(numero, codigo, descripcion);
	listae->agregarLEspecifica(info);
	listae->insertarAcendente(info);
}
