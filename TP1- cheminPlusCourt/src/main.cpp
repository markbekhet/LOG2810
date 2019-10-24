#include "Graph.h"
#include"Commande.h"
#include "Noeud.h"
#include <chrono>
#include <ctime>
#include "Parcours.h"
#include "RobotX.h"
#include "RobotY.h"
#include "RobotZ.h"

Commande* entrerUneCommande() {
	int nombreObjetA;
	int nombreObjetB;
	int nombreObjetC;
	std::cout << "Entrer le nombre d'objet A : ";
	std::cin >> nombreObjetA;
	std::cout << "\n";
	std::cout << "Entrer le nombre d'objet B : ";
	std::cin >> nombreObjetB;
	std::cout << "\n";
	std::cout << "Entrer le nombre d'objet C : ";
	std::cin >> nombreObjetC;
	std::cout << "\n";
	return new Commande(nombreObjetA, nombreObjetB, nombreObjetC);
}
int main() {
	//Le chrono va m'aider a savoir la vitesse de l'execution du programme
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	//test de l'affichage du graph
	std::ifstream fichier("entrepot.txt");
	
	Graph* leGraph = new Graph(fichier);
	leGraph->afficher();

	//test de l'affichage de la commande
	Commande* uneCommande = new Commande(1,1,1);
	
	//uneCommande->afficher();*/
	
	RobotX* robotX = new RobotX();
	RobotY* robotY = new RobotY();
	RobotZ* robotZ = new RobotZ();
	std::vector<Robot*> robot;
	robot.push_back(robotX);
	robot.push_back(robotY);
	robot.push_back(robotZ);
	Parcours* parcours = new Parcours(leGraph, uneCommande, robot);
	parcours->afficher();

	std::cout << "La charge maximale du robot X est " << robot[0]->getChargeMaximale() << std::endl;
	std::cout << "La charge maximale du robot Y est " << robot[1]->getChargeMaximale() << std::endl;
	std::cout << "La charge maximale du robot Z est " << robot[2]->getChargeMaximale() << std::endl;


	//test de la fonction recursive qui nous donne tous les chemins possibles d'un noeud a un autre
	
	
	/*Noeud* unNoeud = leGraph->getNoeud(0);
	Noeud* autreNoeud = leGraph->getNoeud(6);
	
	
	std::map<std::vector<Noeud*>, int> NoeudVersAutreNoeud = unNoeud->tousLesChemins(autreNoeud);
	for (auto possibility : NoeudVersAutreNoeud) {
		std::cout << " Le chemin du ";
		for (auto Node : possibility.first) {
			std::cout << Node->getId() << " vers ";
		}
		std::cout << "\n . La distance totale de cette possibilite est " << possibility.second<<std::endl;
	}*/
	
	
	/*
		* Test de la fonction qui nous donne la distance vers le voisin. Cette fonction va etre utile dans le retour du robot.
	*/
	/*for (auto Node : leGraph->getLesNoeuds()) {
		
		std::pair<Noeud*, int> test = unNoeud->cheminVoisin(Node);
		std::cout << "La distance du noeud " <<unNoeud->getId()<<" jusqu'a "<<Node->getId()<<" est : "<< test.second << std::endl;
	}*/
	// Ce bloc sert seulement pour mesurer le temps d'execution du programme , ce code se trouve sur geeksforgeeks en ligne
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "Le temps d'execution en seconde = " << elapsed_seconds.count() <<" s" <<std::endl;
	return 0;
}