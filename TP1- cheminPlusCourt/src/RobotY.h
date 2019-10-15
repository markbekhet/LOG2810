#pragma once
#include "Robot.h"
class RobotY :public Robot {
public:
	RobotY();
	void setConstanteK(Commande* commande) override;
};