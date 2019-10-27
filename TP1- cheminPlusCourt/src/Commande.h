#pragma once
#include "ObjetA.h"
#include "ObjetB.h"
#include "ObjetC.h"

#include <iostream>
class Commande {
public:
	
	Commande();
	Commande(int nombreA, int nombreB, int nombreC);
	Commande(Commande* commande);
	int getMasseTotale();
	int getNombreObjetA() const;
	void diminuerNombreObjetA(int facteur);
	void augmenterNombreObjetA(int facteur);
	int getNombreObjetB() const;
	void diminuerNombreObjetB(int facteur);
	void augmenterNombreObjetB(int facteur);
	int getNombreObjetC() const;
	void diminuerNombreObjetC(int facteur);
	void augmenterNombreObjetC(int facteur);
	Commande operator = (Commande* commande);
	void afficher();
	~Commande();
	
	friend std::ostream& operator <<(std::ostream& os, Commande* commande);
	bool plusGrandOuEgal (const Commande* commandeVoulue);


private:
	ObjetA* objetA;
	ObjetB* objetB;
	ObjetC* objetC;
};
