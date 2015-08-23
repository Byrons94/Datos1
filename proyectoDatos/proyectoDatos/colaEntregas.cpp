#include "ColaEntregas.h"
#include "NodoEntrega.h"


ColaEntregas::ColaEntregas()
{
	setSize(0);
	setFrente(NULL);
	setFinal(NULL);

}

ColaEntregas::~ColaEntregas()
{
}

void ColaEntregas::setSize(int size)
{
	this->size = size;
}

int ColaEntregas::getSize()
{
	return this->size;
}

NodoEntrega * ColaEntregas::getFrente()
{
	return Frente;
}

NodoEntrega * ColaEntregas::getFinal()
{
	return Final;
}

void ColaEntregas::setFrente(NodoEntrega *nodo)
{
	this->Frente = nodo;
}

void ColaEntregas::setFinal(NodoEntrega *nodo)
{
	this->Final = nodo;
}





bool ColaEntregas::vacio()
{
	return (getFrente() == NULL);
		
}

void ColaEntregas::encolar(InfoEntrega * pinfo)
{

	NodoEntrega *nuevo;
	nuevo = new NodoEntrega(pinfo);
	nuevo->setSgte(NULL) ;

	if (vacio())
	{
		setFrente(nuevo);
		setFinal(nuevo);
	}
	else {
		getFinal()->setSgte(nuevo);

		setFinal(nuevo);
	}
	setSize(getSize() + 1);
}

InfoEntrega * ColaEntregas::desencolar()
{
	if (!vacio()) {
		NodoEntrega *aux;
		aux = getFrente();
		InfoEntrega *info = aux->getLineaDetalle();
		if (getSize() == 1){
			setFrente(NULL);
			setFinal(NULL);
		}
		else {
			setFrente(aux->getSgte());
		}
		delete aux;
		setSize(getSize() - 1);
		return info;
	}

	return NULL;
}




NodoEntrega * ColaEntregas::frente()
{
	return getFrente();
}

int ColaEntregas::largo()
{
	return getSize();
}

void ColaEntregas::mostrar()
{
}

