#include "ColaEntregas.h"

ColaEntregas::ColaEntregas(){
	setSize(0);
	setFrente(NULL);
	setFinal(NULL);
}

ColaEntregas::~ColaEntregas()
{}

void ColaEntregas::setSize(int size){
	this->size = size;
}

int ColaEntregas::getSize(){
	return this->size;
}

NodoEntrega * ColaEntregas::getFrente(){
	return Frente;
}

NodoEntrega * ColaEntregas::getFinal(){
	return Final;
}

void ColaEntregas::setFrente(NodoEntrega *nodo){
	this->Frente = nodo;
}

void ColaEntregas::setFinal(NodoEntrega *nodo){
	this->Final = nodo;
}


bool ColaEntregas::vacio(){
	return (getFrente() == NULL);
}

void ColaEntregas::encolar(NodoCarrito * pcarrito){
	NodoEntrega *nuevo;
	nuevo = new NodoEntrega(pcarrito);
	nuevo->setSgte(NULL) ;

	if (vacio()){
		setFrente(nuevo);
		setFinal(nuevo);
	}
	else {
		getFinal()->setSgte(nuevo);
		setFinal(nuevo);
	}
	setSize(getSize() + 1);
}


NodoCarrito * ColaEntregas::desencolar(){
	if (!vacio()) {
		NodoEntrega *aux;
		aux = getFrente();
		NodoCarrito *carrito = aux->getCarrito();
		if (getSize() == 1){
			setFrente(NULL);
			setFinal(NULL);
		}
		else {
			setFrente(aux->getSgte());
		}

		InfoCarrito *info = carrito->getInfo();
		ListaCarrito *lista = new ListaCarrito();
		lista->cargarCarritosPendientes();
		lista->modificarCarrito(info);

		delete aux;
		setSize(getSize() - 1);
		return carrito;
	}
	return NULL;
}


NodoEntrega * ColaEntregas::frente(){
	return getFrente();
}

int ColaEntregas::largo(){
	return getSize();
}

void ColaEntregas::mostrar(){}


void ColaEntregas::cargarColaPendientes(){
	ListaCarrito *lista = new ListaCarrito();
	lista->cargarCarritosPendientes();
	NodoCarrito *nodo = lista->getCab();

	for (int i = 0; i < lista->getTamanio(); i++)	{
		encolar(nodo);
		nodo = nodo->getSgte();
	}
	
}

