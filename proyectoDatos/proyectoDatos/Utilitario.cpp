#include "Utilitario.h"


char * Utilitario::toChar(System::String ^ variable){
	char * charReturn = (char*)(void*)Marshal::StringToHGlobalAnsi(variable);
	return charReturn;
}

int Utilitario::toInt(System::Int32 ^ variable){
	int intReturn = (int)variable;
	return intReturn;
}

System::String ^ Utilitario::toSystemString(char * variable){
	System::String ^ retorno = gcnew System::String(variable);
	return retorno;
}

System::Int32 ^ Utilitario::toInt32(int numero){
	System::Int32  valor = numero;
	return valor;
}

char * Utilitario::intToChar(int numero){
	System::String^	var = System::Convert::ToString(numero);
	return toChar(var);
}

double Utilitario::toDouble(System::String ^ variable){
	double foo = System::Convert::ToDouble(variable);
	return foo;
}

System::String ^ Utilitario::Contanenado(char * codigo, char * nombre){
	char  a[60];
	strcpy_s(a, codigo);
	strcat_s(a, "-");
	strcat_s(a, nombre);
	return toSystemString(a);
}

char * Utilitario::getElementCode(System::String ^ variable){
	System::String^ codigo = variable->Split('-')[0];
	return toChar(codigo);;
}

ListaGenerales *Utilitario::getGeneral(char * pcodigoPasillo, ListaPasillos *lista) {
	ListaGenerales * listag = NULL;
	NodoPasillo * nodoPasillo = lista->getCab();
	while (nodoPasillo != NULL) {
		char * codigoPasillo = nodoPasillo->getInfoPasillo()->getCodigo();
		if (strcmp(codigoPasillo, pcodigoPasillo) == 0) {
			listag = nodoPasillo->getInfoPasillo()->getListaGeneral();
			return listag;
		}
		nodoPasillo = nodoPasillo->getSgte();
	}
	return listag;
}

ListaEspecifica *Utilitario::getEspecificas(char * pcodigoGenerales, ListaPasillos *lista) {
		ListaEspecifica * listae = NULL;
		NodoPasillo * nodoPasillo = lista->getCab();
		while (nodoPasillo != NULL) {
			NodoGenerales * nodoGeneral = nodoPasillo->getInfoPasillo()->getListaGeneral()->getCab();
			while (nodoGeneral != NULL) {
				char * codGeneral = nodoGeneral->getInfo()->getCodigo();
				if (strcmp(codGeneral, pcodigoGenerales) == 0) {
					listae = nodoGeneral->getInfo()->getListaEspecifica();
					return listae;
				}
				nodoGeneral = nodoGeneral->getSgte();
			}
			nodoPasillo = nodoPasillo->getSgte();
		}
		return listae;
	}

  ListaArticulo *Utilitario::getArticulos(char * pcodigoEspecifica, ListaPasillos *lista) {
		ListaArticulo * listaA = NULL;
		NodoPasillo * nodoPasillo = lista->getCab();
		while (nodoPasillo != NULL) {
			NodoGenerales * nodoGeneral = nodoPasillo->getInfoPasillo()->getListaGeneral()->getCab();
			while (nodoGeneral != NULL) {
				NodoEspecifica * nodoE = nodoGeneral->getInfo()->getListaEspecifica()->getCab();
				while (nodoE != NULL) {
					char *codigoEspecifica = nodoE->getInfo()->getCodigo();
					if (strcmp(codigoEspecifica, pcodigoEspecifica) == 0) {
						listaA = nodoE->getInfo()->getListaArticulos();
					}
					nodoE = nodoE->getSgte();
				}
				nodoGeneral = nodoGeneral->getSgte();
			}
			nodoPasillo = nodoPasillo->getSgte();
		}
		return listaA;
	}


