#include "Noeud.h"
/*
	*dans le constructeur je ne suis pas certain seulemtn du placement de la virgule apres 
	* chaque nombre
*/
Noeud::Noeud(std::istream& fichier)
{
	char virgule;
	int id;
	int nombreA;
	int nombreB;
	int nombreC;
	fichier >> id;
	id_ = id;
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

Noeud::~Noeud()
{
	delete objetA_;
	delete objetB_;
	delete objetC_;
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
