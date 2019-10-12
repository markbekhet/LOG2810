#include "Objet.h"

Objet::Objet(int nombre):nombre_(nombre)
{
	masse_ = 0;
}

int Objet::getNombre()
{
	return nombre_;
}

int Objet::getMasse()
{
	return masse_;
}
