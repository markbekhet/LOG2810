#include "RobotY.h"

RobotY::RobotY()
{
	chargeMaximale_ = 10;
}

void RobotY::setConstanteK(Commande* commande)
{
	constanteK_ = 1.5 + 0.6 * commande->getMasseTotale();
}

