#pragma once
#include <vector>
#include "Noeud.h"
#include <string>

class Graph {
public:
	Graph(std::istream& fichier);
	void afficher() const;
	Noeud* getNoeud(int index) const;
	std::vector<Noeud*> getLesNoeuds() const;
	~Graph();
private:
	std::vector<Noeud*> lesNoeuds;
};