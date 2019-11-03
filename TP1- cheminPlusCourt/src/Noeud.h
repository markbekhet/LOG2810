#pragma once
#include "ObjetA.h"
#include "ObjetB.h"
#include "ObjetC.h"
#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <vector>
#include "Commande.h"
class Noeud {
public:
	Noeud(std::istream& fichier);
	Noeud(Noeud* noeud);
	int getLeNombredeA() const;
	int getLeNombredeB() const;
	int getLeNombredeC() const;
	std::map<Noeud*,int> getVoisins() ;
	void setVoisin(Noeud* unNoeud, int distance);
	int getId() const;

	int cheminVoisin( Noeud* but);
	//Ces deux fonctions sont pour la commande Dijkstra
	
	
	// Ces deux fonctions sont pour le noeud final Dijkstra
	void insererChemin(std::pair<std::vector<Noeud*>, int>& tousLesChemins, std::vector<Noeud*>& previous, int& distancePrecedente, const Noeud* noeudFinal);
	std::pair<std::vector<Noeud*>, int> LesCheminsSelonLeNoeudFinal( const Noeud* noeudFinal);
	//fonctions globale
	void diminuerNombreObjetA(int facteur);
	void diminuerNombreObjetB(int facteur);
	void diminuerNombreObjetC(int facteur);
	~Noeud();
	bool appartient(std::vector<Noeud*>& precedent, Noeud* noeud);
	friend std::ostream& operator<<(std::ostream& os, const Noeud* unNoeud);
	Noeud* operator = (Noeud* noeud);
private:
	std::map<Noeud*, int> lesVoisins_;
	std::pair<std::vector<Noeud*>, int> analyserSelonCommande(std::map<std::vector<Noeud*>,int> map, Commande* commande);
	int id_;
	ObjetA* objetA_;
	ObjetB* objetB_;
	ObjetC* objetC_;
	



};
