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
	//leGraph->afficher();

	//test de l'affichage de la commande
	Commande* uneCommande = new Commande(5,0,0);
	
	//uneCommande->afficher();
	
	RobotX* robotX = new RobotX();
	RobotY* robotY = new RobotY();
	RobotZ* robotZ = new RobotZ();
	std::vector<Robot*> robot;
	robot.push_back(robotX);
	robot.push_back(robotY);
	robot.push_back(robotZ);
	try {
		Parcours* parcours = new Parcours(leGraph, uneCommande, robot);
		if (parcours->choisirRobotSelonMasse() != NULL) {
			parcours->afficher();
		}
		
	}
	catch (PasDeRobot e) {
		std::cout << e.what() << "\n";
	}
	
	

	


	
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "Le temps d'execution en seconde = " << elapsed_seconds.count() <<" s" <<std::endl;
	return 0;
}