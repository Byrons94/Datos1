#include "ListaCompra.h"

NodoCompra * ListaCompra::dirNodo(char * pcodigo){
	NodoCompra *nodo = getCab();
	while (nodo != nullptr && strcmp(nodo->getLineaDetalle()->getProducto(), pcodigo) != 0)
		nodo = nodo->getSgte();

	return nodo;
}

char * ListaCompra::dirCodigoDeNodo(NodoCompra * nodo){
	return nodo->getLineaDetalle()->getProducto();
}

NodoCompra * ListaCompra::dirUltimo(){
	NodoCompra *nodo = getCab();
	for (int i = 1; i < getTamanio(); ++i)
		nodo = nodo->getSgte();
	return nodo;
}

ListaCompra::ListaCompra(){
	setCab(NULL);
	setTamanio(0);
}

ListaCompra::ListaCompra(NodoCompra * pnodo){
	setCab(pnodo);
	setTamanio(1);
}

ListaCompra::~ListaCompra(){}

void ListaCompra::setCab(NodoCompra * pnodo){
	this->cab = pnodo;
}

void ListaCompra::setTamanio(int ptamanio){
	this->tamanio = ptamanio;
}

NodoCompra * ListaCompra::getCab(){
	return this->cab;
}

int ListaCompra::getTamanio(){
	return this->tamanio;
}

void ListaCompra::insertarInicio(InfoCompra * pinfo) {
	NodoCompra * nodo = new NodoCompra(pinfo);
	nodo->setSgte(getCab());
	setCab(nodo);
	++tamanio;
}

void ListaCompra::insertarFinal(InfoCompra * pinfo) {
	NodoCompra * nodo = dirUltimo();
	if (getCab() == NULL)
		setCab(new NodoCompra(pinfo));
	else
		nodo->setSgte(new NodoCompra(pinfo));

	++tamanio;
}

bool ListaCompra::insertarDespuesDe(InfoCompra * pinfo, char * pcodigo) {
	NodoCompra * nodo = dirNodo(pcodigo);
	if (nodo != NULL) {
		NodoCompra * aux = new NodoCompra(pinfo);
		if (nodo->getSgte() != NULL) {
			aux->setSgte(nodo->getSgte());
		}
		nodo->setSgte(aux);
		++tamanio;
		return true;
	}
	return false;
}

bool ListaCompra::insertarAcendente(InfoCompra * pinfo) {
	char* codigo = pinfo->getProducto();
	bool seInserta = estaVacia() || strcmp(codigo, dirCodigoDeNodo(getCab())) < 0;
	if (seInserta)
		insertarInicio(pinfo);
	else {
		int i = 1;
		NodoCompra *nodo = getCab();
		while (nodo->getSgte() && (i = strcmp(codigo, dirCodigoDeNodo(nodo->getSgte()))) > 0)
			nodo = nodo->getSgte();

		if (seInserta = (i != 0))
			insertarDespuesDe(pinfo, nodo->getLineaDetalle()->getProducto());
	}
	return seInserta;
}

bool ListaCompra::insertarDecendente(InfoCompra * pinfo) {
	char* codigo = pinfo->getProducto();
	bool seInserta = estaVacia() || strcmp(codigo, dirCodigoDeNodo(getCab())) > 0;

	if (seInserta)
		insertarInicio(pinfo);
	else
	{
		int esI = 1;
		NodoCompra *nodo = getCab();
		while (nodo->getSgte() && (esI = strcmp(codigo, dirCodigoDeNodo(nodo->getSgte()))) < 0)
			nodo = nodo->getSgte();

		if (seInserta = esI != 0)
			insertarDespuesDe(pinfo, nodo->getLineaDetalle()->getProducto());
	}
	return seInserta;
}

bool ListaCompra::insertarIndex(InfoCompra * pinfo, int pindex) {
	NodoCompra *nodo = getCab();
	if (pindex <= getTamanio()) {
		for (int i = 0; i < pindex; i++) {
			nodo = nodo->getSgte();
		}
		insertarDespuesDe(pinfo, nodo->getLineaDetalle()->getProducto());
		return true;
	}
	return false;
}

//revisar
bool ListaCompra::elimina(char * pcodigo) {
	if (estaVacia())
		return false;

	if (strcmp(getCab()->getLineaDetalle()->getProducto(), pcodigo) == 0) {
		NodoCompra *borrar = getCab();
		setCab(getCab()->getSgte());
		delete borrar;
		tamanio--;
	}
	return true;
}

