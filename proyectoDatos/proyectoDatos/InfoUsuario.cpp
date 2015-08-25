#include "InfoUsuario.h"
#include "ListaUsuario.h"


InfoUsuario::InfoUsuario(){
	setCodigo("");
	setNombre("");
	setContrasenna("");
	setRol(0);
}

InfoUsuario::InfoUsuario(char * pcodigo, char * pnombre, char * pcontrasenna, int prol){
	setCodigo(pcodigo);
	setNombre(pnombre);
	setContrasenna(pcontrasenna);
	setRol(prol);
}

InfoUsuario::InfoUsuario( char * pnombre, char * pcontrasenna, int prol) {
	setCodigo(autoIncrementar());
	setNombre(pnombre);
	setContrasenna(pcontrasenna);
	setRol(prol);
}


InfoUsuario::~InfoUsuario()
{}

void InfoUsuario::setCodigo(char * pcodigo){
	strcpy_s(this->codigo, pcodigo);
}

void InfoUsuario::setNombre(char * pNombre){
	strcpy_s(this->nombre, pNombre);
}

void InfoUsuario::setContrasenna(char * pContrasenna){
	strcpy_s(this->contrasenna, pContrasenna);
}

void InfoUsuario::setRol(int pRol){
	this->rol = pRol;
}

char * InfoUsuario::getCodigo(){
	return this->codigo;
}

char * InfoUsuario::getNombre(){
	return this->nombre;
}

char * InfoUsuario::getContrasenna(){
	return this->contrasenna;
}

int InfoUsuario::getRol(){
	return this->rol;
}


/////////////////////////////////////////////////////////////////////////////
char * InfoUsuario::autoIncrementar()
{
	//std::string s = std::to_string(ultimoRegistro() + 1);
	//char const *pchar = s.c_str();

	

	std::string str = std::to_string(ultimoRegistro() + 1);
	char perrito[15];
	strcpy_s(perrito, str.c_str());

	return perrito;

	/*if (ultimoRegistro() == 789)
	{
		return "Bien";
	}else{
		return "Mamo";
	}*/
}

int InfoUsuario::ultimoRegistro()
{
	std::ifstream lectura;
	char codigo[30], nombre[30], contrasena[30], rol[5];
	char *aux = "";
	
	lectura.open("Ficheros/usuarios.txt", std::ios::out | std::ios::in);

	if (lectura.is_open()) {

		lectura >> codigo;  //primer registro de la linea
		std::string linea;		//contador de las lineas del documento
		while (getline(lectura, linea)) {
			std::stringstream ss(linea); //nos da un el elemento por linea
			std::string palabraString;   // lo definimos para almacenar el dato del txt

			std::string str(codigo);
			str.erase(str.find(';'));
			strcpy_s(codigo, str.c_str());

			//convertirAChar(aux, palabraString);

			getline(ss, palabraString, ';');
			convertirAChar(nombre, palabraString);

			getline(ss, palabraString, ';');
			convertirAChar(contrasena, palabraString);

			getline(ss, palabraString, ';');
			convertirAChar(rol, palabraString);

			aux = codigo;

			lectura >> codigo;
		}

		lectura.close();
		return covertirAEntero(aux);
	}
	else {
		return covertirAEntero(0);
	}

}

void InfoUsuario::convertirAChar(char *palabra, std::string palabraString) {
	palabraString.erase(palabraString.find(' '), 1); //elimina los espacios en blanco que se hacen al principio
	std::memcpy(palabra, palabraString.c_str(), palabraString.size() + 1); // convierte el string en char array
}

int InfoUsuario::covertirAEntero(char * pcodigo) {
	int num = atoi(pcodigo);
	return num;
}