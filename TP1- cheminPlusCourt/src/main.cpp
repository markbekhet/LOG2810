#include "Graph.h"
#include"Commande.h"
#include "Noeud.h"
int main() {
	//test de l'affichage du graph
	std::ifstream fichier("entrepot.txt");
	//std::cout << "Le fichier est cree" << std::endl;
	Graph leGraph(fichier);
	leGraph.afficher();

	//test de l'affichage de la commande
	Commande uneCommande(5, 6, 2);
	uneCommande.afficher();
	//test de l'implementation de l'algo de Djikstra
	Noeud* unNoeud = leGraph.getNoeud(0);
	
	std::vector<Noeud*>unVect{ unNoeud };
	Noeud* autreNoeud = leGraph.getNoeud(20);
	int distance = 0;
	
	
	std::pair<std::vector<Noeud*>, int> test = unNoeud->cheminMin(unVect, autreNoeud,distance);
	for (auto noeud : test.first) {
		std::cout << noeud << std::endl;
	}
	
	std::cout <<"La distance : " <<test.second << std::endl;
	return 0;
}