#include "ListaArticulo.h"
#include <stdlib.h>  

NodoArticulo * ListaArticulo::dirNodo(char * pcodigo) {
	NodoArticulo * nodo = getCab();
	while (nodo != nullptr && strcmp(pcodigo, nodo->getInfo()->getCodigo()) != 0) {
		nodo = nodo->getSgte();
	}
	return nodo;
}

NodoArticulo * ListaArticulo::dirUltimo() {
	NodoArticulo *nodo = getCab();
	for (int i = 0; i < getTamanio(); i++)
		nodo = nodo->getSgte();

	return nodo;
}

NodoArticulo * ListaArticulo::dirAnterior(char * pcodigo) {
	NodoArticulo * nodo = dirNodo(pcodigo);

	return nodo != NULL ? nodo->getAnte() : NULL;
}

NodoArticulo * ListaArticulo::dirIndex(int pindex) {
	NodoArticulo * nodo = getCab();
	for (int i = 0; i < pindex; i++)
		nodo = nodo->getSgte();

	return nodo;
}

void ListaArticulo::agregarNodoDespuesDe(NodoArticulo * nuevo, NodoArticulo * nodo) {

	if (nodo->getSgte() != NULL) {
		nodo->getSgte()->setAnte(nuevo);
	}
	nuevo->setSgte(nodo->getSgte());
	nuevo->setAnte(nodo);
	nodo->setSgte(nuevo);

	++tamanio;
}

