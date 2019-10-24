#include "RobotX.h"

RobotX::RobotX()
{
	chargeMaximale_ = 5;
}
void RobotX::setConstanteK(Commande* commande) {
	constanteK_ = 1.0 + commande->getMasseTotale();
	
}
void RobotX::afficher()
{
	std::cout << this << std::endl;
}


std::ostream& operator<<(std::ostream& os, RobotX* robot)
{
	// TODO: insert return statement her
	os << "robot X" << std::endl;
	return os;
}
