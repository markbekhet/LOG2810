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
// Je veux recuperer la distance minimale que je veux directement.

// Il reste de s'assurer de cette fonction le reste se passe bien
void Noeud::insererChemin(std::pair<std::vector<Noeud*>, int>& tousLesChemins, std::vector<Noeud*>& precedent,/* Noeud* but,*/ int& distancePrecedente ,const Commande* commandeVoulue, Commande* commandeCollectee)
{
	// Je fais une copie de la distance actuelle et des noeud precedent ainsi que la commande collectee pour savoir reutilisee la meme distance en faisant la recursivite
	int copyDistance = distancePrecedente;
	std::vector<Noeud*> copyPrecedent = precedent;
	Commande* copyCommandeCollectee = new Commande(commandeCollectee);
	for (auto unVoisin : lesVoisins_) {
		// Je veux garder une distance qui sera un repere en cas que la commande est realise par le voisin sinon on continue
		//commande potentielle accumulee et commande voulue sont deux parametres necessaires
		
		
		distancePrecedente = copyDistance;
		precedent = copyPrecedent;
		commandeCollectee = new Commande(copyCommandeCollectee);
		if (!appartient(precedent, unVoisin.first)) {
			//Je recupere les informations precedentes
			
			//std::cout <<unVoisin.first->getId()<<" Le pointeur ici est : " <<&commandeCollectee << std::endl;
			//J'additionne les distances qinsi que je mets le voisin en precedent et j'a
			distancePrecedente += unVoisin.second;
			precedent.push_back(unVoisin.first);

			//Augmenter les donnees de la commande collectee
			commandeCollectee->augmenterNombreObjetA(unVoisin.first->getLeNombredeA());
			commandeCollectee->augmenterNombreObjetB(unVoisin.first->getLeNombredeB());
			commandeCollectee->augmenterNombreObjetC(unVoisin.first->getLeNombredeC());
			
			
			if (tousLesChemins.second >= distancePrecedente) {
				if (/*unVoisin.first->getId() == but->getId() &&*/ commandeCollectee->plusGrandOuEgal(commandeVoulue) /*&& tousLesChemins.second >= distancePrecedente*/) {
					tousLesChemins = std::make_pair(precedent, distancePrecedente);

				}

				else {
					unVoisin.first->insererChemin(tousLesChemins, precedent, /*but,*/ distancePrecedente, commandeVoulue, commandeCollectee);
				}
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
std::pair<std::vector<Noeud*>, int> Noeud::LesCheminsSelonLaCommande(/*Noeud* but,*/ Commande* commande)
{
	std::vector<Noeud*> precedent;
	precedent.push_back(this);
	int distance = 0;
	Commande* commandeCollectee = new Commande();
	std::pair<std::vector<Noeud*>, int> tousLesChemins = { {},INT_MAX };

	insererChemin(tousLesChemins, precedent, /*but,*/ distance,commande, commandeCollectee);


	return tousLesChemins;
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
