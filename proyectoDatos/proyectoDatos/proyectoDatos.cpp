// proyectoDatos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GestorInventario.h";
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string.h>
#include "ListaArticulo.h"

int main(){
	GestorInventario *a = new GestorInventario();
	
	ListaArticulo *lista = a->cargarArticulos();
	
	a->crearProducto("3", "Condones", "Prudence", 1, 1275, lista);

	NodoArticulo *aux = lista->getCab();
	while (aux != NULL){
		cout << "Codigo: " << aux->getInfo()->getCodigo() << endl;
		cout << "Nombre: " << aux->getInfo()->getNombre() << endl;
		cout << "Marca: " << aux->getInfo()->getMarca() << endl;
		cout << "Tamanio: " << aux->getInfo()->getTamanio() << endl;
		cout << "Precio: " << aux->getInfo()->getPrecio() << endl;
		aux = aux->getSgte();
		cout << endl;
	}

	system("PAUSE");
    return 0;
}

