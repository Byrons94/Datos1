#pragma once
#include "Infousuario.h"

class NodoUsuario
{
	NodoUsuario * sgte;
	InfoUsuario *info;

public:
	NodoUsuario();
	NodoUsuario(InfoUsuario *);
	~NodoUsuario();

	void setSgte(NodoUsuario *);
	void setInfo(InfoUsuario *);

	NodoUsuario * getSgte();
	InfoUsuario * getInfo();

};

