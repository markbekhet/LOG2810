#include "Parcours.h"
#include <algorithm>

Parcours::Parcours(Graph* graph, Commande* commande, std::vector<Robot*> listeRobot): graph_(graph),commande_(commande),listeRobot_(listeRobot)
{
	choisirRobotSelonMasse();
}

std::pair<std::vector<Noeud*>, int> Parcours::plusCourtChemin()
{
	std::pair<std::vector<Noeud*>, int> resultat;
	int distance = (2 ^ 31) - 1;
	Noeud* noeudZero = graph_->getNoeud(0);
	int n = 0;
	for (auto noeud : graph_->getLesNoeuds()) {
		if (noeudZero->getId() != noeud->getId()) {
			std::pair<std::vector<Noeud*>, int> temp = noeudZero->LesCheminsSelonLaCommande(noeud, commande_);
			if (temp.second < distance) {
				resultat = temp;
			}
		}
		++n;
	}
	return resultat;
}

Robot* Parcours::choisirRobotSelonMasse()
{
	int masseTotale = commande_->getMasseTotale();
	std::vector<Robot*> temp;
	Robot* robotChoisi = NULL;
	for (auto robot : listeRobot_) {
		if (robot->getChargeMaximale() >= masseTotale) {
			temp.push_back(robot);
		}
	}

	int tempsMax = (2 ^ 31) - 1;
	for (auto robot : temp) {
		int temps = calculerTemps(robot);
		if (tempsMax >= temps) {
			tempsMax = temps;
			robotChoisi = robot;
		}
	}

	return robotChoisi;
}

int Parcours::calculerTemps(Robot* robot)
{
	std::pair <std::vector<Noeud*>, int> chemin = plusCourtChemin();
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
	os << "Le type de robot choisir est: ";
	Robot* robotChoisi = parcours->choisirRobotSelonMasse();
	if (dynamic_cast<RobotY*> (robotChoisi) ) {
		os << dynamic_cast<RobotY*> (robotChoisi) << "\n";
	}
	else if (dynamic_cast<RobotZ*>(robotChoisi)) {
		os << dynamic_cast<RobotZ*>(robotChoisi) << "\n";
	}
	else if (dynamic_cast<RobotX*>(robotChoisi)) {
		os << dynamic_cast<RobotX*>(robotChoisi) << "\n";
	}

		os<< "Il passera par les noeuds suivants: " ;
		Commande* copie = parcours->commande_;
		for (auto noeud : parcours->plusCourtChemin().first) {
			os << "Noeud " << noeud->getId() << " collecte " << parcours->getMin(copie, noeud)[0] << " objets A, "
				<< parcours->getMin(copie, noeud)[1] << " objets B, " 
				<< parcours->getMin(copie, noeud)[2] << " objets C." << "\n";
		}
		os << "Le robot a collecte la commande en " << parcours->calculerTemps(parcours->choisirRobotSelonMasse()) << " secondes." << "\n";
		return os;
}