/*
	* Noms: Cécile Hornecker, Marjorie Pomerleau , Mark Bekhet
	* Matricules: 1783304_1959041_1949264
*/
#pragma once
#include "Robot.h"
class RobotX : public Robot{
public:
	RobotX();
	void setConstanteK(Commande* commande) override;
	void afficher() override;

	friend std::ostream& operator<<(std::ostream& os, RobotX* robot);
};
