#include "Robot.h"

Robot::Robot()
{
	constanteK_ = 0;
	chargeMaximale_ = 0;
}


int Robot::getConstanteK() const
{
	return constanteK_;
}

int Robot::getChargeMaximale() const
{
	return chargeMaximale_;;
}
