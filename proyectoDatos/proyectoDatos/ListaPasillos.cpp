#include "ListaPasillos.h"

NodoPasillo * ListaPasillos::dirNodo(char * pcodigo){
	NodoPasillo * nodo = getCab();
	while (nodo != nullptr && strcmp(pcodigo, dirCodigoDePasillo(nodo)) != 0 ) {
		nodo = nodo->getSgte();
	}
	return nodo;
}

NodoPasillo * ListaPasillos::dirUltimo(){
	NodoPasillo *nodo = getCab();
	for (int i = 0; i < getTamanio(); i++)
		nodo = nodo->getSgte();

	return nodo;
}

NodoPasillo * ListaPasillos::dirAnterior(char * pcodigo ){
	NodoPasillo * nodo = dirNodo(pcodigo);
	
	return nodo != NULL? nodo->getAnte():NULL;
}

NodoPasillo * ListaPasillos::dirIndex(int pindex){
	NodoPasillo * nodo = getCab();
	for (int i = 0; i < pindex; i++)
		nodo = nodo->getSgte();

	return nodo;
}

char * ListaPasillos::dirCodigoDePasillo(NodoPasillo * nodo){
	return nodo->getInfoPasillo()->getCodigo();
}

void ListaPasillos::agregarNodoDespuesDe(NodoPasillo * nuevo, NodoPasillo * nodo){
	if (nodo->getSgte() != NULL) {
		nodo->getSgte()->setAnte(nuevo);
	}
	nuevo->setSgte(nodo->getSgte());
	nuevo->setAnte(nodo);
	nodo->setSgte(nuevo);
	++tamanio;
}

