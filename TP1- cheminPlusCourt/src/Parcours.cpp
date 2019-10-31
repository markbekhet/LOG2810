#include "Parcours.h"
#include <algorithm>

Parcours::Parcours(Graph* graph, Commande* commande, std::vector<Robot*> listeRobot): graph_(graph),commande_(commande),listeRobot_(listeRobot)
{
	exception = false;
	if (commande_->getMasseTotale() > std::max( listeRobot_[1]->getChargeMaximale(), listeRobot_[2]->getChargeMaximale())) {
		throw PasDeRobot();
	}
	else {
		
			choisirRobotSelonMasse();
		
		
	}
	
	
}

std::pair<std::vector<Noeud*>, int> Parcours::plusCourtChemin()
{
	std::pair<std::vector<Noeud*>, int> resultat;
	int distance = INT_MAX;
	Noeud* noeudZero = graph_->getNoeud(0);
	Commande* copieCommande = new Commande(commande_);
	
	/*for (auto noeud : graph_->getLesNoeuds()) {
		if (noeudZero->getId() != noeud->getId()) {
			
			std::pair<std::vector<Noeud*>, int> temp = noeudZero->LesCheminsSelonLaCommande(noeud, copieCommande);
			
			if (distance >= temp.second) {
				resultat = temp;
				distance = temp.second;
			}
		}
		
	}*/
	resultat= noeudZero->LesCheminsSelonLaCommande(/*noeud,*/ copieCommande);
	delete copieCommande;
	return resultat;
}

Robot* Parcours::choisirRobotSelonMasse()
{
	int masseTotale = commande_->getMasseTotale();
	std::vector<Robot*> temp = {};
	
	for (auto robot : listeRobot_) {
		if (robot->getChargeMaximale() >= masseTotale) {
			temp.push_back(robot);
		}
	}

	int tempsMax = INT_MAX;
	Robot* robotChoisi = NULL ;
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
		exception = true;
		throw PasDeChemin();
		
		
	}
	Commande* commandeCollectee = new Commande(0, 0, 0);
	Commande* commandeBase = new Commande(commande_);
	// En allant le robot ne collecte pas d'objet
	robot->setConstanteK(commandeCollectee);
	int allerTemps = robot->getConstanteK() * chemin.second;
	int retourTemps = 0;
	for (int i = chemin.first.size() - 1; i > 0; --i) {
		std::vector<int> minimums = getMin(commandeBase, chemin.first[i]);
		commandeCollectee->augmenterNombreObjetA(minimums[0]);
		commandeCollectee->augmenterNombreObjetB(minimums[1]);
		commandeCollectee->augmenterNombreObjetC(minimums[2]);

		int distanceVoisin = chemin.first[i]->cheminVoisin(chemin.first[i-1]);
		robot->setConstanteK(commandeCollectee);
		retourTemps += robot->getConstanteK() * distanceVoisin;
		
	}
	
	delete commandeCollectee;
	delete commandeBase;
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

void Parcours::diminuerNoeud()
{
	std::pair<std::vector<Noeud*>, int> chemin = plusCourtChemin();
	for (auto noeud : chemin.first) {
		std::vector<int> minimums = getMin(commande_, noeud);
		graph_->getNoeud(noeud->getId())->diminuerNombreObjetA(minimums[0]);
		graph_->getNoeud(noeud->getId())->diminuerNombreObjetB(minimums[1]);
		graph_->getNoeud(noeud->getId())->diminuerNombreObjetC(minimums[2]);
	}
}

bool Parcours::getException() const
{
	return exception;
}

std::ostream& operator<<(std::ostream& os, Parcours* parcours)
{
	Commande* copie = new Commande(parcours->commande_);
	
	os << "Le type de robot choisir est: ";
	Robot* robotChoisi = parcours->choisirRobotSelonMasse();
	
	 robotChoisi->afficher();
	 

	os<< "Il passera par les noeuds suivants: " ;
	std::pair<std::vector<Noeud*>, int> chemin = parcours->plusCourtChemin();
		
	for (int i = chemin.first.size()-1 ; i >= 0;--i) {
		auto noeud =  chemin.first[i];
		std::vector<int> minimes = parcours->getMin(copie, noeud);
		os << "Noeud " << noeud->getId() << " collecte " << minimes[0] << " objets A, "
			<< minimes[1] << " objets B, " 
			<< minimes[2] << " objets C." << "\n";
	}
	//std::cout << "La commande avant d'appeller le temps du parcours est : " << parcours->commande_;
	os << "Le robot a collecte la commande en " << parcours->calculerTemps(parcours->choisirRobotSelonMasse()) << " secondes." << "\n";
	delete copie;
	return os;
}
