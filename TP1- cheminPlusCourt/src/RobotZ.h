#pragma once
#include "Robot.h"
class RobotZ : public Robot {
public:
	RobotZ();
	void setConstanteK(Commande* commande) override;
	void afficher() override;

	friend std::ostream& operator<<(std::ostream& os, RobotZ* robot);
};

