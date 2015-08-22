// proyectoDatos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GestorInventario.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
#include "ListaArticulo.h"
#include "ListaCarrito.h"


void mostrarElementos() {
	GestorInventario *a = new GestorInventario();

	ListaPasillos * lista = new ListaPasillos();
	lista->cargarPasillos();

	NodoPasillo * aux = lista->getCab();

	while (aux != NULL) {
		cout << "Pasillo: " << aux->getInfoPasillo()->getNumero() << endl;
		//cout << "Codigo: " << aux->getInfoPasillo()->getCodigo() << endl;
		cout << "Nombre: " << aux->getInfoPasillo()->getDescripcion() << endl;

		NodoGenerales * nodo = aux->getInfoPasillo()->getListaGeneral()->getCab();
		//cout << "Lineas generales: " << endl;
		while (nodo != NULL) {
			cout << "  -" << nodo->getInfo()->getDescripcion() << endl;

			NodoEspecifica * especifica = nodo->getInfo()->getListaGeneral()->getCab();

			while (especifica != NULL) {
				cout << "       *" << especifica->getInfo()->getDescripcion() << endl;

				NodoArticulo * articulo = especifica->getInfo()->getListaArticulos()->getCab();
				while (articulo != NULL) {
					cout << "             ->" << articulo->getInfo()->getNombre() << "-----" << articulo->getInfo()->getMarca() << endl;
					articulo = articulo->getSgte();
				}

				especifica = especifica->getSgte();
			}

			nodo = nodo->getSgte();
		}
		cout << endl;
		aux = aux->getSgte();
	}

	/*ListaArticulo *lista = a->cargarArticulos();
	cout <<  lista->agregar("030", "perrito", "Tio pelon", 45, 2000, lista) << endl;

	NodoArticulo *aux = lista->getCab();
	while (aux != NULL){
	cout << "Codigo: " << aux->getInfo()->getCodigo() << endl;
	cout << "Nombre: " << aux->getInfo()->getNombre() << endl;
	cout << "Marca: " << aux->getInfo()->getMarca() << endl;
	cout << "Tamanio: " << aux->getInfo()->getTamanio() << endl;
	cout << "Precio: " << aux->getInfo()->getPrecio() << endl;
	aux = aux->getSgte();
	cout << endl;
	}*/

	system("PAUSE");
}


void mostrarCarrito() {
	ListaCarrito *carrito = new ListaCarrito();
	ListaCompra * lista = new ListaCompra();
	lista->agregarProducto(new InfoCompra("1", "1", "1", "1", 5, 5000));
	lista->agregarProducto(new InfoCompra("2", "2", "2", "2", 8, 8000));
	lista->agregarProducto(new InfoCompra("3", "3", "3", "3", 3, 3500));
	
	carrito->agregarListaCompra(lista);
	//InfoCarrito * infoCarrito = new InfoCarrito();
	//infoCarrito->setListaCompra(lista);
	


	/*char * pasillo, char *general, char *especifica, 
		char *producto, int cantidad, double monto*/
	system("PAUSE");
}

int main(){
	//mostrarElementos();


    return 0;
}