void ListaPasillos::agregarNodoAntesDe(NodoPasillo * nuevo, NodoPasillo * nodo){
	
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

int ListaPasillos::convertirAEntero(char * pcodigo) {
	int num = atoi(pcodigo);
	return num;
}

//constructores
ListaPasillos::ListaPasillos(){
	setCab(NULL);
	setTamanio(0);
}

ListaPasillos::~ListaPasillos(){}


void ListaPasillos::setCab(NodoPasillo * pnodo){
	this->cab = pnodo;
}
void ListaPasillos::setTamanio(int ptamanio){
	this->tamanio = ptamanio;
}

NodoPasillo * ListaPasillos::getCab(){
	return this->cab;
}

int ListaPasillos::getTamanio(){
	return this->tamanio;
}

bool ListaPasillos::elimina(char * pcodigo){
	NodoPasillo *nodo = dirNodo(pcodigo);
	if(nodo!=NULL){
		eliminarNodo(nodo);
	return true;
	}
	else 
		return false;
}

bool ListaPasillos::eliminarIndex(int pindex){
	if (getTamanio() >= pindex - 1) {
		NodoPasillo * nodo = getCab();
		for (int i = 0; i < pindex; i++){
			nodo = nodo->getSgte();
		}
		eliminarNodo(nodo);
		return true;
	}
	else
	return false;
}

void ListaPasillos::vaciar() {
	NodoPasillo * nodo = getCab();
	if (nodo != NULL) {
		NodoPasillo *temp = nodo;
		nodo = nodo->getSgte();
		delete(temp);
	}
	setCab(NULL);
	setTamanio(0);
}

void ListaPasillos::eliminarNodo(NodoPasillo * pnodo){
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

InfoPasillo * ListaPasillos::obtenerDato(char * pcodigo){
	NodoPasillo * nodo = dirNodo(pcodigo);
	return nodo != NULL ? nodo->getInfoPasillo() : NULL;
}

InfoPasillo * ListaPasillos::obtenerPorIndex(int pindex){
	if (pindex - 1 <= getTamanio()) {
		return dirIndex(pindex)->getInfoPasillo();
	}
	else
		return NULL;
}

bool ListaPasillos::estaVacia(){
	return cab==NULL;
}

bool ListaPasillos::modificarDatos(char * codigo, InfoPasillo * info){
	NodoPasillo * nodo = dirNodo(codigo);
	if (nodo != NULL) {
		nodo->setInfoPasillo(info);
		return true;
	}
	return false;
}

void ListaPasillos::insetarInicio(InfoPasillo * pinfo){
	NodoPasillo * nodo = new NodoPasillo(pinfo);
	if (!estaVacia()) {
		getCab()->setAnte(nodo);
		nodo->setSgte(getCab());
	}
	setCab(nodo);

	tamanio++;
}

void ListaPasillos::insertarFinal(InfoPasillo * pinfo){
	NodoPasillo * nodo = new NodoPasillo(pinfo);
	if (estaVacia()) {
		setCab(nodo);
	}else {
		NodoPasillo * ultimo = dirUltimo();
		nodo->setAnte(ultimo);
		ultimo->setSgte(nodo);
	}
	tamanio++;
}

bool ListaPasillos::insertarAntesDe(InfoPasillo * pinfo, char * pcodigo){
	NodoPasillo *aux = dirNodo(pcodigo);
	bool existe = aux != NULL;
	if(existe){
		NodoPasillo *nodo = new NodoPasillo(pinfo);
		agregarNodoAntesDe(nodo, aux);
	}
	return existe;
}

bool ListaPasillos::insertarDespuesDe(InfoPasillo * pinfo, char * pcodigo){
	NodoPasillo *aux = dirNodo(pcodigo);
	bool existe = aux != NULL;
	if (existe) {
		NodoPasillo *nodo = new NodoPasillo(pinfo);
		agregarNodoDespuesDe(nodo, aux);
	}
	return existe;
}

bool ListaPasillos::insertarAcendente(InfoPasillo * pinfo) {
	NodoPasillo * temp = new NodoPasillo(pinfo);
	NodoPasillo * nodo = getCab();
	if (nodo == NULL || convertirAEntero(pinfo->getCodigo()) < convertirAEntero(nodo->getInfoPasillo()->getCodigo())) {
		insetarInicio(pinfo);
	}
	else {
		bool existe = false;
		while (nodo->getSgte() != NULL && convertirAEntero(pinfo->getCodigo()) >= convertirAEntero(nodo->getSgte()->getInfoPasillo()->getCodigo())) {
			existe = (convertirAEntero(pinfo->getCodigo()) == convertirAEntero(nodo->getInfoPasillo()->getCodigo()));
			nodo = nodo->getSgte();
		}
		if (!existe) {
			agregarNodoDespuesDe(temp, nodo);
			return true;
		}
	}
	return false;
}

bool ListaPasillos::insertarDecendente(InfoPasillo * pinfo){
	NodoPasillo * temp = new NodoPasillo(pinfo);
	NodoPasillo * nodo = getCab();
	if (nodo == NULL || convertirAEntero(pinfo->getCodigo()) > convertirAEntero(nodo->getInfoPasillo()->getCodigo())) {
		insetarInicio(pinfo);
	}
	else {
		bool existe = false;
		while (nodo->getSgte() != NULL && convertirAEntero(pinfo->getCodigo()) < convertirAEntero(nodo->getSgte()->getInfoPasillo()->getCodigo())) {
			existe = (convertirAEntero(pinfo->getCodigo()) == convertirAEntero(nodo->getInfoPasillo()->getCodigo()));
			nodo = nodo->getSgte();
		}
		if (!existe) {
			agregarNodoDespuesDe(temp, nodo);

			return true;
		}
	}
	return false;
}


void ListaPasillos::cargarPasillos(){
	leerFicheroPasillos();
}

int ListaPasillos::leerFicheroPasillos() {
	
	ifstream lectura;
	char numero[5], codigo[15], descripcion[30];

	lectura.open("Ficheros/pasillos.txt", ios::out | ios::in);
	InfoPasillo *pasillo;

	if (lectura.is_open()) {
		lectura >> numero;  //primer registro de la linea
		string linea;		//contador de las lineas del documento

		while (getline(lectura, linea)) {
			stringstream ss(linea); //nos da un el elemento por linea
			string palabraString;   // lo definimos para almacenar el dato del txt

			string str(numero);
			str.erase(str.find(';'));
			strcpy_s(numero, str.c_str());

			getline(ss, palabraString, ';');
			convertirAChar(codigo, palabraString);

			getline(ss, palabraString, ';');
			convertirAChar(descripcion, palabraString);

			pasillo = new InfoPasillo(covertirAEntero(numero), codigo, descripcion);
			insertarAcendente(pasillo); //los anadimos a la lista
			
			pasillo->cargarGeneralesPasillo();
			lectura >> numero;
		}
		lectura.close();
		return 1;
	}
	else {
		return 0;
	}
}

void ListaPasillos::convertirAChar(char *palabra, string palabraString) {
	palabraString.erase(palabraString.find(' '), 1); //elimina los espacios en blanco que se hacen al principio
	std::memcpy(palabra, palabraString.c_str(), palabraString.size() + 1); // convierte el string en char array
}

int ListaPasillos::covertirAEntero(char * pcodigo) {
	int num = atoi(pcodigo);
	return num;
}

