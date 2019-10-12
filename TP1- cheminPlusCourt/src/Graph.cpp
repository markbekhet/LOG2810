#include "Graph.h"

bool isEmpty(std::string mot) {
	for (int i = 0; i < mot.length(); ++i) {
		if (mot[i] != ' ') return false;
		
	}
	return true;
}

Graph::Graph(std::istream& fichier)
{
	std::string ligne ;
	bool finish = true;
	
	do {
		
		
		int position = fichier.tellg();
		std::getline(fichier, ligne);
		std::cout << "Le fichier est rendu "<<fichier.tellg() << std::endl;
		
		if (!isEmpty(ligne) ) {
			finish = false;
			fichier.seekg(position, fichier.beg);
			Noeud* unNoeud = new Noeud(fichier);
			
			std::cout << unNoeud << std::endl;
			lesNoeuds.push_back(unNoeud);
		}
		else {
			finish = true;
		}
		std::getline(fichier, ligne);
		
	} while (!finish);
	//std::getline(fichier, ligne);
	

	while (!fichier.eof()) {
		char virgule;
		int nodeOne = 0;
		fichier >> nodeOne;
		fichier >> virgule;
		int nodeTwo = 0;
		fichier >> nodeTwo;
		fichier >> virgule;
		int distance;
		//fichier >> nodeOne;
		//fichier >> nodeTwo;
		fichier >> distance;
		std::cout << "node One : " << nodeOne << " ,node Two : " << nodeTwo << std::endl;
		lesNoeuds[nodeOne]->setVoisin(lesNoeuds[nodeTwo], distance);
		lesNoeuds[nodeTwo]->setVoisin(lesNoeuds[nodeOne], distance);
		std::getline(fichier, ligne);
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
