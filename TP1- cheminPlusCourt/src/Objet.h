/*
	* Noms: Cécile Hornecker, Marjorie Pomerleau , Mark Bekhet
	* Matricules: 1783304_1959041_1949264
*/
#pragma once
class Objet {
public:
	Objet(int nombre, int masse);
	int getNombre();
	int getMasse();
	void diminuerNombre(int facteur);
	void augmenterNombre(int facteur);
protected:
	int nombre_;
	int masse_;
};
