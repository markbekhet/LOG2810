/*
	* Noms: Cécile Hornecker, Marjorie Pomerleau , Mark Bekhet
	* Matricules: 1783304_1959041_1949264
*/
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

void Objet::augmenterNombre(int facteur) 
{
	nombre_ += facteur;
}
