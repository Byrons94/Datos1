#include "ListaUsuario.h"

NodoUsuario * ListaUsuario::dirNodo(char * pcodigo){
	NodoUsuario *nodo = getCab();
	while (nodo != nullptr && strcmp(nodo->getInfo()->getCodigo(), pcodigo) != 0)
		nodo = nodo->getSgte();

	return nodo;
}

char * ListaUsuario::dirCodigoDeNodo(NodoUsuario * nodo){
	return nodo->getInfo()->getCodigo();
}

NodoUsuario * ListaUsuario::dirUltimo(){
	NodoUsuario *nodo = getCab();
	for (int i = 1; i < getTamanio(); ++i)
		nodo = nodo->getSgte();
	return nodo;
}

ListaUsuario::ListaUsuario(){
	setCab(NULL);
	setTamanio(0);
}

ListaUsuario::~ListaUsuario(){}

void ListaUsuario::setCab(NodoUsuario * pnodo){
	this->cab = pnodo;
}

void ListaUsuario::setTamanio(int ptamanio){
	this->tamanio = ptamanio;
}

NodoUsuario *ListaUsuario::getCab(){
	return this->cab;
}

int ListaUsuario::getTamanio(){
	return this->tamanio;
}


void ListaUsuario::insertarInicio(InfoUsuario * pinfo){
	NodoUsuario * nodo = new NodoUsuario(pinfo);
	nodo->setSgte(getCab());
	setCab(nodo);
	++tamanio;
}

void ListaUsuario::insertarFinal(InfoUsuario * pinfo){
	NodoUsuario * nodo = dirUltimo();
	if (getCab() == NULL)
		setCab(new NodoUsuario(pinfo));
	else
		nodo->setSgte(new NodoUsuario(pinfo));
	
	++tamanio;
}

bool ListaUsuario::insertarDespuesDe(InfoUsuario * pinfo, char * pcodigo){
	NodoUsuario * nodo = dirNodo(pcodigo);
	if (nodo != NULL) {
		NodoUsuario * aux = new NodoUsuario(pinfo);
		if (nodo->getSgte() != NULL) {
			aux->setSgte(nodo->getSgte());
		}
		nodo->setSgte(aux);
		++tamanio;
		return true;
	}
	return false;
}

bool ListaUsuario::insertarAcendente(InfoUsuario * pinfo){
	char* codigo = pinfo->getCodigo();
	bool seInserta = estaVacia() || strcmp(codigo, dirCodigoDeNodo(getCab())) < 0;
	
	if (seInserta)
		insertarInicio(pinfo);
	else {
		int i = 1;
		NodoUsuario *nodo = getCab();
		while (nodo->getSgte() && (i = strcmp(codigo, dirCodigoDeNodo(nodo->getSgte()))) > 0)
			nodo = nodo->getSgte();

		if (seInserta = (i != 0))
			insertarDespuesDe(pinfo, nodo->getInfo()->getCodigo());
	}
	return seInserta;
}

bool ListaUsuario::insertarDecendente(InfoUsuario * pinfo){
	char* codigo = pinfo->getCodigo();
	bool seInserta = estaVacia() || strcmp(codigo, dirCodigoDeNodo(getCab())) > 0;

	if (seInserta)
		insertarInicio(pinfo);
	else
	{
		int esI = 1;
		NodoUsuario *nodo = getCab();
		while (nodo->getSgte() && (esI = strcmp(codigo, dirCodigoDeNodo(nodo->getSgte()))) < 0)
			nodo = nodo->getSgte();

		if (seInserta = esI != 0)
			insertarDespuesDe(pinfo, nodo->getInfo()->getCodigo());
	}

	return seInserta;
}

bool ListaUsuario::insertarIndex(InfoUsuario * pinfo, int pindex){
	NodoUsuario *nodo = getCab();
	if (pindex <= getTamanio()) {
		for (int i = 0; i < pindex; i++){
			nodo = nodo->getSgte();
		}
		insertarDespuesDe(pinfo, nodo->getInfo()->getCodigo());
		return true;
	}
	return false;
}

