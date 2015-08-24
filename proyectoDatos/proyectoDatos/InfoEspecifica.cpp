#include "InfoEspecifica.h"



InfoEspecifica::InfoEspecifica(){
	setNumero(0);
	setCodigo("");
	setDescripcion("");
	setListaArticulos(NULL);
}

InfoEspecifica::InfoEspecifica(int pnumero, char * pcodigo, char * pdescripcion) {
	setNumero(pnumero);
	setCodigo(pcodigo);
	setDescripcion(pdescripcion);
	setListaArticulos(NULL);
}

InfoEspecifica::InfoEspecifica(int pnumero, char * pcodigo, char * pdescripcion, ListaArticulo * plista){
	setNumero(pnumero);
	setCodigo(pcodigo);
	setDescripcion(pdescripcion);
	setListaArticulos(plista);
}

InfoEspecifica::InfoEspecifica(int pnumero,char * pdescripcion, ListaArticulo * plista) {
	setNumero(pnumero);
	setCodigo(autoIncrementar());
	setDescripcion(pdescripcion);
	setListaArticulos(plista);
}

InfoEspecifica::~InfoEspecifica(){}

void InfoEspecifica::setNumero(int pnumero){
	this->numero = pnumero;
}

void InfoEspecifica::setCodigo(char * pcodigo){
	strcpy_s(this->codigo, pcodigo);
}

void InfoEspecifica::setDescripcion(char * pdescripcion){
	strcpy_s(this->descripcion, pdescripcion);
}

void InfoEspecifica::setListaArticulos(ListaArticulo * plista){
	this->lista = plista;
}

int InfoEspecifica::getNumero(){
	return this->numero;
}

char * InfoEspecifica::getCodigo(){
	return this->codigo;
}

char * InfoEspecifica::getDescripcion(){
	return this->descripcion;
}

ListaArticulo * InfoEspecifica::getListaArticulos(){
	return this->lista;
}

void  InfoEspecifica::cargarArticulos() {
	ListaArticulo * lista = new ListaArticulo();
	int especificas = atoi(this->codigo);
	lista->cargarArticulos(especificas);
	setListaArticulos(lista);
}

/////////////////////////////////////////////////////////////////////////////
char * InfoEspecifica::autoIncrementar()
{
	std::string s = std::to_string(ultimoRegistro() + 1);
	char const *pchar = s.c_str();

	return (char*)s.c_str();
}

int InfoEspecifica::ultimoRegistro()
{
	std::ifstream lectura;
	char numero[15], codigo[15], descripcion[30];

	lectura.open("Ficheros/especificas.txt", std::ios::out | std::ios::in);

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

void InfoEspecifica::convertirAChar(char *palabra, std::string palabraString) {
	palabraString.erase(palabraString.find(' '), 1); //elimina los espacios en blanco que se hacen al principio
	std::memcpy(palabra, palabraString.c_str(), palabraString.size() + 1); // convierte el string en char array
}

int InfoEspecifica::covertirAEntero(char * pcodigo) {
	int num = atoi(pcodigo);
	return num;
}