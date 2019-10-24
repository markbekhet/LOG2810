#pragma once
#include "Robot.h"
class RobotY :public Robot {
public:
	RobotY();
	void setConstanteK(Commande* commande) override;
	void afficher() override;
	friend std::ostream& operator<<(std::ostream& os, RobotY* robot);
};