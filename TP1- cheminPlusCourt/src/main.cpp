#include "Graph.h"

int main() {
	std::ifstream fichier("entrepot.txt");
	//std::cout << "Le fichier est cree" << std::endl;
	Graph leGraph(fichier);
	leGraph.afficher();
}