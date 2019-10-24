#pragma once
#include <iostream>
#include "Commande.h"


class Robot {
public:
	Robot();
	virtual void setConstanteK(Commande* uneCommande) = 0;
	int getConstanteK() const;
	int getChargeMaximale() const;
	virtual void afficher() ;
	

protected:
	double constanteK_;
	int chargeMaximale_;

};