bool ListaCompra::agregarProducto(InfoCompra * lineaDetallle){
	NodoCompra * nodo = dirNodo(lineaDetallle->getProducto());
	if(nodo!=NULL)
		return false;
		//insertarFinal(lineaDetallle);
	else {
		insertarFinal(lineaDetallle);
		return true;
	}
}

void ListaCompra::vaciar() {
	NodoCompra *nodo = getCab();
	while (nodo != nullptr) {
		NodoCompra *borrar = nodo;
		nodo = nodo->getSgte();
		delete borrar;
	}
	setCab(NULL);
	setTamanio(0);
}

bool ListaCompra::estaVacia() {
	return this->cab == NULL;
}

InfoCompra * ListaCompra::obtenerDato(char * pcodigo) {
	NodoCompra * nodo = dirNodo(pcodigo);
	if (nodo != NULL)
		return nodo->getLineaDetalle();
	else
		return NULL;
}

InfoCompra * ListaCompra::obtenerPorIndex(int pindex) {
	NodoCompra * nodo = getCab();
	if (pindex >= getTamanio())
		return NULL;
	else {
		for (int i = 0; i < pindex; i++) {
			nodo = nodo->getSgte();
		}
	}
	return nodo->getLineaDetalle();
}

//falta de implementar
bool ListaCompra::modificarDatos(char * pcodigo, InfoCompra * pinfo) {
	return false;
}

bool ListaCompra::momodificarDatoPorIndex(int pindex, InfoCompra *pinfo) {
	return false;
}

void ListaCompra::guardarListas(){
	NodoCompra * nodo = getCab();
	while (nodo != NULL) {
		almacenarListaEnFichero(nodo->getLineaDetalle());
		nodo = nodo->getSgte();
	}
}

bool ListaCompra::almacenarListaEnFichero(InfoCompra* lista) {
	std::ofstream escritura;
	escritura.open("Ficheros/pedidos.txt", std::ios::out | std::ios::app);
	if (escritura.is_open()) {
		escritura << lista->getCodCarrito() << "; " << lista->getPasillo() << "; "
			<< lista->getGeneral() << "; " << lista->getEspecifica() << "; "
			<< lista->getProducto() << "; " << lista->getCantidad() << "; "
			<< lista->getMonto() << "; " << std::endl;
		escritura.close();
	}
	else {
		return false;
	}
	return true;
}


void ListaCompra::cargarCompras(char *codCarrito) {
	leerFicheroCompras(codCarrito);
}

int ListaCompra::leerFicheroCompras(char *codCarrito) {
	std::ifstream lectura;
	char carrito[15], pasillo[15], general[15], 
			especifica[15], producto[15], cantidad[15], monto[15];

	lectura.open("Ficheros/pedidos.txt", std::ios::out | std::ios::in);
	InfoCompra * listaCompras;

	if (lectura.is_open()) {
		lectura >> carrito;  //primer registro de la linea
		std::string linea;		//contador de las lineas del documento

		while (getline(lectura, linea)) {
			std::stringstream ss(linea); //nos da un el elemento por linea
			std::string palabraString;   // lo definimos para almacenar el dato del txt

			std::string str(codCarrito);
			str.erase(str.find(';'));
			strcpy_s(carrito, str.c_str());
			
			getline(ss, palabraString, ';');
			convertirAChar(pasillo, palabraString);

			getline(ss, palabraString, ';');
			convertirAChar(general, palabraString);

			getline(ss, palabraString, ';');
			convertirAChar(especifica, palabraString);

			getline(ss, palabraString, ';');
			convertirAChar(producto, palabraString);

			getline(ss, palabraString, ';');
			convertirAChar(cantidad, palabraString);

			getline(ss, palabraString, ';');
			convertirAChar(monto, palabraString);

			if (covertirAEntero(carrito) == covertirAEntero(codCarrito)) {
				listaCompras = new InfoCompra(carrito, pasillo, general,
						especifica, producto, covertirAEntero(cantidad), covertirAEntero(monto));
				insertarAcendente(listaCompras);
			}
			lectura >> carrito;
		}
		lectura.close();
		return 1;
	}
	else {
		return 0;
	}
}

void ListaCompra::convertirAChar(char *palabra, std::string palabraString) {
	palabraString.erase(palabraString.find(' '), 1); //elimina los espacios en blanco que se hacen al principio
	std::memcpy(palabra, palabraString.c_str(), palabraString.size() + 1); // convierte el string en char array
}

int ListaCompra::covertirAEntero(char * pcodigo) {
	int num = atoi(pcodigo);
	return num;
}
