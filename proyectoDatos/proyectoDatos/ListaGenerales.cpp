#include "ListaGenerales.h"


NodoGenerales * ListaGenerales::dirNodo(char * pcodigo) {
	NodoGenerales * nodo = getCab();
	while (nodo != nullptr && strcmp(pcodigo, dirCodigoDePasillo(nodo)) != 0) {
		nodo = nodo->getSgte();
	}
	return nodo;
}


NodoGenerales * ListaGenerales::dirUltimo() {
	NodoGenerales *nodo = getCab();
	for (int i = 0; i < getTamanio(); i++)
		nodo = nodo->getSgte();

	return nodo;
}


NodoGenerales * ListaGenerales::dirAnterior(char * pcodigo) {
	NodoGenerales * nodo = dirNodo(pcodigo);

	return nodo != NULL ? nodo->getAnte() : NULL;
}


NodoGenerales * ListaGenerales::dirIndex(int pindex) {
	NodoGenerales * nodo = getCab();
	for (int i = 0; i < pindex; i++)
		nodo = nodo->getSgte();

	return nodo;
}

char * ListaGenerales::dirCodigoDePasillo(NodoGenerales * nodo) {
	return nodo->getInfo()->getCodigo();
}

void ListaGenerales::agregarNodoDespuesDe(NodoGenerales * nuevo, NodoGenerales * nodo) {
	if (nodo->getSgte() != NULL) {
		nodo->getSgte()->setAnte(nuevo);
	}
	nuevo->setSgte(nodo->getSgte());
	nuevo->setAnte(nodo);
	nodo->setSgte(nuevo);

	++tamanio;
}

void ListaGenerales::agregarNodoAntesDe(NodoGenerales * nuevo, NodoGenerales * nodo) {

	if (nodo->getAnte() != NULL)
	{
		nodo->getAnte()->setSgte(nuevo);
		nuevo->setSgte(nodo->getAnte());
	}
	else
		setCab(nuevo);

	nuevo->setSgte(nodo);
	nodo->setAnte(nuevo);

	++tamanio;
}

int ListaGenerales::convertirAEntero(char * pcodigo) {
	int num = atoi(pcodigo);
	return num;
}

//constructores
ListaGenerales::ListaGenerales() {
	setCab(NULL);
	setTamanio(0);
}

ListaGenerales::~ListaGenerales() {}


void ListaGenerales::setCab(NodoGenerales * pnodo) {
	this->cab = pnodo;
}
void ListaGenerales::setTamanio(int ptamanio) {
	this->tamanio = ptamanio;
}

NodoGenerales * ListaGenerales::getCab() {
	return this->cab;
}

int ListaGenerales::getTamanio() {
	return this->tamanio;
}

bool ListaGenerales::elimina(char * pcodigo) {
	NodoGenerales *nodo = dirNodo(pcodigo);
	if (nodo != NULL) {
		eliminarNodo(nodo);
		return true;
	}
	else
		return false;
}

bool ListaGenerales::eliminarIndex(int pindex) {
	if (getTamanio() >= pindex - 1) {
		NodoGenerales * nodo = getCab();
		for (int i = 0; i < pindex; i++) {
			nodo = nodo->getSgte();
		}
		eliminarNodo(nodo);
		return true;
	}
	else
		return false;
}

void ListaGenerales::vaciar() {
	NodoGenerales * nodo = getCab();
	if (nodo != NULL) {
		NodoGenerales *temp = nodo;
		nodo = nodo->getSgte();
		delete(temp);
	}
	setCab(NULL);
	setTamanio(0);
}

void ListaGenerales::eliminarNodo(NodoGenerales * pnodo) {
	if (pnodo->getSgte() != NULL) {
		pnodo->getSgte()->setAnte(pnodo->getAnte());
	}if (pnodo->getAnte() != NULL) {
		pnodo->getAnte()->setSgte(pnodo->getSgte());
	}
	else {
		setCab(pnodo->getSgte());
	}
	delete(pnodo);
	--tamanio;
}

InfoGenerales * ListaGenerales::obtenerDato(char * pcodigo) {
	NodoGenerales * nodo = dirNodo(pcodigo);
	return nodo != NULL ? nodo->getInfo() : NULL;
}

InfoGenerales * ListaGenerales::obtenerPorIndex(int pindex) {
	if (pindex - 1 <= getTamanio()) {
		return dirIndex(pindex)->getInfo();
	}
	else
		return NULL;
}

bool ListaGenerales::estaVacia() {
	return cab == NULL;
}

bool ListaGenerales::modificarDatos(char * codigo, InfoGenerales * info) {
	NodoGenerales * nodo = dirNodo(codigo);
	if (nodo != NULL) {
		nodo->setInfoGenerales(info);
		return true;
	}
	return false;
}

void ListaGenerales::insetarInicio(InfoGenerales * pinfo) {
	NodoGenerales * nodo = new NodoGenerales(pinfo);
	if (!estaVacia()) {
		getCab()->setAnte(nodo);
		nodo->setSgte(getCab());
	}
	setCab(nodo);

	tamanio++;
}

void ListaGenerales::insertarFinal(InfoGenerales * pinfo) {
	NodoGenerales * nodo = new NodoGenerales(pinfo);
	if (estaVacia()) {
		setCab(nodo);
	}
	else {
		NodoGenerales * ultimo = dirUltimo();
		nodo->setAnte(ultimo);
		ultimo->setSgte(nodo);
	}
	tamanio++;
}

