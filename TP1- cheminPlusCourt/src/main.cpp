#include "Graph.h"
#include"Commande.h"
#include "Noeud.h"
#include <chrono>
#include <ctime>
int main() {
	//Le chrono va m'aider a savoir la vitesse de l'execution du programme
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	//test de l'affichage du graph
	std::ifstream fichier("entrepot.txt");
	
	Graph leGraph(fichier);
	leGraph.afficher();

	//test de l'affichage de la commande
	Commande uneCommande(5, 6, 2);
	uneCommande.afficher();
	//test de l'implementation de l'algo de Djikstra
	// Celui la est un test pour voir le fonctionnement de l'algorithm ecrit hier et c'est l'implementation de la fonction pour collecter tous les chemins possibles 
	//du parcours
	Noeud* unNoeud = leGraph.getNoeud(0);
	for (auto Node : leGraph.getLesNoeuds()) {
		
		std::pair<std::vector<Noeud*>, int> test = unNoeud->cheminMin(Node);
		//affichage de tous les noeud du chemin afin de le comparer avec le Graph de l'enonce
		for (auto noeud : test.first) {
			std::cout << noeud << std::endl;
		}

		std::cout << "La distance : " << test.second << std::endl;
	}
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "Le temps d'execution en seconde = " << elapsed_seconds.count() <<" s" <<std::endl;
	return 0;
}