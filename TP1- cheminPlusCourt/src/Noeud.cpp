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

Noeud::Noeud(Noeud* noeud)
{
	id_ = noeud->getId();
	objetA_ = new ObjetA(noeud->getLeNombredeA());
	objetB_ = new ObjetB(noeud->getLeNombredeB());
	objetC_ = new ObjetC(noeud->getLeNombredeC());
	

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

std::map<Noeud*, int> Noeud::getVoisins() 
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

bool Noeud::appartient(std::vector<Noeud*>& precedent, Noeud* noeud) {
	for (auto node : precedent) {
		if (noeud->getId() == node->getId()) return true;
	}
	return false;
}
// Cela est la fonction recurive qui me permet d'avoir toutes les possibilites
// Je veux recuperer la distance minimale que je veux directement.

// Il reste de s'assurer de cette fonction le reste se passe bien

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


void Noeud::insererChemin(std::pair<std::vector<Noeud*>, int>& tousLesChemins, std::vector<Noeud*>& previous, int& distancePrecedente, const Noeud* noeudFinal)
{
	if (noeudFinal->getId() == id_) { tousLesChemins = std::make_pair(previous, 0); }
	else {
		// Je fais une copie de la distance actuelle et des noeud precedent ainsi que la commande collectee pour savoir reutilisee la meme distance en faisant la recursivite
		int copyDistance = distancePrecedente;
		std::vector<Noeud*> copyPrecedent = previous;
		


		for (auto unVoisin : lesVoisins_) {
			// Je veux garder une distance qui sera un repere en cas que la commande est realise par le voisin sinon on continue
			//commande potentielle accumulee et commande voulue sont deux parametres necessaires


			distancePrecedente = copyDistance;
			previous = copyPrecedent;
			

			if (!appartient(previous, unVoisin.first)) {
				//Je recupere les informations precedentes

				//std::cout <<unVoisin.first->getId()<<" Le pointeur ici est : " <<&commandeCollectee << std::endl;
				//J'additionne les distances qinsi que je mets le voisin en precedent et j'a
				distancePrecedente += unVoisin.second;
				previous.push_back(unVoisin.first);

				
				


				if (tousLesChemins.second >= distancePrecedente) {
					if (unVoisin.first->getId() == noeudFinal->getId() ) {
						tousLesChemins = std::make_pair(previous, distancePrecedente);

					}

					else {
						unVoisin.first->insererChemin(tousLesChemins, previous, distancePrecedente, noeudFinal);
					}
				}


			}


		}
		
	}
}

std::pair<std::vector<Noeud*>, int> Noeud::LesCheminsSelonLeNoeudFinal(const Noeud* noeudFinal)
{
	std::vector<Noeud*> precedent;
	precedent.push_back(this);
	int distance = 0;
	
	std::pair<std::vector<Noeud*>, int> tousLesChemins = { {},INT_MAX };

	insererChemin(tousLesChemins, precedent,  distance, noeudFinal);


	return tousLesChemins;
	
}

void Noeud::diminuerNombreObjetA(int facteur)
{
	objetA_->diminuerNombre(facteur);
}

void Noeud::diminuerNombreObjetB(int facteur)
{
	objetB_->diminuerNombre(facteur);
}

void Noeud::diminuerNombreObjetC(int facteur)
{
	objetC_->diminuerNombre(facteur);
}

Noeud::~Noeud()
{
	delete objetA_;
	delete objetB_;
	delete objetC_;
}

Noeud* Noeud::operator=(Noeud* noeud)
{
	Noeud* ret = new Noeud(noeud);
	for (auto voisin : noeud->getVoisins()) {
		ret->setVoisin(voisin.first, voisin.second);
	}
	return ret;
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
