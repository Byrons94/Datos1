#include "InfoPasillo.h"


//constructores
InfoPasillo::InfoPasillo(){
	setNumero(0);
	setCodigo("");
	setDescripcionn("");
	setListaGeneral(NULL);
}

InfoPasillo::InfoPasillo(int pnumero, char * pcodigo, char * pdescripcion){
	setNumero(pnumero);
	setCodigo(pcodigo);
	setDescripcionn(pdescripcion);
	setListaGeneral(NULL);
}

InfoPasillo::InfoPasillo(int pnumero, char * pcodigo, char * pdescripcion, ListaGenerales * plista){
	setNumero(pnumero);
	setCodigo(pcodigo);
	setDescripcionn(pdescripcion);
	setListaGeneral(plista);
}


InfoPasillo::InfoPasillo(int pnumero,  char * pdescripcion, ListaGenerales * plista) {
	setNumero(pnumero);
	setCodigo(autoIncrementar());
	setDescripcionn(pdescripcion);
	setListaGeneral(plista);
}


//destructor
InfoPasillo::~InfoPasillo(){}

//sets
void InfoPasillo::setNumero(int pnumero){
	this->numero = pnumero;
}

void InfoPasillo::setCodigo(char * pcodigo){
	strcpy_s(this->codigo, pcodigo);
}

void InfoPasillo::setDescripcionn(char * pdescripcion){
	strcpy_s(this->descripcion, pdescripcion);
}

void InfoPasillo::setListaGeneral(ListaGenerales * lista){
	this->lista = lista;
}

int InfoPasillo::getNumero(){
	return this->numero;
}

char * InfoPasillo::getCodigo(){
	return this->codigo;
}

char * InfoPasillo::getDescripcion(){
	return this->descripcion;
}

ListaGenerales * InfoPasillo::getListaGeneral(){
	return this->lista;
	
}

void  InfoPasillo::cargarGeneralesPasillo(){
	ListaGenerales * lista = new ListaGenerales();
	int codigoPasillo = atoi(this->getCodigo());
	lista->cargarGenerales(codigoPasillo);
	setListaGeneral(lista);
}


/////////////////////////////////////////////////////////////////////////////
char * InfoPasillo::autoIncrementar()
{
	std::string s = std::to_string(ultimoRegistro() + 1);
	char const *pchar = s.c_str();

	return (char*)s.c_str();
}

int InfoPasillo::ultimoRegistro()
{
	std::ifstream lectura;
	char numero[5], codigo[15], descripcion[30];

	lectura.open("Ficheros/pasillos.txt", std::ios::out | std::ios::in);

	if (lectura.is_open()) {
		lectura >> numero;  //primer registro de la linea
		std::string linea;		//contador de las lineas del documento

		while (getline(lectura, linea)) {
			std::stringstream ss(linea); //nos da un el elemento por linea
			std::string palabraString;   // lo definimos para almacenar el dato del txt

			std::string str(numero);
			str.erase(str.find(';'));
			strcpy_s(numero, str.c_str());

			getline(ss, palabraString, ';');
			convertirAChar(codigo, palabraString);

			getline(ss, palabraString, ';');
			convertirAChar(descripcion, palabraString);

			lectura >> numero;
		}

		lectura.close();
		return covertirAEntero(codigo);
	}
	else {
		return covertirAEntero(0);
	}

}

void InfoPasillo::convertirAChar(char *palabra, std::string palabraString) {
	palabraString.erase(palabraString.find(' '), 1); //elimina los espacios en blanco que se hacen al principio
	std::memcpy(palabra, palabraString.c_str(), palabraString.size() + 1); // convierte el string en char array
}

int InfoPasillo::covertirAEntero(char * pcodigo) {
	int num = atoi(pcodigo);
	return num;
}