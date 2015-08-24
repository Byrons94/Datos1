#include "InfoCarrito.h"

InfoCarrito::InfoCarrito(){
	setCodigo("");
	setNombre("");
	setCodClie("");
	setEstado(false);
	setMonto(0); 
	setListaCompra(NULL);
}

InfoCarrito::InfoCarrito(char * pCodigo, char * pCodClie, ListaCompra * plista){
	setCodigo(pCodigo);
	setNombre("");
	setCodClie(pCodClie);
	setEstado(false);
	setMonto(0);
	setListaCompra(plista);
}

InfoCarrito::InfoCarrito(char * pCodigo, char * pNombre, char * pCodClie , bool pEntregado, 
							double pmonto, ListaCompra * plista){
	setCodigo(pCodigo);
	setNombre(pNombre);
	setCodClie(pCodClie);
	setEstado(pEntregado);
	setMonto(pmonto);
	setListaCompra(plista);
}

InfoCarrito::InfoCarrito( char * pNombre, char * pCodClie, bool pEntregado,
	double pmonto, ListaCompra * plista) {
	setCodigo(autoIncrementar());
	setNombre(pNombre);
	setCodClie(pCodClie);
	setEstado(pEntregado);
	setMonto(pmonto);
	setListaCompra(plista);
}

InfoCarrito::~InfoCarrito(){}

void InfoCarrito::setCodigo(char * pCodigo){
	strcpy_s(this->codigo, pCodigo);
}

void InfoCarrito::setNombre(char * pNombre){
	strcpy_s(this->nombre, pNombre);
}

void InfoCarrito::setCodClie(char * pCodClie){
	strcpy_s(this->codCliente, pCodClie);
}

void InfoCarrito::setEstado(bool pEstado){
	this->estado = pEstado;
}

void InfoCarrito::setMonto(double pMonto){
	this->monto = pMonto;
}

void InfoCarrito::setListaCompra(ListaCompra * pLista){
	this->lista = pLista;
}

char * InfoCarrito::autoIncrementar()
{
	std::string s = std::to_string(ultimoRegistro()+1);
	char const *pchar = s.c_str(); 

	return (char*)s.c_str();
}

char * InfoCarrito::getCodigo(){
	return this->codigo;
}

char * InfoCarrito::getNombre(){
	return this->nombre;
}

char * InfoCarrito::getCodClie(){
	return this->codCliente;
}

bool InfoCarrito::getEstado(){
	return this->estado;
}

double InfoCarrito::getMonto(){
	return this->monto;
}

ListaCompra * InfoCarrito::getListaCompra(){
	return this->lista;
}

int InfoCarrito::ultimoRegistro()
{
	std::ifstream lectura;
	char codigo[15], codCliente[15], nombre[30], estado[5], monto[15];

	lectura.open("Ficheros/carritos.txt", std::ios::out | std::ios::in);

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

			lectura >> codigo;
		}

		lectura.close();
		return covertirAEntero(codigo);
	}
	else {
		return covertirAEntero(0);
	}

}

void InfoCarrito::convertirAChar(char *palabra, std::string palabraString) {
	palabraString.erase(palabraString.find(' '), 1); //elimina los espacios en blanco que se hacen al principio
	std::memcpy(palabra, palabraString.c_str(), palabraString.size() + 1); // convierte el string en char array
}

int InfoCarrito::covertirAEntero(char * pcodigo) {
	int num = atoi(pcodigo);
	return num;
}