#pragma once
#include "ObjetA.h"
#include "ObjetB.h"
#include "ObjetC.h"
#include <iostream>
#include <fstream>
#include <map>
#include <utility>
class Noeud {
public:
	Noeud(std::istream& fichier);
	int getLeNombredeA() const;
	int getLeNombredeB() const;
	int getLeNombredeC() const;
	std::map<Noeud*,int> getVoisins() const;
	void setVoisin(Noeud* unNoeud, int distance);
	friend std::ostream& operator<<(std::ostream& os, const Noeud* unNoeud);
private:
	std::map<Noeud*, int> lesVoisins_;
	int id_;
	ObjetA* objetA_;
	ObjetB* objetB_;
	ObjetC* objetC_;



};
