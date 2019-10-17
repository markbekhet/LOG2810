#pragma once
#include "ObjetA.h"
#include "ObjetB.h"
#include "ObjetC.h"
#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <vector>
class Noeud {
public:
	Noeud(std::istream& fichier);
	int getLeNombredeA() const;
	int getLeNombredeB() const;
	int getLeNombredeC() const;
	std::map<Noeud*,int> getVoisins() const;
	void setVoisin(Noeud* unNoeud, int distance);
	int getId() const;
	void insererChemin(std::map<std::vector<Noeud*>, int>& tousLesChemins, std::vector<Noeud*>& previous, Noeud* but, int& distance);
	std::pair<std::vector<Noeud*>,int> cheminMin( std::vector<Noeud*>& previous, Noeud* but, int& distance);
	~Noeud();
	friend std::ostream& operator<<(std::ostream& os, const Noeud* unNoeud);
private:
	std::map<Noeud*, int> lesVoisins_;
	int id_;
	ObjetA* objetA_;
	ObjetB* objetB_;
	ObjetC* objetC_;
	std::pair<std::vector<Noeud*>, int> PlusCourtChemin(std::map<std::vector<Noeud*>,int>& map);



};
