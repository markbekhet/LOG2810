#include "Graph.h"

Graph::Graph(std::istream& fichier)
{
	std::string ligne = "";
	do {
		int position = fichier.tellg();
		std::getline(fichier, ligne);
		if (ligne != " ") {
			fichier.seekg(position,fichier.beg);
			Noeud* unNoeud = new Noeud(fichier);
			lesNoeuds.push_back(unNoeud);
		}

	} while (ligne != " ");
	while (!fichier.eof()) {
		int nodeOne;
		int nodeTwo;
		int distance;
		fichier >> nodeOne;
		fichier >> nodeTwo;
		fichier >> distance;
		lesNoeuds[nodeOne]->setVoisin(lesNoeuds[nodeTwo], distance);
		lesNoeuds[nodeTwo]->setVoisin(lesNoeuds[nodeOne], distance);
	}
}

void Graph::afficher() const
{
	for (auto node : lesNoeuds) {
		std::cout << node;
	}
}

Graph::~Graph()
{
	for (auto noeud : lesNoeuds) {
		delete noeud;
	}
}
