#pragma once
#include <iostream>
#include "Commande.h"


class Robot {
public:
	Robot();
	virtual void setConstanteK(Commande* uneCommande);
	int getConstanteK() const;
	int getChargeMaximale() const;
	

protected:
	double constanteK_;
	int chargeMaximale_;

};