#include "ListaCarrito.h"

NodoCarrito * ListaCarrito::dirNodo(char * codigo){
	NodoCarrito *nodo = getCab();
	for (int i = 0; i < getTamanio(); i++){
		if (strcmp(codigo, nodo->getInfo()->getCodigo()) == 0)
			return nodo;

		nodo = nodo->getSgte();
	}
 return NULL;
}

char * ListaCarrito::dirCodigoDeNodo(NodoCarrito * nodo){
	return nodo->getInfo()->getCodigo();
}

NodoCarrito * ListaCarrito::dirUltimo(){
	return getCab() != NULL ? getCab()->getAnte() : NULL;
}

NodoCarrito * ListaCarrito::dirAnterior(char * pcodigo){
	NodoCarrito * nodo = getCab();
	for (int i = 0; i < getTamanio(); i++){
		
		if (strcmp(pcodigo, nodo->getInfo()->getCodigo()) == 0) {
			return nodo->getAnte();
		}
		nodo = nodo->getSgte();
	}
	return NULL;
}

NodoCarrito * ListaCarrito::dirIndex(int pindex){
	bool existe = pindex <= getTamanio();
	if (existe) {
		NodoCarrito * nodo = getCab();
		for (int i = 0; i < pindex; i++){
			nodo = nodo->getSgte();
		}
		return nodo;
	}
	return NULL;
}

void ListaCarrito::agregarNodoDespuesDe(NodoCarrito * nodo, NodoCarrito *nuevo){
	nuevo->setAnte(nodo);
	nuevo->setSgte(nodo->getSgte());
	nodo->getSgte()->setAnte(nuevo);
	nodo->setSgte(nuevo);

	++tamanio;
}

void ListaCarrito::agregarNodoAntesDe(NodoCarrito *nodo, NodoCarrito *nuevo){
	nuevo->setSgte(nodo);
	nuevo->setAnte(nodo->getAnte());
	nodo->getAnte()->setSgte(nuevo);
	nodo->setAnte(nuevo);

	if (nodo == getCab())
		setCab(nuevo);
	
	++tamanio;
}

void ListaCarrito::borrar(NodoCarrito *nodo){
	if (getTamanio() == 1) {
		setCab(NULL);
	}
	else {
		nodo->getAnte()->setSgte(nodo->getSgte());
		nodo->getSgte()->setAnte(nodo->getAnte());
		delete nodo;
	}
	--tamanio;
}

ListaCarrito::ListaCarrito(){
	setCab(NULL);
	setTamanio(0);
}

ListaCarrito::ListaCarrito(NodoCarrito * pnodo){
	setCab(pnodo);
	setTamanio(1);
}

ListaCarrito::~ListaCarrito(){}

void ListaCarrito::setTamanio(int ptamanio){
	this->tamanio = ptamanio;
}

void ListaCarrito::setCab(NodoCarrito* pnodo){
	this->cab = pnodo;
}

int ListaCarrito::getTamanio(){
	return this->tamanio;
}

NodoCarrito *ListaCarrito::getCab(){
	return this->cab;
}

void ListaCarrito::insetarInicio(InfoCarrito * pinfo){
	insertarFinal(pinfo);
	setCab(getCab()->getAnte());
}

void ListaCarrito::insertarFinal(InfoCarrito * pinfo){
	NodoCarrito * nodo = new NodoCarrito(pinfo);
	if (estaVacia())
		agregarVacio(nodo);
	else
		agregarNodoDespuesDe(getCab()->getAnte(), nodo);
}

void ListaCarrito::agregarVacio(NodoCarrito *nodo){
	nodo->setSgte(nodo);
	nodo->setAnte(nodo);
	setCab(nodo);
	++tamanio;
}

bool ListaCarrito::insertarAntesDe(InfoCarrito *pinfo, char *pcodigo){
	NodoCarrito * nodo = dirNodo(pcodigo);
	bool existe = nodo != NULL;
	if (existe)
		agregarNodoAntesDe(nodo, new NodoCarrito(pinfo));

	return existe;
}

bool ListaCarrito::insertarDespuesDe(InfoCarrito * pinfo, char * pcodigo){
	NodoCarrito *nodo = dirNodo(pcodigo);
	bool existe = nodo != NULL;

	if (existe)
		agregarNodoAntesDe(nodo, new NodoCarrito(pinfo));

	return existe;
}

bool ListaCarrito::insertarAcendente(InfoCarrito * pinfo){
	NodoCarrito *nodo = getCab();
	
	bool insertar = estaVacia() || strcmp(pinfo->getCodigo(), nodo->getInfo()->getCodigo()) < 0;
		if (insertar){
			insetarInicio(pinfo);
			return true;
		}
		else {
			while (nodo->getSgte() != getCab() 
					&& strcmp(pinfo->getCodigo(), nodo->getSgte()->getInfo()->getCodigo()) > 0) {
				nodo = nodo->getSgte();
			}
			agregarNodoDespuesDe(nodo,new NodoCarrito(pinfo));
			return true;
		}
}

