#include "RobotY.h"

RobotY::RobotY()
{
	chargeMaximale_ = 10;
}

void RobotY::setConstanteK(Commande* commande)
{
	constanteK_ = 1.5 + (0.6 * commande->getMasseTotale());
	
}

void RobotY::afficher()
{
	std::cout << this << std::endl;
}

std::ostream& operator<<(std::ostream& os, RobotY* robot)
{
	// TODO: insert return statement here
	os << "robot Y" << std::endl;
	return os;
}
