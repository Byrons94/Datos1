#pragma once
#include "stdafx.h"
#include "InfoEspecifica.h"
class NodoEspecifica
{
	NodoEspecifica * sgte;
	NodoEspecifica *ante;
	InfoEspecifica * info;

public:
	NodoEspecifica();
	NodoEspecifica(InfoEspecifica *);
	~NodoEspecifica();

	void setSgte(NodoEspecifica *);
	void setAnte(NodoEspecifica *);
	void setInfo(InfoEspecifica *);

	NodoEspecifica * getSgte();
	NodoEspecifica * getAnte();
	InfoEspecifica * getInfo();

};

