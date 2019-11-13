/*
	* Noms: Cécile Hornecker, Marjorie Pomerleau , Mark Bekhet
	* Matricules: 1783304_1959041_1949264
*/
#pragma once
#include "Robot.h"
class RobotY :public Robot {
public:
	RobotY();
	void setConstanteK(Commande* commande) override;
	void afficher() override;
	friend std::ostream& operator<<(std::ostream& os, RobotY* robot);
};