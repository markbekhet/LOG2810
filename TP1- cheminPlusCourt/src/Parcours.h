/*
	* Noms: Cécile Hornecker, Marjorie Pomerleau , Mark Bekhet
	* Matricules: 1783304_1959041_1949264
*/
#pragma once
#include "Robot.h"
#include "Graph.h"
#include "Commande.h"
#include "RobotX.h"
#include "RobotY.h"
#include "RobotZ.h"
class PasDeRobot : public std::exception {
public:
	virtual const char* what() {
		return "Il n'existe pas de robots capable de faire cette commande";
	}
};
class PasDeChemin : public std::exception {
public:
	virtual const char* what() {
		return "Il n'y a pas de chemin possible";
	}
};
class Parcours{
public:
	Parcours(Graph* graph , Commande* commande, std::vector<Robot*> listeRobot);
	std::pair<std::vector<Noeud*>, int> plusCourtChemin();
	std::pair<Robot*,bool> choisirRobotSelonMasse();

	std::pair<double, bool> calculerTemps(Robot* robot);
	std::vector<int> getMin(Commande* commande, Noeud* noeud);
	void afficher();
	void diminuerNoeud(Graph* ungraph);
	bool getException() const;
	void resetException();

	friend std::ostream& operator<<(std::ostream& os, Parcours* parcours);

private:
	Graph* graph_;
	Commande* commande_;
	
	bool exception;
	std::vector<Robot*> listeRobot_;

};
