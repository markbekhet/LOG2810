#pragma once
#include "Robot.h"
class RobotX : public Robot{
public:
	RobotX();
	void setConstanteK(Commande* commande) override;
};