void ListaArticulo::agregarNodoAntesDe(NodoArticulo * nuevo, NodoArticulo * nodo) {

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

int ListaArticulo::convertirAEntero(char * pcodigo){
	int num = atoi(pcodigo);
	return num;
}

bool ListaArticulo::almacenarArticuloEnFichero(InfoArticulo* articulo) {
	std::ofstream escritura;
	escritura.open("Ficheros/articulos.txt", std::ios::out | std::ios::app);
	if (escritura.is_open()) {
		escritura << articulo->getCodigo() << "; " << articulo->getNombre() << "; "
			<< articulo->getMarca() << "; " << articulo->getTamanio() << "; "
			<< articulo->getPrecio() << "; " << std::endl;
		escritura.close();
	}
	else {
		return false;
	}
	return true;
}
//fin privados

//constrructores
ListaArticulo::ListaArticulo(){
	setCab(NULL);
	setTamanio(0);
}

ListaArticulo::~ListaArticulo(){}


NodoArticulo * ListaArticulo::getCab(){
	return cab;
}

int ListaArticulo::getTamanio(){
	return tamanio;
}

void ListaArticulo::setCab(NodoArticulo * NodoArticulo){
	this->cab = NodoArticulo;
}

void ListaArticulo::setTamanio(int ptamanio){
	this->tamanio = ptamanio;
}

bool ListaArticulo::elimina(char * pcodigo) {
	NodoArticulo *nodo = dirNodo(pcodigo);
	if (nodo != NULL) {
		eliminarNodo(nodo);
		return true;
	}
	else
		return false;
}

bool ListaArticulo::eliminarIndex(int pindex) {
	if (getTamanio() >= pindex - 1) {
		NodoArticulo * nodo = getCab();
		for (int i = 0; i < pindex; i++) {
			nodo = nodo->getSgte();
		}
		eliminarNodo(nodo);
		return true;
	}
	else
		return false;
}

void ListaArticulo::vaciar() {
	NodoArticulo * nodo = getCab();
	if (nodo != NULL) {
		NodoArticulo *temp = nodo;
		nodo = nodo->getSgte();
		delete(temp);
	}
	setCab(NULL);
	setTamanio(0);
}

void ListaArticulo::eliminarNodo(NodoArticulo * pnodo) {
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

InfoArticulo * ListaArticulo::obtenerDato(char * pcodigo) {
	NodoArticulo * nodo = dirNodo(pcodigo);
	return nodo != NULL ? nodo->getInfo() : NULL;
}

InfoArticulo * ListaArticulo::obtenerPorIndex(int pindex) {
	if (pindex - 1 <= getTamanio()) {
		return dirIndex(pindex)->getInfo();
	}
	else
		return NULL;
}

bool ListaArticulo::estaVacia() {
	return cab == NULL;
}

bool ListaArticulo::modificarDatos(char * codigo, InfoArticulo * info) {
	NodoArticulo * nodo = dirNodo(codigo);
	if (nodo != NULL) {
		nodo->setInfo(info);
		return true;
	}
	return false;
}

void ListaArticulo::insetarInicio(InfoArticulo * pinfo) {
	NodoArticulo * nodo = new NodoArticulo(pinfo);
	if (!estaVacia()) {
		getCab()->setAnte(nodo);
		nodo->setSgte(getCab());
	}
	setCab(nodo);

	tamanio++;
}

void ListaArticulo::insertarFinal(InfoArticulo * pinfo) {
	NodoArticulo * nodo = new NodoArticulo(pinfo);
	if (estaVacia()) {
		setCab(nodo);
	}
	else {
		NodoArticulo * ultimo = dirUltimo();
		nodo->setAnte(ultimo);
		ultimo->setSgte(nodo);
	}
	tamanio++;
}

bool ListaArticulo::insertarAntesDe(InfoArticulo * pinfo, char * pcodigo) {
	NodoArticulo *aux = dirNodo(pcodigo);
	bool existe = aux != NULL;
	if (existe) {
		NodoArticulo *nodo = new NodoArticulo(pinfo);
		agregarNodoAntesDe(nodo, aux);
	}
	return existe;
}

bool ListaArticulo::insertarDespuesDe(InfoArticulo * pinfo, char * pcodigo) {
	NodoArticulo *aux = dirNodo(pcodigo);
	bool existe = aux != NULL;
	if (existe) {
		NodoArticulo *nodo = new NodoArticulo(pinfo);
		agregarNodoDespuesDe(nodo, aux);
	}
	return existe;
}

bool ListaArticulo::insertarAcendente(InfoArticulo * pinfo) {
	NodoArticulo *temp = new NodoArticulo(pinfo);
	NodoArticulo * nodo = getCab();

	if (nodo == NULL || convertirAEntero(pinfo->getCodigo()) < convertirAEntero(nodo->getInfo()->getCodigo())) {
		insetarInicio(pinfo);
	}
	else {
		bool existe = false;
		while (nodo->getSgte() != NULL && convertirAEntero(pinfo->getCodigo()) >= convertirAEntero(nodo->getSgte()->getInfo()->getCodigo())){
			existe = (convertirAEntero(pinfo->getCodigo()) == convertirAEntero(nodo->getSgte()->getInfo()->getCodigo()));
			nodo = nodo->getSgte();
		}
		if(!existe){
			agregarNodoDespuesDe(temp, nodo);
			return true;
		}
	}
	return false;
}

bool ListaArticulo::insertarDecendente(InfoArticulo * pinfo) {
	NodoArticulo * nodo = getCab();
	NodoArticulo *temp = new NodoArticulo(pinfo);
	 if (nodo == NULL || strcmp(pinfo->getCodigo(), nodo->getInfo()->getCodigo()) > 0) {
		insetarInicio(pinfo);
	}
	else {
		bool existe = false;
		while (nodo->getSgte() != NULL && convertirAEntero(pinfo->getCodigo()) < convertirAEntero(nodo->getSgte()->getInfo()->getCodigo())){
			existe = (convertirAEntero(pinfo->getCodigo()) == convertirAEntero(nodo->getSgte()->getInfo()->getCodigo()));
			nodo = nodo->getSgte();
		}
		if (!existe) {
			agregarNodoDespuesDe(temp, nodo);
			return true;
		}
	}
	return false;
}


////////////////almacenamiento
int  ListaArticulo::agregar(char * codigo, char *nombre, char *marca, char * tamanio, double precio, ListaArticulo *lista) {
	//devuelve 1 si el producto ya existe
	//devuelve 2 si el archivo no pudo ser abierto
	//devuelve 3 si se registro con exito;
	InfoArticulo *articulo = new InfoArticulo(0,codigo, nombre, marca, tamanio, precio);
	bool agregar = lista->insertarAcendente(articulo);
	if (agregar == false) {
		return 1;
	}
	else {
		bool almacenado = almacenarArticuloEnFichero(articulo);
		if (almacenado == false) {
			return 2;
		}
		return 3;
	}
}

ListaArticulo* ListaArticulo::cargarArticulos(int codigoEspecificas) {
	ListaArticulo *listaTotal = leerFicheroArticulos(codigoEspecificas);
	return listaTotal;
}

ListaArticulo * ListaArticulo::leerFicheroArticulos(int codigoEspecificas) {
	std::ifstream lectura;
	char lineaEsp[30], codigo[30], nombre[30], marca[30], tamanio[30], precio[15];
	lectura.open("Ficheros/articulos.txt", std::ios::out | std::ios::in);
	
	InfoArticulo *articulo;
	
	if (lectura.is_open()){
		lectura >> lineaEsp;  //primer registro de la linea
		std::string linea;		//contador de las lineas del documento
		while (getline(lectura, linea)) {
			std::stringstream ss(linea); //nos da un el elemento por linea
			std::string palabraString;   // lo definimos para almacenar el dato del txt
			
			std::string str(lineaEsp);
			str.erase(str.find(';'));
			strcpy_s(lineaEsp, str.c_str());


			getline(ss, palabraString, ';');
			convertirAChar(codigo, palabraString);

			getline(ss, palabraString, ';');
			convertirAChar(nombre, palabraString);

			getline(ss, palabraString, ';');
			convertirAChar(marca, palabraString);

			getline(ss, palabraString, ';');
			convertirAChar(tamanio, palabraString);

			getline(ss, palabraString, ';');
			convertirAChar(precio, palabraString);
			
			if(convertirAEntero(lineaEsp) == codigoEspecificas){
				articulo = new InfoArticulo(convertirAEntero(lineaEsp),codigo, nombre, marca, tamanio, convertirAEntero(precio));
				insertarAcendente(articulo); //los anadimos a la lista
			}
			lectura >> lineaEsp;
		}
		lectura.close();
		return NULL;
	}
	else {
		return NULL;
	}
}

void ListaArticulo::convertirAChar(char *palabra, std::string palabraString) {
	palabraString.erase(palabraString.find(' '), 1); //elimina los espacios en blanco que se hacen al principio
	std::memcpy(palabra, palabraString.c_str(), palabraString.size() + 1); // convierte el string en char array
}

int ListaArticulo::covertirAEntero(char * pcodigo) {
	int num = atoi(pcodigo);
	return num;
}


void ListaArticulo::modificarArticulo(InfoArticulo * articulo)
{
	std::ofstream aux;
	std::ifstream lectura;
	bool encontrado = false;

	char lineaEsp[30], codigo[30], nombre[30], marca[30], tamanio[30], precio[15];
	aux.open("Ficheros/auxiliar.txt", std::ios::out);
	lectura.open("Ficheros/articulos.txt", std::ios::in);
	if (aux.is_open() && lectura.is_open()) {
		lectura >> codigo;
		while (!lectura.eof()) {


			lectura >> lineaEsp >> nombre >> marca >> tamanio >> precio;
			if (codigo == articulo->getCodigo()) {
				encontrado = true;

				aux << articulo->getCodigo() << "; " << articulo->getNombre() << "; "
					<< articulo->getMarca() << "; " << articulo->getTamanio() << "; "
					<< articulo->getPrecio() << "; " << std::endl;

			}
			else {
				aux << codigo << "; " << nombre << "; "
					<< marca << "; " << tamanio << "; "
					<< precio << "; " << std::endl;
			}
			lectura >> precio;
		}
	}

	aux.close();
	lectura.close();
	remove("Ficheros/articulos.txt");
	rename("Ficheros/auxiliar.txt", "Ficheros/articulos.txt");
}


//
//bool ListaArticulo::Agregar(InfoArticulo * articulo){
//	NodoArticulo *temp = new NodoArticulo(articulo);
//	NodoArticulo *aux = NULL;
//	aux = getCab();
//	
//	if (aux == NULL) {
//		setCab(temp);
//		aux = temp;
//		setTamanio(getTamanio() + 1);
//		return true;
//	}
//	else {
//		while(aux != NULL){
//			if (strcmp(temp->getInfo()->getCodigo(), aux->getInfo()->getCodigo()) == 0) {
//				return false;
//			}
//			else if(strcmp(temp->getInfo()->getCodigo(), aux->getInfo()->getCodigo()) < 0 
//					&& strlen(temp->getInfo()->getCodigo()) <= strlen(aux->getInfo()->getCodigo())){
//				if (aux->getAnte() == NULL) {
//					setCab(temp);
//					aux->setAnte(temp);
//					temp->setSgte(aux);
//				
//				}else{
//					aux->getAnte()->setSgte(temp);
//					temp->setAnte(aux->getAnte());
//					temp->setSgte(aux);
//					aux->setAnte(temp);
//				}
//				setTamanio(getTamanio() + 1);
//				return true;
//			}
//			else if (aux->getSgte() == NULL){
//				aux->setSgte(temp);
//				temp->setAnte(aux);
//				setTamanio(getTamanio() + 1);
//				return true;
//			}
//			aux = aux->getSgte();
//			}
//	}
//	return false;
//}
//
//bool ListaArticulo::Eliminar(char *codigo){
//	if (getCab() == NULL) {
//		return false;
//	}else {
//		NodoArticulo *aux = DirNodo(codigo);
//		if (aux == NULL) {
//			return false;
//		}else {
//			if (getTamanio() == 1) {
//				setCab(NULL);
//			}
//
//			else if (aux->getAnte() == NULL) {
//				setCab(aux->getSgte());
//				aux->getSgte()->setAnte(NULL);
//			}
//
//			else if(aux->getSgte() == NULL){
//				aux->getAnte()->setSgte(NULL);
//			}
//			delete aux;
//			setTamanio(getTamanio() - 1);
//			return true;
//		}
//	}
//	return false;
//}
//
//
//bool ListaArticulo::Modificar(InfoArticulo *articulo) {
//	NodoArticulo *aux = DirNodo(articulo->getCodigo());
//	if (aux == NULL) {
//		return false;
//	}
//	else {
//		NodoArticulo *temp = new NodoArticulo(articulo);
//		if (aux->getAnte() == NULL && aux->getSgte() == NULL) {
//			aux->setInfo(articulo);
//		}
//		else if (aux->getAnte() == NULL) {
//			temp->setSgte(aux->getSgte());
//			aux->getSgte()->setAnte(temp);
//		}
//		else if (aux->getSgte() == NULL){
//			aux->getAnte()->setSgte(temp);
//			temp->setAnte(aux->getAnte());
//		}else {
//			aux->getSgte()->setAnte(temp);
//			aux->getAnte()->setSgte(temp);
//			temp->setAnte(aux->getAnte());
//			temp->setSgte(aux->getSgte());
//		}
//		return true;
//	}
//	return false;
//}
//
//void ListaArticulo::DesplegarListaArticulos() {
//	if (getCab() == NULL) {
//		cout << "La lista esta vacia \n";
//	}else {
//		NodoArticulo *temp = getCab();
//		do {
//			cout << "----------------------------------------\n";
//			cout << "Codigo: "<< temp->getInfo()->getCodigo();
//			cout << "Nombre: " << temp->getInfo()->getNombre();
//			cout << "Precio: " << temp->getInfo()->getPrecio();
//		} while (temp != NULL);
//	}
//}
