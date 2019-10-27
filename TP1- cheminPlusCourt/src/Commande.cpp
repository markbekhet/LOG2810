#include "Commande.h"

Commande::Commande():objetA(new ObjetA(0)), objetB(new ObjetB(0)), objetC(new ObjetC(0))
{
}

Commande::Commande(int nombreA, int nombreB, int nombreC)
{
	objetA = new ObjetA(nombreA);
	objetB = new ObjetB(nombreB);
	objetC = new ObjetC(nombreC);
}

Commande::Commande(Commande* commande): objetA (new ObjetA(commande->getNombreObjetA())),objetB(new ObjetB(commande->getNombreObjetB())),
objetC(new ObjetC(commande->getNombreObjetC()))
{
	

}

int Commande::getMasseTotale() {
	
	return objetA->getMasse() + objetB->getMasse() + objetC->getMasse();
}

int Commande::getNombreObjetA() const
{
	return objetA->getNombre();
}

void Commande::diminuerNombreObjetA(int facteur)
{
	objetA->diminuerNombre(facteur);
}

void Commande::augmenterNombreObjetA(int facteur) 
{
	objetA->augmenterNombre(facteur);
}

int Commande::getNombreObjetB() const
{
	return objetB->getNombre();
}

void Commande::diminuerNombreObjetB(int facteur)
{
	objetB->diminuerNombre(facteur);
}

void Commande::augmenterNombreObjetB(int facteur)
{
	objetB->augmenterNombre(facteur);
}

int Commande::getNombreObjetC() const
{
	return objetC->getNombre();
}

void Commande::diminuerNombreObjetC(int facteur)
{
	objetC->diminuerNombre(facteur);
}

void Commande::augmenterNombreObjetC(int facteur)
{
	objetC->augmenterNombre(facteur);
}

Commande Commande::operator=(Commande* commande)
{
	 
	return Commande(commande->getNombreObjetA(), commande->getNombreObjetB(), commande->getNombreObjetC());
}

void Commande::afficher()
{
	std::cout << this << std::endl;
}

Commande::~Commande()
{
	delete objetA;
	delete objetB;
	delete objetC;
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

bool Commande::plusGrandOuEgal( const Commande* commandeVoulue)
{
	bool nombreObjetA = objetA->getNombre() >= commandeVoulue->getNombreObjetA();
	bool nombreObjetB = objetB->getNombre() >= commandeVoulue->getNombreObjetB();
	bool nombreObjetC = objetC->getNombre() >= commandeVoulue->getNombreObjetC();
	return nombreObjetA && nombreObjetB && nombreObjetC;
}
