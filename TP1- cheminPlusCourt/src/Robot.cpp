#include "Robot.h"

Robot::Robot()
{
	constanteK_ = 0;
	chargeMaximale_ = 0;
}


double Robot::getConstanteK() const
{
	return constanteK_;
}

int Robot::getChargeMaximale() const
{
	return chargeMaximale_;;
}

void Robot::afficher()
{
	std::cout << "Robot \n";
}