bool ListaGenerales::insertarAntesDe(InfoGenerales * pinfo, char * pcodigo) {
	NodoGenerales *aux = dirNodo(pcodigo);
	bool existe = aux != NULL;
	if (existe) {
		NodoGenerales *nodo = new NodoGenerales(pinfo);
		agregarNodoAntesDe(nodo, aux);
	}
	return existe;
}

bool ListaGenerales::insertarDespuesDe(InfoGenerales * pinfo, char * pcodigo) {
	NodoGenerales *aux = dirNodo(pcodigo);
	bool existe = aux != NULL;
	if (existe) {
		NodoGenerales *nodo = new NodoGenerales(pinfo);
		agregarNodoDespuesDe(nodo, aux);
	}
	return existe;
}

bool ListaGenerales::insertarAcendente(InfoGenerales * pinfo) {
	NodoGenerales * temp = new NodoGenerales(pinfo);
	NodoGenerales * nodo = getCab();
	if (nodo == NULL || convertirAEntero(pinfo->getCodigo()) < convertirAEntero(nodo->getInfo()->getCodigo())) {
		insetarInicio(pinfo);
	}
	else {
		bool existe = false;
		while (nodo->getSgte() != NULL && convertirAEntero(pinfo->getCodigo()) >= convertirAEntero(nodo->getSgte()->getInfo()->getCodigo())) {
			existe = (convertirAEntero(pinfo->getCodigo()) == convertirAEntero(nodo->getInfo()->getCodigo()));
			nodo = nodo->getSgte();
		}
		if (!existe){
			agregarNodoDespuesDe(temp, nodo);
			return true;
		}
	}
	return false;
}


bool ListaGenerales::insertarDecendente(InfoGenerales * pinfo) {
	NodoGenerales * temp = new NodoGenerales(pinfo);
	NodoGenerales * nodo = getCab();
	if (nodo == NULL || convertirAEntero(pinfo->getCodigo()) > convertirAEntero(nodo->getInfo()->getCodigo())) {
		insetarInicio(pinfo);
	}
	else {
		bool existe = false;
		while (nodo->getSgte() != NULL && convertirAEntero(pinfo->getCodigo()) < convertirAEntero(nodo->getSgte()->getInfo()->getCodigo())) {
			existe = (convertirAEntero(pinfo->getCodigo()) == convertirAEntero(nodo->getInfo()->getCodigo()));
			nodo = nodo->getSgte();
		}
		if (!existe) {
			agregarNodoDespuesDe(temp, nodo);
			return true;
		}
	}
	return false;
}

void ListaGenerales::cargarGenerales(int numPasillo) {
	leerFicheroGenerales(numPasillo);
}

int ListaGenerales::leerFicheroGenerales(int numPasillo) {
	std::ifstream lectura;
	char numero[3], codigo[15], descripcion[30];

	lectura.open("Ficheros/generales.txt", std::ios::out | std::ios::in);
	InfoGenerales *lineaGeneral;

	if (lectura.is_open()) {
		lectura >> numero;  //primer registro de la linea
		std::string linea;		//contador de las lineas del documento

		while (getline(lectura, linea)) {
			std::stringstream ss(linea); //nos da un el elemento por linea
			std::string palabraString;   // lo definimos para almacenar el dato del txt

			std::string str(numero);
			str.erase(str.find(";"));
			strcpy_s(numero, str.c_str());

			getline(ss, palabraString, ';');
			convertirAChar(codigo, palabraString);

			getline(ss, palabraString, ';');
			convertirAChar(descripcion, palabraString);

			if(covertirAEntero(numero) == numPasillo){
				lineaGeneral = new InfoGenerales(covertirAEntero(numero), codigo, descripcion);
				insertarAcendente(lineaGeneral); 
				 lineaGeneral->cargarEspecificas();
			}
			lectura >> numero;
		}
		lectura.close();
		return 1;
	}
	else {
		return 0;
	}
}


int ListaGenerales::leerFicheroGenerales(){
	std::ifstream lectura;
	char numero[3], codigo[15], descripcion[30];

	lectura.open("Ficheros/generales.txt", std::ios::out | std::ios::in);
	InfoGenerales *lineaGeneral;

	if (lectura.is_open()) {
		lectura >> numero;  //primer registro de la linea
		std::string linea;		//contador de las lineas del documento

		while (getline(lectura, linea)) {
			std::stringstream ss(linea); //nos da un el elemento por linea
			std::string palabraString;   // lo definimos para almacenar el dato del txt

			std::string str(numero);
			str.erase(str.find(";"));
			strcpy_s(numero, str.c_str());

			getline(ss, palabraString, ';');
			convertirAChar(codigo, palabraString);

			getline(ss, palabraString, ';');
			convertirAChar(descripcion, palabraString);

			lineaGeneral = new InfoGenerales(covertirAEntero(numero), codigo, descripcion);
			insertarAcendente(lineaGeneral);
			lineaGeneral->cargarEspecificas();

			lectura >> numero;
		}
		lectura.close();
		return 1;
	}
	else {
		return 0;
	}
}

void ListaGenerales::convertirAChar(char *palabra, std::string palabraString) {
	palabraString.erase(palabraString.find(' '), 1); //elimina los espacios en blanco que se hacen al principio
	std::memcpy(palabra, palabraString.c_str(), palabraString.size() + 1); // convierte el string en char array
}

int ListaGenerales::covertirAEntero(char * pcodigo) {
	int num = atoi(pcodigo);
	return num;
}