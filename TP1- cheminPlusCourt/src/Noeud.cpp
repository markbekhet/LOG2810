#include "Noeud.h"
/*
	*dans le constructeur je ne suis pas certain seulemtn du placement de la virgule apres 
	* chaque nombre
*/
Noeud::Noeud(std::istream& fichier)
{
	char virgule;
	//int id;
	int nombreA;
	int nombreB;
	int nombreC;
	fichier >> id_;
	//id_ = id;
	fichier >> virgule;
	fichier >> nombreA;
	objetA_= new ObjetA(nombreA);
	fichier >> virgule;
	fichier >> nombreB;
	objetB_ = new ObjetB(nombreB);
	
	fichier >> virgule;
	fichier >> nombreC;
	objetC_ = new ObjetC(nombreC);


}

int Noeud::getLeNombredeA() const
{
	return objetA_->getNombre();
}

int Noeud::getLeNombredeB() const
{
	return objetB_->getNombre();
}

int Noeud::getLeNombredeC() const
{
	return objetC_->getNombre();
}

std::map<Noeud*, int> Noeud::getVoisins() const
{
	return lesVoisins_;
}

void Noeud::setVoisin(Noeud* unNoeud, int distance)
{
	std::pair<Noeud*, int>unePaire = std::make_pair(unNoeud, distance);
	lesVoisins_.insert(unePaire);

}

int Noeud::getId() const
{
	return id_;
}

bool appartient(std::vector<Noeud*>& precedent, Noeud* noeud) {
	for (auto node : precedent) {
		if (noeud->getId() == node->getId()) return true;
	}
	return false;
}
// Cela est la fonction recurive qui me permet d'avoir toutes les possibilites
void Noeud::insererChemin(std::map<std::vector<Noeud*>, int>& tousLesChemins, std::vector<Noeud*>& precedent, Noeud* but, int& distance)
{
	int copyDistance = distance;
	std::vector<Noeud*> copyPrecedent = precedent;
	for (auto unVoisin : lesVoisins_) {
		distance = copyDistance;
		precedent = copyPrecedent;
		if (!appartient(precedent, unVoisin.first)) {
			distance += unVoisin.second;
			precedent.push_back(unVoisin.first);
			if (unVoisin.first->getId() == but->getId()) {
				std::pair<std::vector<Noeud*>, int> pairAjoute = std::make_pair(precedent, distance);
				tousLesChemins.insert(pairAjoute);
			}

			else {
				unVoisin.first->insererChemin(tousLesChemins, precedent, but, distance);
			}
		}

	}
}
/*
	* Cette fonction va me donner le chemin la distance d<un noeud a son voisin selon le 
	* resultat final
 */


int Noeud::cheminVoisin(Noeud* but)
{
	int resultat= 0;
	for (auto voisin : lesVoisins_) {
		if (voisin.first->getId() == but->getId()) {
			resultat = voisin.second;
		}
	}
	return resultat;
}
/*
	* Cette fonction va me donner tous les chemins possibles vers un 
*/
std::pair<std::vector<Noeud*>, int> Noeud::LesCheminsSelonLaCommande(Noeud* but, Commande* commande)
{
	std::vector<Noeud*> precedent;
	precedent.push_back(this);
	int distance = 0;
	std::map<std::vector<Noeud*>, int> tousLesChemins;

	insererChemin(tousLesChemins, precedent, but, distance);


	return analyserSelonCommande(tousLesChemins,commande);
}

Noeud::~Noeud()
{
	delete objetA_;
	delete objetB_;
	delete objetC_;
}

std::pair<std::vector<Noeud*>, int> Noeud::analyserSelonCommande(std::map<std::vector<Noeud*>, int> map, Commande* commande)
{
	int distance = INT_MAX;
	std::pair<std::vector<Noeud*>, int> resultat;
	
	
	for (std::pair<std::vector<Noeud*>, int> possibilite : map) {
		int nombreA = 0;
		int nombreB = 0;
		int nombreC = 0;
		
		for (auto noeud : possibilite.first) {
			nombreA += noeud->getLeNombredeA();
			nombreB += noeud->getLeNombredeB();
			nombreC += noeud->getLeNombredeC();
			
		}
		
		
		
		
		if (nombreA >= commande->getNombreObjetA() && nombreB >= commande->getNombreObjetB() &&	nombreC >= commande->getNombreObjetC() && distance >= possibilite.second) {
			
			resultat = possibilite;
			distance = possibilite.second;
			
		}
		
	}
	return resultat;
}


std::ostream& operator<<(std::ostream& os, const Noeud* unNoeud)
{
	// TODO: insert return statement here
	os << "Noeud " << unNoeud->id_ << " nbObjetA: " <<
		unNoeud->getLeNombredeA() << " ,nbObjetB: " << unNoeud->getLeNombredeB() <<
		" nbObjetC: " << unNoeud->getLeNombredeC()<<" ses voisoins sont : ";

	for (auto pair : unNoeud->lesVoisins_) {
		os << "(" << pair.first->id_ << "," << pair.second << ") ";
	}
	os << std::endl;
	return os;

}
