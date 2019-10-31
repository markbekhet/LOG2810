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
	int getLeNombredeA() const;
	int getLeNombredeB() const;
	int getLeNombredeC() const;
	std::map<Noeud*,int> getVoisins() const;
	void setVoisin(Noeud* unNoeud, int distance);
	int getId() const;
	void insererChemin(std::pair<std::vector<Noeud*>, int>& tousLesChemins, std::vector<Noeud*>& previous, /*Noeud* but,*/ int& distancePrecedente, const Commande* commandeVoulue, Commande* commandeCollectee);
	int cheminVoisin( Noeud* but);
	std::pair<std::vector<Noeud*>, int> LesCheminsSelonLaCommande(/*Noeud* but,*/  Commande* commande);
	void diminuerNombreObjetA(int facteur);
	void diminuerNombreObjetB(int facteur);
	void diminuerNombreObjetC(int facteur);
	~Noeud();
	friend std::ostream& operator<<(std::ostream& os, const Noeud* unNoeud);
private:
	std::map<Noeud*, int> lesVoisins_;
	std::pair<std::vector<Noeud*>, int> analyserSelonCommande(std::map<std::vector<Noeud*>,int> map, Commande* commande);
	int id_;
	ObjetA* objetA_;
	ObjetB* objetB_;
	ObjetC* objetC_;
	



};
