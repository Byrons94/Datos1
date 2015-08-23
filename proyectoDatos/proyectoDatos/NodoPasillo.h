#pragma once
#include "stdafx.h"
#include "InfoPasillo.h"

class NodoPasillo
{
private:
	InfoPasillo *infoPasillo;
	NodoPasillo *sgte;
	NodoPasillo *ante;

public:
	NodoPasillo();
	NodoPasillo(InfoPasillo*);
	~NodoPasillo();

	void setInfoPasillo(InfoPasillo *);
	void setSgte(NodoPasillo *);
	void setAnte(NodoPasillo *);

	InfoPasillo * getInfoPasillo();
	NodoPasillo * getAnte();
	NodoPasillo * getSgte();

};


