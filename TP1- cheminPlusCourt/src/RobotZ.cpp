#include "RobotZ.h"

RobotZ::RobotZ()
{
	chargeMaximale_ = 25;
}

void RobotZ::setConstanteK(Commande* commande)
{
	constanteK_ = 2.5 + 0.2 * commande->getMasseTotale();
}
