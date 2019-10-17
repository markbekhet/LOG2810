#pragma once
#include "ObjetA.h"
#include "ObjetB.h"
#include "ObjetC.h"
#include <iostream>
class Commande {
public:
	Commande(int nombreA, int nombreB, int nombreC);
	int getMasseTotale();
	int getNombreObjetA();
	void diminuerNombreObjetA(int facteur);
	int getNombreObjetB();
	void diminuerNombreObjetB(int facteur);
	int getNombreObjetC();
	void diminuerNombreObjetC(int facteur);
	
	void afficher();
	~Commande();
	friend std::ostream& operator<<(std::ostream& os, Commande* commande);


private:
	ObjetA* objetA;
	ObjetB* objetB;
	ObjetC* objetC;
};