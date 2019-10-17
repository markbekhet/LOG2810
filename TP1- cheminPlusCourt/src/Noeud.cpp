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


std::pair<std::vector<Noeud*>,int> Noeud::cheminMin( std::vector<Noeud*>& precedent, Noeud* but, int& distance)
{
	std::map<std::vector<Noeud*> , int> tousLesChemins;
	
	insererChemin(tousLesChemins, precedent, but, distance);
	//s'il arrive a terminer cette boucle
	std::cout << "La taille de la map est " << tousLesChemins.size() << std::endl;
	
	return PlusCourtChemin(tousLesChemins);
}

Noeud::~Noeud()
{
	delete objetA_;
	delete objetB_;
	delete objetC_;
}

std::pair<std::vector<Noeud*>, int> Noeud::PlusCourtChemin(std::map<std::vector<Noeud*>, int>& map)
{
	int distance = 0;
	int nombre = 0;
	std::vector<Noeud*> listVoulu;
	for (auto element : map) {
		//std::cout << element.second << std::endl;
		if (nombre == 0) {
			distance = element.second;
			listVoulu = element.first;
		}
		else if (distance > element.second) {
			distance = element.second;
			listVoulu = element.first;
		}
		++nombre;
	}
	
	return std::make_pair(listVoulu, distance);
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