bool ListaUsuario::elimina(char * pcodigo) {
	if (estaVacia())
		return false;

	if (strcmp(getCab()->getInfo()->getCodigo(), pcodigo) == 0) {
		NodoUsuario *borrar = getCab();
		setCab(getCab()->getSgte());
		delete borrar;
		tamanio--;
	}
	return true;
}


void ListaUsuario::vaciar(){
	NodoUsuario *nodo = getCab();
	while (nodo != nullptr) {
		NodoUsuario *borrar = nodo;
		nodo = nodo->getSgte();
		delete borrar;
	}

	setCab(NULL);
	setTamanio(0);
}

bool ListaUsuario::estaVacia(){
	return this->cab == NULL;
}

InfoUsuario * ListaUsuario::obtenerDato(char * pcodigo){
	NodoUsuario * nodo = dirNodo(pcodigo);
	if (nodo != NULL)
		return nodo->getInfo();
	else
		return NULL;
}

InfoUsuario * ListaUsuario::obtenerPorIndex(int pindex){
	NodoUsuario * nodo = getCab();
	if (pindex >= getTamanio())
		return NULL;
	else {
		for (int i = 0; i < pindex; i++){
			nodo = nodo->getSgte();
		}
	}
	return nodo->getInfo();
}

//falta de implementar
bool ListaUsuario::modificarDatos(char * pcodigo, InfoUsuario * pinfo){
	return false;
}

bool ListaUsuario::momodificarDatoPorIndex(int pindex, InfoUsuario *pinfo){
	return false;
}

void ListaUsuario::crearUsuario(InfoUsuario *info){
	almacenarUsuarioEnFichero(info);
}

bool ListaUsuario::almacenarUsuarioEnFichero(InfoUsuario* usuario) {
	std::ofstream escritura;
	escritura.open("Ficheros/usuarios.txt", std::ios::out | std::ios::app);
	if (escritura.is_open()) {
		escritura << usuario->getCodigo() << "; " << usuario->getNombre() << "; "
			<< usuario->getContrasenna() << "; " << usuario->getRol() << std::endl;
		escritura.close();
	}
	else {
		return false;
	}
	return true;
}

InfoUsuario * ListaUsuario::iniciarSesion(char * pcodigo, char * pclave){	
	cargarUsuarios();
	NodoUsuario * nodo = getCab();
	InfoUsuario * usuario = NULL;
	
	while (nodo != NULL) {
		if (strcmp(pcodigo, nodo->getInfo()->getCodigo()) == 0
			&& strcmp(pclave, nodo->getInfo()->getContrasenna()) == 0) {
			usuario = nodo->getInfo();
		}
		nodo = nodo->getSgte();
	}
	return usuario;
}


void  ListaUsuario::cargarUsuarios() {
	leerFicheroUsuarios();
}

void  ListaUsuario::leerFicheroUsuarios() {
	std::ifstream lectura;

	char codigo[30], nombre[30], contrasena[30], rol[5];
	lectura.open("Ficheros/usuarios.txt", std::ios::out | std::ios::in);

	InfoUsuario * usuario = NULL;

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
			convertirAChar(nombre, palabraString);

			getline(ss, palabraString, ';');
			convertirAChar(contrasena, palabraString);

			getline(ss, palabraString, ';');
			convertirAChar(rol, palabraString);

			usuario = new InfoUsuario(codigo, nombre, contrasena, covertirAEntero(rol));
			insertarAcendente(usuario);

			lectura >> codigo;
		}
		lectura.close();
	}
}

void ListaUsuario::convertirAChar(char *palabra, std::string palabraString) {
	palabraString.erase(palabraString.find(' '), 1); //elimina los espacios en blanco que se hacen al principio
	std::memcpy(palabra, palabraString.c_str(), palabraString.size() + 1); // convierte el string en char array
}

int ListaUsuario::covertirAEntero(char * pcodigo) {
	int num = atoi(pcodigo);
	return num;
}
