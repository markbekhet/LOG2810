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
	
	
	resultat= noeudZero->LesCheminsSelonLaCommande(/*noeud,*/ copieCommande);
	delete copieCommande;
	return resultat;
}

std::pair<Robot*,bool> Parcours::choisirRobotSelonMasse()
{
	int masseTotale = commande_->getMasseTotale();
	std::vector<Robot*> temp = {};
	
	for (auto robot : listeRobot_) {
		if (robot->getChargeMaximale() >= masseTotale) {
			temp.push_back(robot);
		}
	}

	int tempsMax = INT_MAX;
	std::pair<Robot*,bool> robotChoisi ;
	for (auto robot : temp) {
		try {
			std::pair<double,bool> temps = calculerTemps(robot);
			
			if (tempsMax > temps.first) {
				tempsMax = temps.first;
				robotChoisi = { robot,temps.second };
			}
		}
		catch (PasDeChemin e) {
			std::cout << e.what() << "\n";
		}
		
		
	}
	
	
	
	

	return robotChoisi;
}


//ca c'est un test
// retourne un booleen a cote du temps qui sert a dire s'il fait la commande en allant ou en retournant
// s'il decide de faire la commande en allant il retourne false
// s'il decide de faire la commande en retournant il retourne true
std::pair<double, bool> Parcours::calculerTemps(Robot* robot)
{
	//std::cout << "Pour le "; robot->afficher();
	std::pair <std::vector<Noeud*>, int> chemin = plusCourtChemin();
	
	
	
	if (chemin.first.size() == 0) {
		exception = true;
		throw PasDeChemin();
		
		
	}
	Noeud* noeudZero = graph_->getNoeud(0);
	std::pair<std::vector<Noeud*>, int> cheminPlusCourt = noeudZero->LesCheminsSelonLeNoeudFinal(chemin.first[chemin.first.size() - 1]);
	// 1 er option faire la commande en retournant
	Commande* commandeCollectee = new Commande(0, 0, 0);
	Commande* commandeBase = new Commande(commande_);
	// En allant le robot ne collecte pas d'objet
	robot->setConstanteK(commandeCollectee);
	double allerTemps = robot->getConstanteK() * cheminPlusCourt.second;
	double retourTemps = 0;
	for (int i = chemin.first.size() - 1; i > 0; --i) {
		int constantKAvantLeNoeud = robot->getConstanteK();
		std::vector<int> minimums = getMin(commandeBase, chemin.first[i]);
		commandeCollectee->augmenterNombreObjetA(minimums[0]);
		commandeCollectee->augmenterNombreObjetB(minimums[1]);
		commandeCollectee->augmenterNombreObjetC(minimums[2]);

		int distanceVoisin = chemin.first[i]->cheminVoisin(chemin.first[i-1]);
		robot->setConstanteK(commandeCollectee);
		int constantKApresLeNoeud = robot->getConstanteK();
		if (constantKAvantLeNoeud != constantKApresLeNoeud) {
			retourTemps += (robot->getConstanteK() * distanceVoisin) + ((10*minimums[0])+(10*minimums[1])+(10*minimums[2]));
		}
		else {
			retourTemps += robot->getConstanteK() * distanceVoisin;
		};
		//retourTemps += robot->getConstanteK() * distanceVoisin;
		
	}
	
	
	delete commandeCollectee;
	delete commandeBase;
	double tempsFinalOptionRetournant= allerTemps + retourTemps;
	//std::cout <<"Le temps de l'option de collecter en retournant est "<< tempsFinalOptionRetournant << "\n";


	// 2 eme option faire la commande en allant 
	Commande* commandeCollecteeOption2 = new Commande(0, 0, 0);
	Commande* commandeBaseOption2 = new Commande(commande_);
	
	
	double allerTempsOption2 = 0;
	
	for (int i = 0; i < chemin.first.size() ; ++i) {
		int constantKAvantLeNoeud = robot->getConstanteK();
		std::vector<int> minimums = getMin(commandeBaseOption2, chemin.first[i]);
		commandeCollecteeOption2->augmenterNombreObjetA(minimums[0]);
		commandeCollecteeOption2->augmenterNombreObjetB(minimums[1]);
		commandeCollecteeOption2->augmenterNombreObjetC(minimums[2]);
		int distanceVoisin = 0;
		if (i != chemin.first.size() - 1) {
			distanceVoisin = chemin.first[i]->cheminVoisin(chemin.first[i + 1]);
		}
		
		
		robot->setConstanteK(commandeCollecteeOption2);
		int constantKApresLeNoeud = robot->getConstanteK();
		if (constantKAvantLeNoeud!=constantKApresLeNoeud) {
			allerTempsOption2 += (robot->getConstanteK() * distanceVoisin) + ((10 * minimums[0]) + (10 * minimums[1]) + (10 * minimums[2]));
		}
		else {
			allerTempsOption2 += robot->getConstanteK() * distanceVoisin;
		}
		

	}
	robot->setConstanteK(commandeCollecteeOption2);
	double retourTempsOption2 = robot->getConstanteK() * cheminPlusCourt.second;
	delete commandeCollecteeOption2;
	delete commandeBaseOption2;
	double tempsFinalOptionAllant = allerTempsOption2 + retourTempsOption2;
	//std::cout <<"Le temps de l'option de collecter en allant est "<< tempsFinalOptionAllant << "\n";

	if (tempsFinalOptionAllant <= tempsFinalOptionRetournant) {
		
		return std::pair<double, bool>(tempsFinalOptionAllant, false);
	}
	else {
		
		return std::pair<double,bool>(tempsFinalOptionRetournant,true);
	}


	
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

void Parcours::diminuerNoeud(Graph* unGraph)
{
	std::pair<std::vector<Noeud*>, int> chemin = plusCourtChemin();
	Commande* copieCommande  = new Commande(commande_);
	for (auto noeud : chemin.first) {
		std::vector<int> minimums = getMin(copieCommande, noeud);
		unGraph->getNoeud(noeud->getId())->diminuerNombreObjetA(minimums[0]);
		unGraph->getNoeud(noeud->getId())->diminuerNombreObjetB(minimums[1]);
		unGraph->getNoeud(noeud->getId())->diminuerNombreObjetC(minimums[2]);
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
	std::pair<Robot*,bool> robotChoisi = parcours->choisirRobotSelonMasse();
	
	 robotChoisi.first->afficher();
	 

	
	std::pair<std::vector<Noeud*>, int> chemin = parcours->plusCourtChemin();
	Noeud* noeudZero = parcours->graph_->getNoeud(0);
	std::pair<std::vector<Noeud*>, int> cheminPlusCourt = noeudZero->LesCheminsSelonLeNoeudFinal(chemin.first[chemin.first.size() - 1]);
	if (robotChoisi.second) {
		os << "Au debut le robot passera par les noeud suivante sans rien collecter ";
		for (auto noeud : cheminPlusCourt.first) {
			os << noeud->getId() << " , ";
		}
		os << ". Ensuite en revenant , il collectera la commande \n";

		for (int i = chemin.first.size() - 1; i >= 0; --i) {
			auto noeud = chemin.first[i];
			std::vector<int> minimes = parcours->getMin(copie, noeud);
			os << "Noeud " << noeud->getId() << " collecte " << minimes[0] << " objets A, "
				<< minimes[1] << " objets B, "
				<< minimes[2] << " objets C." << "\n";
		}
	}

	else {
		os << "Au debut le robot passera par les noeud suivante en collectant la commande "; 
		for (int i =0; i < chemin.first.size() ; ++i) {
			auto noeud = chemin.first[i];
			std::vector<int> minimes = parcours->getMin(copie, noeud);
			os << "Noeud " << noeud->getId() << " collecte " << minimes[0] << " objets A, "
				<< minimes[1] << " objets B, "
				<< minimes[2] << " objets C." << "\n";
		}

		os << " Ensuite en revenant , il passera par les noeud suivante sans rien collecter \n";
		for (int i = cheminPlusCourt.first.size()-1; i >= 0; --i) {
			auto noeud = cheminPlusCourt.first[i];
			os << noeud->getId() << " , ";
		}
		os << "\n";
		

	}
	
	
	os << "Le robot a collecte la commande en " << parcours->calculerTemps(parcours->choisirRobotSelonMasse().first).first << " secondes." << "\n";
	delete copie;
	return os;
}
