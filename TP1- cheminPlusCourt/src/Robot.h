#pragma once
#include <iostream>
#include "Commande.h"


class Robot {
public:
	Robot();
	virtual void setConstanteK(Commande* uneCommande);
	virtual int getChargeMaximale();
	virtual int getConstanteK();

private:
	double constanteK;
	int chargeMaximale;

};