bool ListaCarrito::insertarDecendente(InfoCarrito * pinfo){
	NodoCarrito *nodo = getCab();
	bool insertar = estaVacia() || strcmp(pinfo->getCodigo(), nodo->getInfo()->getCodigo()) > 0;

	if (insertar){
		insetarInicio(pinfo);
		return true;
	}
	else {
		while (nodo->getSgte() != getCab() 
				&& strcmp(pinfo->getCodigo(), nodo->getSgte()->getInfo()->getCodigo()) < 0){
			nodo = nodo->getSgte();
		}
		agregarNodoDespuesDe(new NodoCarrito(pinfo), nodo);
		return true;
	}
}

bool ListaCarrito::insertarIndex(InfoCarrito * pinfo, int pindex){
	bool existe = getTamanio() <= pindex;
	if (existe) {
		NodoCarrito * nodo = getCab();
		for (int i = 0; i < pindex; i++){
			if (i == pindex) {
				agregarNodoDespuesDe(new NodoCarrito(pinfo),nodo->getAnte());
				return true;
			}
			nodo = nodo->getSgte();
		}
	}
	return false;
}

bool ListaCarrito::elimina(char * pcodigo){
	NodoCarrito * nodo = dirNodo(pcodigo);
	bool existe = nodo != NULL;
	if (existe)
		borrar(nodo);

	return existe;
}

bool ListaCarrito::eliminarIndex(int pindex){
	NodoCarrito *nodo = dirIndex(pindex);
	bool existe = nodo != NULL;
	if (existe)
		borrar(nodo);

	return existe;
}

void ListaCarrito::vaciar(){
	NodoCarrito * nodo = getCab();

	while (getTamanio() != 0) {
		NodoCarrito *temp = nodo;
		nodo = nodo->getSgte();
		delete temp;
		--tamanio;
	}
	setCab(NULL);
	setTamanio(0);
}

bool ListaCarrito::estaVacia(){
	return getCab() == NULL;	
}

InfoCarrito * ListaCarrito::obtenerDato(char * pcodigo){
	NodoCarrito * nodo = dirNodo(pcodigo);
	return nodo != NULL ? nodo->getInfo(): NULL;
}

InfoCarrito * ListaCarrito::obtenerPorIndex(int pindex){
	NodoCarrito * nodo = dirIndex(pindex);
	return nodo!=NULL ? nodo->getInfo(): NULL;
}

bool ListaCarrito::modificarDatos(char * codigo, InfoCarrito * pinfo){
	NodoCarrito * nodo = dirNodo(codigo);
	bool existe = nodo != NULL;
	if (existe)
		nodo->setInfo(pinfo);

	return existe;
}

bool ListaCarrito::modificarDatoPorIndex(int index, InfoCarrito *pinfo){
	NodoCarrito * nodo = dirIndex(index);
	bool existe = nodo != NULL;
	if (existe)
		nodo->setInfo(pinfo);

	return existe;
}

void ListaCarrito::agregarListaCompra(char* codigo, char * nombre, 
										char * codClie, bool estado, double monto, ListaCompra * listaCompra) {
	InfoCarrito * pinfo = new InfoCarrito(codigo, nombre, codClie, estado,estado, listaCompra);
	NodoCompra * nodo = listaCompra->getCab();
	while (nodo!=NULL){
		nodo->getLineaDetalle()->setCodCarrito(codigo);
		nodo = nodo->getSgte();
	}
	insertarAcendente(pinfo);
}

void ListaCarrito::mostrarLista(){
}

void  ListaCarrito::guardarCarritos() {
	NodoCarrito  * nodo = getCab();
	for (int i = 0; i < getTamanio(); i++){
		almacenarCarritoEnFichero(nodo->getInfo());

		nodo->getInfo()->getListaCompra()->guardarListas();
		nodo = nodo->getSgte();
	}
}

bool ListaCarrito::almacenarCarritoEnFichero(InfoCarrito* carrito) {
	std::ofstream escritura;
	escritura.open("Ficheros/carritos.txt", std::ios::out | std::ios::app);
	if (escritura.is_open()) {
		escritura << carrito->getCodigo() << "; " << carrito->getCodClie() << "; "
			<< carrito->getNombre() << "; " << carrito->getEstado() << "; "
			<< carrito->getMonto() << "; " << std::endl;
		escritura.close();
	}
	else {
		return false;
	}
	return true;
}

void ListaCarrito::cargarCarritosUsuario(char *codUsuario) {
	leerFicheroCarritoUsuario(codUsuario);
}

