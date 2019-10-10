#pragma once
#include "Objet.h"

class ObjetB :public Objet {
public:
	ObjetB(int nombre);
	int getNombre();
	int getMasse();
};