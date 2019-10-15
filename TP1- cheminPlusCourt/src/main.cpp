#include "Graph.h"
#include"Commande.h"
int main() {
	//test de l'affichage du graph
	std::ifstream fichier("entrepot.txt");
	//std::cout << "Le fichier est cree" << std::endl;
	Graph leGraph(fichier);
	leGraph.afficher();

	//test de l'affichage de la commande
	Commande uneCommande(5, 6, 2);
	uneCommande.afficher();
}