#pragma once
#include "Robot.h"
#include "Graph.h"
#include "Commande.h"
class Parcours{
public:
	Parcours(Graph* graph , Commande* commande, std::vector<Robot*> listeRobot);
	std::pair<std::vector<Noeud*>, int> plusCourtChemin();
	Robot* choisirRobotSelonMasse();

	int calculerTemps(Robot* robot);
	std::vector<int> getMin(Commande* commande, Noeud* noeud);
	void afficher();
	friend std::ostream& operator<<(std::ostream& os, Parcours* parcours);

private:
	Graph* graph_;
	Commande* commande_;
	std::vector<Robot*> listeRobot_;

};