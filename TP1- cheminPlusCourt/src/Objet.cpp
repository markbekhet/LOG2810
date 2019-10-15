#include "Objet.h"

Objet::Objet(int nombre, int masse):nombre_(nombre), masse_(masse)
{
	
}

int Objet::getNombre()
{
	return nombre_;
}

int Objet::getMasse()
{
	return masse_*nombre_;
}

void Objet::diminuerNombre(int facteur)
{
	nombre_ -= facteur;
}
