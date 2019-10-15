#include "RobotX.h"

RobotX::RobotX()
{
	chargeMaximale_ = 5;
}
void RobotX::setConstanteK(Commande* commande) {
	constanteK_ = 1.0 + commande->getMasseTotale();
}
