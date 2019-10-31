#include "Parcours.h"
#include <algorithm>

Parcours::Parcours(Graph* graph, Commande* commande, std::vector<Robot*> listeRobot): graph_(graph),commande_(commande),listeRobot_(listeRobot)
{
	if (commande_->getMasseTotale() > std::max( listeRobot_[1]->getChargeMaximale(), listeRobot_[2]->getChargeMaximale())) {
		throw PasDeRobot();
	}
	else {
		
			choisirRobotSelonMasse();
		
		
	}
	
	
}

std::pair<std::vector<Noeud*>, int> Parcours::plusCourtChemin()
{
	Noeud noeudDepart = graph_->getNoeud[0];
	std::pair<Noeud*, int> noeudCourant(graph_->getNoeud[0], 0);
	std::pair<std::vector<Noeud*>, int>  noeudFixe;
	std::map<std::vector<Noeud*>, int>* cheminNonVisite;
	std::vector<Noeud*>* chemin;
	chemin->push_back(&noeudDepart);
	Commande verifCommande(0, 0, 0);
	bool cible = verifCommande.getNombreObjetA() <= commande_->getNombreObjetA() &&
		verifCommande.getNombreObjetB() <= commande_->getNombreObjetB() &&
		verifCommande.getNombreObjetC() <= commande_->getNombreObjetC();
	while (cible) {
		noeudCourant = prochainNoeud(noeudCourant, cheminNonVisite, chemin);
		
	}
	return noeudFixe;
}

std::pair<Noeud*, int> Parcours::prochainNoeud(std::pair<Noeud*, int> noeud,
	std::map<std::vector<Noeud*>, int>* cheminPossible,
	std::vector<Noeud*>* cheminActuelle) {
	int distanceMin = 0xFF;
	std::pair<Noeud*, int> prochainNoeud;

	for (auto voisin : noeud.first->getVoisins()) {
		int newDistance = noeud.second + voisin.second;
		std::pair<std::vector<Noeud*>, int> newChemin = {cheminActuelle->push_back(noeud.first), newDistance };
		cheminPossible->insert(newChemin);
	}
	return prochainNoeud;
}


std::pair< std::vector<Noeud*>, int> Parcours::findMin(std::map<std::vector<Noeud*>, int>* cheminPossible) {

	std::pair<std::vector<Noeud*>, int> cheminChoisi = { {},INT_MAX };
	for (auto chemin : *cheminPossible) {
		
		if (chemin.second < cheminChoisi.second) {
			cheminChoisi = chemin;
		}
	}
	return  cheminChoisi;
}



Robot* Parcours::choisirRobotSelonMasse()
{
	int masseTotale = commande_->getMasseTotale();
	std::vector<Robot*> temp;
	Robot* robotChoisi= NULL ;
	for (auto robot : listeRobot_) {
		if (robot->getChargeMaximale() >= masseTotale) {
			temp.push_back(robot);
		}
	}

	int tempsMax = INT_MAX;
	for (auto robot : temp) {
		try {
			int temps = calculerTemps(robot);
			if (tempsMax > temps) {
				tempsMax = temps;
				robotChoisi = robot;
			}
		}
		catch (PasDeChemin e) {
			std::cout << e.what() << "\n";
		}
		
		//std::cout << "Le temps de retour selon le robot est " << temps << " s" << std::endl;
	}
	

	return robotChoisi;
}

int Parcours::calculerTemps(Robot* robot)
{
	std::pair <std::vector<Noeud*>, int> chemin = plusCourtChemin();
	if (chemin.first.size() == 0) {
		throw PasDeChemin();
		
	}
	Commande* commandeCollectee = new Commande(0, 0, 0);
	Commande* commandeBase = new Commande(commande_->getNombreObjetA() , commande_->getNombreObjetB(),commande_->getNombreObjetC());
	robot->setConstanteK(commandeCollectee);
	int allerTemps = robot->getConstanteK() * chemin.second;
	int retourTemps = 0;
	for (int i = chemin.first.size() - 1; i > 0; i--) {
		std::vector<int> minimums = getMin(commandeBase, chemin.first[i]);
		commandeCollectee->augmenterNombreObjetA(minimums[0]);
		commandeCollectee->augmenterNombreObjetB(minimums[1]);
		commandeCollectee->augmenterNombreObjetC(minimums[2]);

		int distanceVoisin = chemin.first[i]->cheminVoisin(chemin.first[i-1]);
		robot->setConstanteK(commandeCollectee);
		retourTemps += robot->getConstanteK() * distanceVoisin;
		
	}
	

	int tempsFinal = allerTemps + retourTemps;

	return tempsFinal;
}

std::vector<int> Parcours::getMin(Commande* commande, Noeud* noeud)
{
	int minA = std::min(commande->getNombreObjetA(), noeud->getLeNombredeA());
	int minB = std::min(commande->getNombreObjetB(), noeud->getLeNombredeB());
	int minC = std::min(commande->getNombreObjetC(), noeud->getLeNombredeC());
	commande->diminuerNombreObjetA(minA);
	commande->diminuerNombreObjetB(minB);
	commande->diminuerNombreObjetC(minC);
	std::vector<int> minimes;
	minimes.push_back(minA);
	minimes.push_back(minB);
	minimes.push_back(minC);
	return minimes;
}

void Parcours::afficher()
{
	std::cout << this << std::endl;
}

std::ostream& operator<<(std::ostream& os, Parcours* parcours)
{
	Commande* copie = new Commande(parcours->commande_->getNombreObjetA(),parcours->commande_->getNombreObjetB(),parcours->commande_->getNombreObjetC());
	os << "Le type de robot choisir est: ";
	Robot* robotChoisi = parcours->choisirRobotSelonMasse();
	/*if (dynamic_cast<RobotY*> (robotChoisi) ) {
		os << dynamic_cast<RobotY*> (robotChoisi) << "\n";
	}
	else if (dynamic_cast<RobotZ*>(robotChoisi)) {
		os << dynamic_cast<RobotZ*>(robotChoisi) << "\n";
	}
	else if (dynamic_cast<RobotX*>(robotChoisi)) {
		os << dynamic_cast<RobotX*>(robotChoisi) << "\n";
	}*/
	 robotChoisi->afficher();

		os<< "Il passera par les noeuds suivants: " ;
		
		for (int i = parcours->plusCourtChemin().first.size() - 1; i >= 0;--i) {
			auto noeud =  parcours->plusCourtChemin().first[i];
			std::vector<int> minimes = parcours->getMin(copie, noeud);
			os << "Noeud " << noeud->getId() << " collecte " << minimes[0] << " objets A, "
				<< minimes[1] << " objets B, " 
				<< minimes[2] << " objets C." << "\n";
		}
		os << "Le robot a collecte la commande en " << parcours->calculerTemps(parcours->choisirRobotSelonMasse()) << " secondes." << "\n";
		return os;
}
