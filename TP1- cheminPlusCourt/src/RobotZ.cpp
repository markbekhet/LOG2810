#include "RobotZ.h"

RobotZ::RobotZ()
{
	chargeMaximale_ = 25;
}

void RobotZ::setConstanteK(Commande* commande)
{
	constanteK_ = 2.5 + 0.2 * commande->getMasseTotale();
	
}
void RobotZ::afficher()
{
	std::cout << this << std::endl;
}

std::ostream& operator<<(std::ostream& os, RobotZ* robot) {
	os << "Robot Z" << std::endl;
	return os;
}
