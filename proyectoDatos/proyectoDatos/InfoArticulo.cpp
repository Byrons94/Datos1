#include "InfoArticulo.h"


InfoArticulo::InfoArticulo(){
	setCodigo ("");
	setNombre ("");
	setMarca  ("");
	setTamanio(0);
	setPrecio (0);
}
InfoArticulo::~InfoArticulo(){}


InfoArticulo::InfoArticulo(int codigoLinea, char *pcodigo, char *pnombre, char *pmarca, char * ptamanio, double pprecio){
	setCodLinea(codigoLinea);
	setCodigo(pcodigo);
	setNombre(pnombre);
	setMarca(pmarca);
	setTamanio(ptamanio);
	setPrecio(pprecio);
}

InfoArticulo::InfoArticulo(int codigoLinea,  char *pnombre, char *pmarca, char * ptamanio, double pprecio) {
	setCodLinea(codigoLinea);
	setCodigo(autoIncrementar());
	setNombre(pnombre);
	setMarca(pmarca);
	setTamanio(ptamanio);
	setPrecio(pprecio);
}

void InfoArticulo::setCodLinea(int plinea){
	this->lineaEspecifica = plinea;
}

void InfoArticulo::setCodigo(char *pcodigo){
	strcpy_s(this->codigo, pcodigo);
}

void InfoArticulo::setNombre(char *pnombre){
	strcpy_s(this->nombre, pnombre);
}

void InfoArticulo::setMarca(char *pmarca){
	strcpy_s(this->marca, pmarca);
}

void InfoArticulo::setTamanio(char * ptamanio){
	strcpy_s(this->tamanio, ptamanio);
}


void InfoArticulo::setPrecio(double pprecio){
	this->precio = pprecio;
}

int InfoArticulo::getCodlinea(){
	return this->lineaEspecifica;
}

char * InfoArticulo::getCodigo(){
	return this->codigo;
}

char * InfoArticulo::getNombre(){
	return this->nombre;
}

char * InfoArticulo::getMarca(){
	return this->marca;
}

char * InfoArticulo::getTamanio(){
	return this->tamanio;
}

double InfoArticulo::getPrecio(){
	return this->precio;
}

char * InfoArticulo::autoIncrementar()
{
	std::string s = std::to_string(ultimoRegistro() + 1);
	char const *pchar = s.c_str();

	return (char*)s.c_str();
}

int InfoArticulo::ultimoRegistro()
{
	std::ifstream lectura;
	char lineaEsp[30], codigo[30], nombre[30], marca[30], tamanio[30], precio[15];
	lectura.open("Ficheros/articulos.txt", std::ios::out | std::ios::in);

	if (lectura.is_open()) {
		lectura >> codigo;  //primer registro de la linea
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

			lectura >> lineaEsp;
		}

		lectura.close();
		return covertirAEntero(codigo);
	}
	else {
		return covertirAEntero(0);
	}

}

void InfoArticulo::convertirAChar(char *palabra, std::string palabraString) {
	palabraString.erase(palabraString.find(' '), 1); //elimina los espacios en blanco que se hacen al principio
	std::memcpy(palabra, palabraString.c_str(), palabraString.size() + 1); // convierte el string en char array
}

int InfoArticulo::covertirAEntero(char * pcodigo) {
	int num = atoi(pcodigo);
	return num;
}
