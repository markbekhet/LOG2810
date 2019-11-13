/*
	* Noms: Cécile Hornecker, Marjorie Pomerleau , Mark Bekhet
	* Matricules: 1783304_1959041_1949264
*/
#pragma once
#include <iostream>
#include "Commande.h"


class Robot {
public:
	Robot();
	virtual void setConstanteK(Commande* uneCommande) = 0;
	double getConstanteK() const;
	int getChargeMaximale() const;
	virtual void afficher() ;
	

protected:
	double constanteK_;
	int chargeMaximale_;

};