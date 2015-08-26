#include "InfoGenerales.h"

InfoGenerales::InfoGenerales(){
	setNumero(0);
	setCodigo("");
	setDescripcionn("");
	setListaEspecifica(NULL);
}

InfoGenerales::InfoGenerales(int numero, char * codigo, char * descripcion){
	setNumero(numero);
	setCodigo(codigo);
	setDescripcionn(descripcion);
	setListaEspecifica(NULL);
}

InfoGenerales::InfoGenerales(int numero, char * codigo, char * descripcion, ListaEspecifica * lista){
	setNumero(numero);
	setCodigo(codigo);
	setDescripcionn(descripcion);
	setListaEspecifica(lista);
}

InfoGenerales::InfoGenerales(int numero,  char * descripcion, ListaEspecifica * lista) {
	setNumero(numero);
	setCodigo(autoIncrementar());
	setDescripcionn(descripcion);
	setListaEspecifica(lista);
}

InfoGenerales::~InfoGenerales(){}


void InfoGenerales::setNumero(int pnumero){
	this->numero = pnumero;
}

void InfoGenerales::setCodigo(char * pcodigo){
	strcpy_s(this->codigo, pcodigo);
}

void InfoGenerales::setDescripcionn(char * pdescripcion){
	strcpy_s(this->descripcion, pdescripcion);
}

void InfoGenerales::setListaEspecifica(ListaEspecifica * plista){
	this->lista = plista;
}

int InfoGenerales::getNumero(){
	return  this->numero;
}

char * InfoGenerales::getCodigo(){
	return this->codigo;
}

char * InfoGenerales::getDescripcion(){
	return this->descripcion;
}

ListaEspecifica * InfoGenerales::getListaEspecifica(){
	return this->lista;
}

void  InfoGenerales::cargarEspecificas() {
	ListaEspecifica * lista = new ListaEspecifica();
	int especificas = atoi(this->codigo);
	lista->cargarEspecificas(especificas);
	setListaEspecifica(lista);
}


/////////////////////////////////////////////////////////////////////////////
char * InfoGenerales::autoIncrementar()
{
	std::string s = std::to_string(ultimoRegistro() + 1);
	char const *pchar = s.c_str();

	return (char*)s.c_str();
}

int InfoGenerales::ultimoRegistro()
{
	std::ifstream lectura;
	char numero[3], codigo[15], descripcion[30];

	lectura.open("Ficheros/generales.txt", std::ios::out | std::ios::in);

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

			lectura >> numero;
		}

		lectura.close();
		return covertirAEntero(codigo);
	}
	else {
		return covertirAEntero(0);
	}

}

void InfoGenerales::convertirAChar(char *palabra, std::string palabraString) {
	palabraString.erase(palabraString.find(' '), 1); //elimina los espacios en blanco que se hacen al principio
	std::memcpy(palabra, palabraString.c_str(), palabraString.size() + 1); // convierte el string en char array
}

int InfoGenerales::covertirAEntero(char * pcodigo) {
	int num = atoi(pcodigo);
	return num;
}
