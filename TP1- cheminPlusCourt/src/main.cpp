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

void afficherOption() {
	std::cout << "Choisir entre afficher graph (a) , entrer une commande (b) et afficher la commande (c), afficher le parcours (d) ou quitter (q). \n";
}
int main() {
	//Le chrono va m'aider a savoir la vitesse de l'execution du programme
	
	//test de l'affichage du graph
	bool continuer = false;
	std::string nom = "";
	Graph* leGraph = NULL;
	Graph* copieGraph = NULL;

	while (!continuer) {
		std::wcout << "Veuillez entrer le nom de votre fichier incluant l'extension \n";
		std::cin >> nom;
		
		std::ifstream fichier;
		
		fichier.open(nom);
		if (fichier.fail()) {
			std::cout << "Le nom de votre fichier semble incorrect  ou le format du fichier n'est pas bon \n";
		}
		else {
			leGraph = new Graph(fichier);
			copieGraph = new Graph(leGraph);
			continuer = true;

		}

	}
	
	
	 
	

	//test de l'affichage de la commande
	
	bool quitter = false;
	//uneCommande->afficher();
	
	RobotX* robotX = new RobotX();
	RobotY* robotY = new RobotY();
	RobotZ* robotZ = new RobotZ();
	std::vector<Robot*> robot;
	robot.push_back(robotX);
	robot.push_back(robotY);
	robot.push_back(robotZ);


	// Le code pour le main
	
	Commande* uneCommande = NULL;
	Parcours* parcours = NULL;
	
	
	while (!quitter) {
		afficherOption();
		char choix;
		std::cin >> choix;
		
		if (choix == 'a') {
			
			copieGraph->afficher();

		}
			
		else if (choix == 'b') {
			
			
			
			if (parcours != NULL) {
				parcours->diminuerNoeud(leGraph);
				delete parcours;
				
			}
			if (uneCommande != NULL) delete uneCommande;

			uneCommande = entrerUneCommande();
			try {
				parcours = new Parcours(leGraph, uneCommande, robot);
				parcours->diminuerNoeud(copieGraph);
			}
			catch (PasDeRobot e) {
				std::cout << e.what() << "\n";
			}

		}
		else if (choix == 'c') {
			if (uneCommande != NULL) {
				uneCommande->afficher();
				
			}
			else {
				std::cout << "Faites une commande d'abord. \n";
			}
		}
		else if (choix == 'd') {
			if (parcours != NULL && !parcours->getException() ) {
				parcours->afficher();
				
			}
			else {
				std::cout << "Faites une commande valide d'abord. \n";
			}
		}
		else if (choix == 'q') {
			
			if (parcours != NULL) delete parcours;
			if (uneCommande != NULL) delete uneCommande;
			
			quitter = true;
		}
		

	}//*/
	
	// Test de performance

	/*Commande* commande = new Commande(5, 0, 0);
	Parcours* parcours = NULL;
	try {
		parcours = new Parcours(leGraph, commande, robot);
	}
	catch (PasDeRobot e) {
		std::cout << e.what() << std::endl;
		parcours = NULL;
	}
	if (parcours != NULL && !parcours->getException()) {
		parcours->afficher();
	}
	
	
	delete commande;
	delete parcours;
	*/
	
	delete robotX;
	delete robotY;
	delete robotZ;
	delete leGraph;
	delete copieGraph;
	

	




	
	
	return 0;
}