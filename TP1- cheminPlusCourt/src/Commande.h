#pragma once
#include "ObjetA.h"
#include "ObjetB.h"
#include "ObjetC.h"
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


private:
	ObjetA* objetA;
	ObjetB* objetB;
	ObjetC* objetC;
};