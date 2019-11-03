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
	int getLaDistanceDeZero(Noeud* noeud);
	~Graph();
private:
	std::vector<Noeud*> lesNoeuds;
	std::map<int, int> distanceDeZero;
};