int ListaCarrito::leerFicheroCarritoUsuario(char *codUsuario) {
	std::ifstream lectura;
	char codigo[15], codCliente[15], nombre[30], estado[5], monto[15];
	
	lectura.open("Ficheros/carritos.txt", std::ios::out | std::ios::in);
	InfoCarrito * listaCarrito;

	if (lectura.is_open()) {
		lectura >> codigo;  //primer registro de la linea
		std::string linea;		//contador de las lineas del documento
		while (getline(lectura, linea)) {
			std::stringstream ss(linea); //nos da un el elemento por linea
			std::string palabraString;   // lo definimos para almacenar el dato del txt

			std::string str(codigo);
			str.erase(str.find(';'));
			strcpy_s(codigo, str.c_str());

			getline(ss, palabraString, ';');
			convertirAChar(codCliente, palabraString);

			getline(ss, palabraString, ';');
			convertirAChar(nombre, palabraString);

			getline(ss, palabraString, ';');
			convertirAChar(estado, palabraString);

			getline(ss, palabraString, ';');
			convertirAChar(monto, palabraString);

			if (covertirAEntero(codUsuario) == covertirAEntero(codCliente) 
				&& convertirABoolean(estado) == true && strcmp(nombre, "Regular" ) !=0 ){
				ListaCompra * listaC = new ListaCompra();
				listaC->cargarCompras(codigo);
				listaCarrito = new InfoCarrito(codigo, nombre, codCliente, convertirABoolean(estado),
							covertirAEntero(monto), listaC);
				insertarAcendente(listaCarrito);
			}

			lectura >> codigo;
		}
		lectura.close();
		return 1;
	}
	else {
		return 0;
	}
}


void ListaCarrito::cargarCarritosPendientes() {
	leerFicheroCarritoPendientes();
}

int ListaCarrito::leerFicheroCarritoPendientes() {
	std::ifstream lectura;
	char codigo[15], codCliente[15], nombre[30], estado[5], monto[15];

	lectura.open("Ficheros/carritos.txt", std::ios::out | std::ios::in);
	InfoCarrito * listaCarrito;

	if (lectura.is_open()) {
		lectura >> codigo;  //primer registro de la linea
		std::string linea;		//contador de las lineas del documento
		while (getline(lectura, linea)) {
			std::stringstream ss(linea); //nos da un el elemento por linea
			std::string palabraString;   // lo definimos para almacenar el dato del txt

			std::string str(codigo);
			str.erase(str.find(';'));
			strcpy_s(codigo, str.c_str());

			getline(ss, palabraString, ';');
			convertirAChar(codCliente, palabraString);

			getline(ss, palabraString, ';');
			convertirAChar(nombre, palabraString);

			getline(ss, palabraString, ';');
			convertirAChar(estado, palabraString);

			getline(ss, palabraString, ';');
			convertirAChar(monto, palabraString);

		if (convertirABoolean(estado) == true && strcmp(nombre, "Regular") == 0) {
				ListaCompra * listaC = new ListaCompra();
				listaC->cargarCompras(codigo);
				listaCarrito = new InfoCarrito(codigo, nombre, codCliente, convertirABoolean(estado),
					covertirAEntero(monto), listaC);
				insertarFinal(listaCarrito);
			}
			lectura >> codigo;
		}
		lectura.close();
		return 1;
	}
	else {
		return 0;
	}
}

void ListaCarrito::modificarCarrito(InfoCarrito * info){
	std::ofstream aux;
	std::ifstream lectura;
	bool encontrado = false;

	char codigo[15], codCliente[15], nombre[30], estado[5], monto[15];

	aux.open("Ficheros/auxiliar.txt", std::ios::out);
	lectura.open("Ficheros/carritos.txt", std::ios::in);

	std::string linea;

	if (aux.is_open() && lectura.is_open()) {
		lectura >> codigo;

		while (getline(lectura, linea)) {
			std::stringstream ss(linea); 
			std::string palabraString;   

			std::string str(codigo);
			str.erase(str.find(';'));
			strcpy_s(codigo, str.c_str());

			getline(ss, palabraString, ';');
			convertirAChar(codCliente, palabraString);

			getline(ss, palabraString, ';');
			convertirAChar(nombre, palabraString);

			getline(ss, palabraString, ';');
			convertirAChar(estado, palabraString);

			getline(ss, palabraString, ';');
			convertirAChar(monto, palabraString);

			if (strcmp(codigo, info->getCodigo()) == 0) {
				encontrado = true;

				aux << info->getCodigo() << "; " << info->getCodClie() << "; "
					<< info->getNombre() << "; " << 1 << "; "
					<< info->getMonto() << "; " << std::endl;
			}
			else {
				aux << codigo << "; " << codCliente << "; "
					<< nombre << "; " << estado << "; " << monto << "; " << std::endl;
			}
			lectura >> codigo;
		}
	}

	aux.close();
	lectura.close();
	remove("Ficheros/carritos.txt");
	rename("Ficheros/auxiliar.txt", "Ficheros/carritos.txt");
}

void ListaCarrito::convertirAChar(char *palabra, std::string palabraString) {
	palabraString.erase(palabraString.find(' '), 1); //elimina los espacios en blanco que se hacen al principio
	std::memcpy(palabra, palabraString.c_str(), palabraString.size() + 1); // convierte el string en char array
}

int ListaCarrito::covertirAEntero(char * pcodigo) {
	int num = atoi(pcodigo);
	return num;
}

//0 entregado, 1 pendiente
bool ListaCarrito::convertirABoolean(char *num){
	if (strcmp(num, "1") ==0)
		return false;

	return true;
}

