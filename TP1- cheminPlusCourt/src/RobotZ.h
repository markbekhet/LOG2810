#pragma once
#include "Robot.h"
class RobotZ : public Robot {
public:
	RobotZ();
	void setConstanteK(Commande* commande) override;
};

