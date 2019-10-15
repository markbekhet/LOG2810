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

void Commande::afficher()
{
	std::cout << this << std::endl;
}

std::ostream& operator<<(std::ostream& os, Commande* commande)
{
	// TODO: insert return statement here
	os << "Le nombre d'objet de type A dans votre commande est: " << commande->objetA->getNombre() << "\n"
		<< "Le nombre d'objet de type B dans votre commande est: " << commande->objetB->getNombre() << "\n"
		<< "Le nombre d'objet de type C dans votre commande est: " << commande->objetC->getNombre() << "\n"
		<< "pour une masse totale de " << commande->getMasseTotale() ;
	return os;
}
