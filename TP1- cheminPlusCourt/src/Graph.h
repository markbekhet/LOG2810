/*
	* Noms: Cécile Hornecker, Marjorie Pomerleau , Mark Bekhet
	* Matricules: 1783304_1959041_1949264
*/
#pragma once
#include <vector>
#include "Noeud.h"
#include <string>

class Graph {
public:
	Graph(std::istream& fichier);
	Graph(Graph* graph);
	void afficher() const;
	Noeud* getNoeud(int index) const;
	std::vector<Noeud*> getLesNoeuds() const;
	~Graph();
private:
	std::vector<Noeud*> lesNoeuds;
};