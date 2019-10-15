#include "Commande.h"

Commande::Commande(int nombreA, int nombreB, int nombreC)
{
	objetA = new ObjetA(nombreA);
	objetB = new ObjetB(nombreB);
	objetC = new ObjetC(nombreC);
}

int Commande::getMasseTotale() {
	
	return objetA->getMasse() + objetB->getMasse() + objetC->getMasse();
}

int Commande::getNombreObjetA()
{
	return objetA->getNombre();
}

void Commande::diminuerNombreObjetA(int facteur)
{
	objetA->diminuerNombre(facteur);
}

int Commande::getNombreObjetB()
{
	return objetB->getNombre();
}

void Commande::diminuerNombreObjetB(int facteur)
{
	objetB->diminuerNombre(facteur);
}

int Commande::getNombreObjetC()
{
	return objetC->getNombre();
}

void Commande::diminuerNombreObjetC(int facteur)
{
	objetC->diminuerNombre(facteur);
}

