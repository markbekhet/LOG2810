#pragma once
#include "ObjetA.h"
#include "ObjetB.h"
#include "ObjetC.h"
class Commande {
public:
	Commande(int nombreA, int nombreB, int nombreC);
	int getMasseTotale();

private:
	ObjetA objetA;
	ObjetB objetB;
	ObjetC objetC;
};